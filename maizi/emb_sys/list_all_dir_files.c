#include <dirent.h>
#include <stdio.h>


int main(int argc, const char *argv[]) {
    if (argc != 2) {
        printf("argument error!\n");
        return -1;
    }

    DIR *srcdir = NULL;
    srcdir = opendir(argv[1]);
    if (srcdir == NULL) {
        printf("open dir failed!\n");
        return -1;
    }

    struct dirent *dent;

    // subdirs saved as a linked list
    while((dent = readdir(srcdir))!= NULL){
        printf("%s\n", dent->d_name);
    }
    
    closedir(srcdir);
    return 0;
}