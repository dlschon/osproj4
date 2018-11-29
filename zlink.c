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
  if(argc == 3) {
    // Open the virtual disk
    vdisk_disk_open(disk_name);

    // Make the specified directory
    int ret = oufs_link(strdup(cwd), strdup(argv[1]), strdup(argv[2]));

    if(ret != 0) {
      fprintf(stderr, "Error (%d)\n", ret);
    }

    // Clean up
    vdisk_disk_close();
    
  }else{
    // Wrong number of parameters
    fprintf(stderr, "Usage: zlink <src> <dst>\n");
  }

}
