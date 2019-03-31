//
// Created by alfons on 19-3-31.
//

#include <sys/uio.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
    int fd;

    // iov 数据结构
    struct iovec iov[3];

    struct stat my_struct;
    int x;
#define STR_SIZE 100
    char str[STR_SIZE];

    ssize_t total_read = 0;

    if (argc != 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file\n", argv[0]);

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        errExit("open");

    // 更新iov结构体
    iov[0].iov_base = &my_struct;
    iov[0].iov_len = sizeof(my_struct);
    total_read += iov[0].iov_len;

    iov[1].iov_base = &x;
    iov[1].iov_len = sizeof(x);
    total_read += iov[1].iov_len;

    iov[2].iov_base = str;
    iov[2].iov_len = STR_SIZE;
    total_read += iov[2].iov_len;

    // 通过readv读取
    ssize_t read_num = readv(fd, iov, 3);
    if (read_num == -1)
        errExit("readv");

    if (read_num < total_read)
        printf("Read fewer bytes than requested\n");

    printf("Total bytes requested: %ld; bytes read: %ld\n", total_read, read_num);

    close(fd);
    return 0;
}