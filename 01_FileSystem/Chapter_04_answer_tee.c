//
// Created by alfons on 19-3-26.
//
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>
#include "tlpi_hdr.h"

void Usage(char *exe) {
    printf("usage = %s filename\n", exe);
    printf("-a: append\n");
    exit(-1);
}

int main(int argc, char *argv[]) {
    int flag = O_CREAT | O_WRONLY;
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

    // 参数判断与解析
    if (argc < 2) {
        Usage(argv[0]);
    }

    int opt;
    opterr = 0;
    while ((opt = getopt(argc, argv, "ah")) != -1) {
        switch (opt) {
            case 'a':
                flag |= O_APPEND;
                break;
            case 'h':
                Usage(argv[0]);
                break;
            default:
                break;
        }
    }

    // 打开输出文件
    const char *file_name = argv[optind];
    int outputFd = open(file_name, flag, mode);
    if (outputFd == -1)
        errExit("open");

    // 写入文件和标准输出
    ssize_t read_num = 0;
    size_t BUF_SIZE = 1024;
    char buf[BUF_SIZE];

    while ((read_num = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, (size_t) read_num) == -1)
            errExit("write");

        if (write(outputFd, buf, (size_t) read_num) == -1)
            errExit("write file");
    }

    return 0;
}