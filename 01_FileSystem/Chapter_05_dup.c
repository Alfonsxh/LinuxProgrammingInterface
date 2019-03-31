//
// Created by alfons on 19-3-31.
//

#include <fcntl.h>
#include "tlpi_hdr.h"

#define _GNU_SOURCE

int main(int argc, char *argv[]) {

    int dup_fd = dup(1);
    printf("%s func get new fd %d.\n", "dup", dup_fd);
    write(dup_fd, "hello world\n", 12);

    int dup2_fd = dup2(1, 12);
    printf("%s func get new fd %d.\n", "dup2", dup2_fd);
    write(dup2_fd, "hello world\n", 12);


    int dup3_fd = dup3(1, 10, O_CLOEXEC);
    printf("%s func get new fd %d.\n", "dup3", dup3_fd);
    write(dup3_fd, "hello world\n", 12);
    return 0;
}