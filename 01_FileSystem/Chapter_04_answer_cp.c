//
// Created by alfons on 19-3-26.
//

#include <fcntl.h>
#include "tlpi_hdr.h"

// 拷贝一个源文件包含空洞的文件，没明白是什么意思？下面的操作也能达成目的。
int main(int argc, char *argv[]) {
    if (argc != 3)
        errExit("argv error");

    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    int inputFd = open(argv[1], O_RDONLY);
    if (inputFd == -1)
        errExit("input file open");

    int outputFd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
    if (outputFd == -1)
        errExit("output file open");

    ssize_t read_num = 0;
    size_t BUF_SZIE = 1024;
    char buf[BUF_SZIE];
    while ((read_num = read(inputFd, buf, BUF_SZIE)) > 0) {
        if (write(outputFd, buf, (size_t) read_num) == -1)
            errExit("write file");
    }

    if (close(inputFd) == -1 || close(outputFd) == -1)
        errExit("close");
    return 0;
}