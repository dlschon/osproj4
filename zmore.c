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
    OUFILE *fp = oufs_fopen(strdup(cwd), strdup(argv[1]), "r");

    // Get file size
    INODE inode;
    oufs_read_inode_by_reference(fp->inode_reference, &inode);
    int len = inode.size;
    unsigned char buf[len];
    
    // Read the file
    int ret = oufs_fread(fp, buf, len);

    if (ret != -1) 
    {
      // Print it to stdout
      printf("%.*s", len, buf);
    }
    else
    {
      fprintf(stderr, "Error: (%d)\n", ret);
    }
    
    // Close the file
    oufs_fclose(fp);

    // Clean up
    vdisk_disk_close();
    
  }else{
    // Wrong number of parameters
    fprintf(stderr, "Usage: zmore <filename>\n");
  }

}
