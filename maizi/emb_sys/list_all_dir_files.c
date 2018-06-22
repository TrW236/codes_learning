#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>


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
    } else {
        printf("open dir: %s\n", argv[1]);
    }

    int len_input = strlen(argv[1]);
    
    char srcdir_path[len_input + 1];
    srcdir_path[0] = 0;  // init
    //srcdir_path = "";
    strcat(srcdir_path, argv[1]);
    strcat(srcdir_path, "/");
    //printf("open dir: %s\n", srcdir_path);
    //strcpy(srcdir_path, argv[1]);
    //srcdir_path[len_input - 1] = '/';


    struct dirent *dent;
    struct stat fStat;

    // subdirs saved as a linked list
    while((dent = readdir(srcdir))!= NULL){
        int len_f = strlen(dent->d_name);
        int len_total = len_f + strlen(srcdir_path);
        char fpath[len_total];
        fpath[0] = 0;
        strcat(fpath, srcdir_path);
        strcat(fpath, dent->d_name);
        // printf("%s\n", fpath);
        if(stat(fpath, &fStat) < 0) return 1;
        char d_type[16];
        d_type[0] = 0;
        
        if (dent->d_type == 4) {
            strcat(d_type, "directory");
        } else {
            strcat(d_type, "file");
        }

        printf("Type: %s; ", d_type);

        printf("Permission: ");
        printf( (fStat.st_mode & S_IRUSR) ? "r" : "-");
        printf( (fStat.st_mode & S_IWUSR) ? "w" : "-");
        printf( (fStat.st_mode & S_IXUSR) ? "x" : "-");
        printf( (fStat.st_mode & S_IRGRP) ? "r" : "-");
        printf( (fStat.st_mode & S_IWGRP) ? "w" : "-");
        printf( (fStat.st_mode & S_IXGRP) ? "x" : "-");
        printf( (fStat.st_mode & S_IROTH) ? "r" : "-");
        printf( (fStat.st_mode & S_IWOTH) ? "w" : "-");
        printf( (fStat.st_mode & S_IXOTH) ? "x" : "-");
        printf( "; " );

        printf("Size: %ld B; Name: %s\n", fStat.st_size, dent->d_name);
    }
    
    closedir(srcdir);
    return 0;
}