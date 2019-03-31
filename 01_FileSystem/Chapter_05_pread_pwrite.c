//
// Created by alfons on 19-3-31.
//

#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
    int fd = open("pread", O_RDWR | O_TRUNC | O_CREAT, 0666);
    if (fd == -1)
        errExit("open");

    // pwrite
    if (write(fd, "write", 5) == -1)
        errExit("write");
    printf("After write(), offset is %ld.\n", lseek(fd, 0, SEEK_CUR));      // 偏移量为5

    if (pwrite(fd, "pwrite", 6, 3) == -1)
        errExit("pwrite");
    printf("After pwrite(), offset is %ld.\n", lseek(fd, 0, SEEK_CUR));     // pwrite不改变文件的偏移量

    // pread
    size_t BUF_SIZE = 11;

    lseek(fd, 2, SEEK_SET);
    char buf[BUF_SIZE];
    ssize_t read_len = read(fd, buf, BUF_SIZE);
    if (read_len == -1)
        errExit("read");
    printf("After read(), offset is %ld.\n", lseek(fd, 0, SEEK_CUR)); // 偏移量为9
    printf("%s\n", buf);

    lseek(fd, 2, SEEK_SET);
    char buf2[BUF_SIZE];
    read_len = pread(fd, buf2, BUF_SIZE, 3);
    if (read_len == -1)
        errExit("read");
    printf("After pread(), offset is %ld.\n", lseek(fd, 0, SEEK_CUR));  // 偏移量为2,pread不改变文件的偏移量
    printf("%s\n", buf2);

    close(fd);
    return 0;
}