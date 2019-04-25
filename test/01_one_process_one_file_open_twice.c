//
// Created by alfons on 19-4-1.
//
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    const char *test_name = "01_test";

    // fd1 只是读取
    int fd1 = open(test_name, O_RDONLY, 0666);
    if (fd1 == -1) {
        printf("fd1 open fail!");
        _exit(0);
    }

    char buf[5];
    if (read(fd1, buf, 5) == -1) {
        printf("fd1 first read fail!");
        _exit(0);
    }
    printf("fd1 first read -> %s\n", buf);

    // fd2 写入一些东西
    int fd2 = open(test_name, O_WRONLY, 0666);
    if (fd2 == -1) {
        printf("fd2 open fail!");
        _exit(0);
    }

    char *write_buf = "aaaaa";
    lseek(fd2, 0, SEEK_END);
    if (write(fd2, write_buf, 5) == -1) {
        printf("fd2 write fail!");
        _exit(0);
    }
    close(fd2);

    // fd1 继续读取内容，如果内容为fd2写入的内容
    // 则说明两个open使用的是不同的文件表项
    if (read(fd1, buf, 5) == -1) {
        printf("fd1 second read fail!");
        _exit(0);
    }
    printf("fd1 second read -> %s\n", buf);

    close(fd1);
    return 0;
}