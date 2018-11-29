/**
Make a directory in the OU File System.

CS3113

*/

#include <stdio.h>
#include <string.h>
#include "oufs_lib.h"

int main(int argc, char** argv) {
  // Fetch the key environment vars
  char cwd[MAX_PATH_LENGTH];
  char disk_name[MAX_PATH_LENGTH];
  oufs_get_environment(cwd, disk_name);

  // Check arguments
  if(argc == 2) {
    // Open the virtual disk
    vdisk_disk_open(disk_name);

    // Open file for reading
    OUFILE *fp = oufs_fopen(strdup(cwd), strdup(argv[1]), "w");

    // Read byte by byte from stdin
    unsigned char ch;
    while (read(STDIN_FILENO, &ch, 1) > 0)
    {
      // Attempt to write the byte to the file
      int wrote = oufs_fwrite(fp, &ch, 1);

      // Break the loop if we failed to write the byte. This means the file is full
      if (wrote == 0)
        break;
    }

    
    // Close the file
    oufs_fclose(fp);

    // Clean up
    vdisk_disk_close();
    
  }else{
    // Wrong number of parameters
    fprintf(stderr, "Usage: zcreate <filename>\n");
  }

}
