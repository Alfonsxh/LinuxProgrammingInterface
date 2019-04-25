//
// Created by alfons on 19-4-23.
//
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    char buf[1024];

    for (int i = 0; i < 1024; ++i) {
        buf[i] = i % 26 + 'a';
        if (i % 26 == 0)
            buf[i] = '\n';
    }

    // O_TRUNC 如果文件存在，将文件大小设置为0,意思为重写
    int fd = open("stdio_copy_src", O_CREAT | O_WRONLY | O_TRUNC, 0666);

    int size = 1024 * 100;
    for (int j = 0; j < size; ++j) {
        write(fd, buf, 1024);
    }

    close(fd);
    return 0;
}