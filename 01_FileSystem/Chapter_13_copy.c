//
// Created by alfons on 19-4-23.
//
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {

    if (argc < 4)
        usageErr("%s file\n", argv[0]);

    int input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1)
        usageErr("input file %s not exist.\n", argv[1]);

    int output_fd = open(argv[2], O_WRONLY | O_TRUNC, 0666);
    if (output_fd == -1)
        usageErr("output file %s not exist.\n", argv[2]);

    int BUF_SIZE = atoi(argv[3]);
    char *buf;
    buf = malloc(BUF_SIZE);

    int read_size = 0;
    while ((read_size = read(input_fd, buf, BUF_SIZE)) > 0) {
        if (write(output_fd, buf, read_size) != read_size)
            fatal("could not write whole buffer");
    }

    if (read_size == -1)
        errExit("read");

    if (close(input_fd) == -1)
        errExit("close input");
    if (close(output_fd) == -1)
        errExit("close ouput");

    return 0;
}