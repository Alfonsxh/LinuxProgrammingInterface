//
// Created by alfons on 19-3-26.
//

#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
    int fd = open("./test.txt", O_RDONLY);
    if (fd == -1)
        errExit("open");

    size_t BUF_SIZE = 1024;

    // 读取全部内容
    char buf[BUF_SIZE];
    ssize_t read_num = read(fd, buf, BUF_SIZE);
    if (read_num == -1)
        errExit("read");
    buf[read_num] = '\0';
    printf("read(%ld) -> %s\n", read_num, buf);

    // 读取部分内容，从文件起始头开始，SEEK_SET
    char buf1[BUF_SIZE];
    lseek(fd, 2, SEEK_SET);
    read_num = read(fd, buf1, BUF_SIZE);
    if (read_num == -1)
        errExit("read");
    buf1[read_num] = '\0';
    printf("read(%ld) SEEK_SET -> %s\n", read_num, buf1);

    // 读取部分内容，从文件当前位置开始，SEEK_CUR
    char buf2[BUF_SIZE];
    lseek(fd, 0, SEEK_SET);
    lseek(fd, 4, SEEK_CUR);
    read_num = read(fd, buf2, BUF_SIZE);
    if (read_num == -1)
        errExit("read");
    buf2[read_num] = '\0';
    printf("read(%ld) SEEK_CUR -> %s\n", read_num, buf2);

    // 读取部分内容，从文件末尾开始，SEEK_END
    char buf3[BUF_SIZE];
    lseek(fd, -5, SEEK_END);
    read_num = read(fd, buf3, BUF_SIZE);
    if (read_num == -1)
        errExit("read");
    buf3[read_num] = '\0';
    printf("read(%ld) SEEK_END -> %s\n", read_num, buf3);
    return 0;
}