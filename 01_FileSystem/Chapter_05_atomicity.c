//
// Created by alfons on 19-3-31.
//
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_WRONLY);
    if (fd != -1) {
        // 如果文件存在，则退出
        printf("[PID %ld] File \"%s\" already exists!\n", (long) getpid(), argv[1]);
        close(fd);
    } else {
        // 如果文件不存在，则先休息5s，再创建文件
        printf("[PID %ld] File \"%s\" don't exist yet!\n", (long) getpid(), argv[1]);
        if (argc > 2) {
            sleep(5);
            printf("[PID %ld] Done sleeping!\n", (long) getpid());
        }

        // 创建文件
        fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
        if (fd == -1)
            errExit("open");

        printf("[PID %ld] File \"%s\" created!\n", (long) getpid(), argv[1]);
    }

    return 0;
}