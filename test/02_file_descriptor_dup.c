//
// Created by alfons on 19-4-1.
//
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    const char *test_name = "02_test";

    // fd1 只是读取
    int fd1 = open(test_name, O_RDONLY, 0666);
    if (fd1 == -1) {
        printf("fd1 open fail!");
        _exit(0);
    }

    // fd2 对 fd1 进行了复制
    int fd2 = dup(fd1);
    if (fd2 == -1) {
        printf("fd2 dup fail!");
        _exit(0);
    }

    // fd1 先读取5个字节
    char buf[5];
    if (read(fd1, buf, 5) == -1) {
        printf("fd1 read fail!");
        _exit(0);
    }
    printf("fd1 read -> %s\n", buf);

    // fd2 也读取5个字节，如果两次读取的内容与文件中的一致
    // 那么说明fd2和fd1使用了同一个文件表项
    if (read(fd2, buf, 5) == -1) {
        printf("fd2 first read fail!");
        _exit(0);
    }
    printf("fd2 first read -> %s\n", buf);

    // 先关闭fd1
    close(fd1);

    // 此时，如果fd2还能读取文件内容，说明之前文件表项中的计数为二
    if (read(fd2, buf, 5) == -1) {
        printf("fd2 second read fail!");
        _exit(0);
    }
    printf("fd2 second read -> %s\n", buf);
    close(fd2);

    return 0;
}