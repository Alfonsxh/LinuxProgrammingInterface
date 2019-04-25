//
// Created by alfons on 19-4-23.
//

#include <stdio.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {

    FILE *input_fd, *output_fd;

    if (argc < 4)
        usageErr("%s args error.\n", argv[0]);

    if ((input_fd = fopen(argv[1], "rb")) == NULL)
        errExit("fopen input file %s error.\n", argv[1]);

    if ((output_fd = fopen(argv[2], "wb")) == NULL)
        errExit("fopen output file %s error.\n", argv[2]);

    int BUF_SIZE = atoi(argv[3]);
    char *cache_buf;
    cache_buf = malloc(BUF_SIZE);

//  int r =  setvbuf(output_fd, cache_buf, _IONBF, BUF_SIZE);      // 不缓存IO
//    int r = setvbuf(output_fd, cache_buf, _IOLBF, BUF_SIZE);      // 行缓存IO，对于输出六，遇到换行符或者buf满了，刷新缓存区;对于输入流，每次读取一行数据。
  int r =  setvbuf(output_fd, cache_buf, _IOFBF, BUF_SIZE);      // 全缓存IO，缓存区满了才刷新。

    if (r != 0)
        errExit("set stdio cache cache_buf error.\n");

    int read_buf_size = 100;
    char read_buf[read_buf_size];
    int read_num = 0;
    while ((read_num = fread(read_buf, sizeof(char), read_buf_size, input_fd)) > 0)
        if (fwrite(read_buf, sizeof(char), read_buf_size, output_fd) != read_num)
            fatal("could not write whole buffer");

    fclose(input_fd);
    fclose(output_fd);
    return 0;
}