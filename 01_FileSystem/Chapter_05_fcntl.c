//
// Created by alfons on 19-3-31.
//

#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        errExit("open");
    sleep(5);
    close(fd);

    // F_GETFL 获取文件状态标志
    printf("File(%d) status flags is %d.\n", 0, fcntl(0, F_GETFL));
    printf("File(%d) status flags is %d.\n", 1, fcntl(1, F_GETFL));
    printf("File(%d) status flags is %d.\n", 2, fcntl(2, F_GETFL));

    // F_GETFD 获取文件描述标志
    printf("File(%d) status flags is %d.\n", 0, fcntl(0, F_GETFD));
    printf("File(%d) status flags is %d.\n", 1, fcntl(1, F_GETFD));
    printf("File(%d) status flags is %d.\n", 2, fcntl(2, F_GETFD));

    return 0;
}