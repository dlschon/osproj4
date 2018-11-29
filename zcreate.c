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

    // Read STDIN into buffer
    char * buf;
    int len = 0;
    char ch;

    // Read byte by byte
    while (read(STDIN_FILENO, &ch, 1) > 0)
    {
      buf[len] = ch;
      len +=1;
    }
    // Null terminate buf
    buf[len] = '\0';

    printf(buf);

    if(ret != 0) {
      fprintf(stderr, "Error (%d)\n", ret);
    }

    // Clean up
    vdisk_disk_close();
    
  }else{
    // Wrong number of parameters
    fprintf(stderr, "Usage: zcreate <filename>\n");
  }

}
