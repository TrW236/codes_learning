#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]) {
    
    char *fname = "./test.txt";
    int fd;
    fd = open(fname, O_CREAT | O_APPEND | O_WRONLY, 0777);
    
    if ( fd  == -1) {
        printf("file open failed!\n");
        return -1;
    } else {
        printf("file open successed! fd = %d\n", fd);
    }

    int ret_w;
    time_t t;
    struct tm t_info;
    char buf[128] = {0};
    // char *buf = (char *) malloc(128 * sizeof(char));
    int len_str;
    while(1) {
        t = time(NULL);
        t_info = *localtime(&t);
        sprintf(buf, "%d-%d-%d %02d:%02d:%02d\n", t_info.tm_year + 1900, t_info.tm_mon + 1, t_info.tm_mday, t_info.tm_hour, t_info.tm_min, t_info.tm_sec);
        len_str = strlen(buf);
        printf("Buffer: %s\nSize: %d\n", buf, len_str);
        ret_w = write(fd, buf, len_str);
        printf("Written %d\n", ret_w);
        sleep(1);
        printf("===\n");
    }
    // free(buf);
    close(fd);

    return 0;
}