//
// Created by alfons on 19-3-27.
//

#include <stdbool.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"

#define READ 0
#define WRITE 1
#define NOT 2

// 按照命令格式进行相关的操作
// seekio -R5 -s100 seekio.txt
// s100 success.
// R5: 68 65 6c 6c 6f
int main(int argc, char *argv[]) {
    if (argc < 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file {r<length>|R<length>|w<string>|s<offset>}...\n", argv[0]);

    int rw_flag = NOT;
    bool hex_flag = false;
    size_t read_len = 0;
    char *wstr;
    size_t offset = 0;

    int opt;
    opterr = 0;
    while ((opt = getopt(argc, argv, "r::R::w:s:")) != -1) {
        switch (opt) {
            case 'r':
                rw_flag = READ;
                read_len = (size_t) atoi(optarg);
                hex_flag = false;
                break;
            case 'R':
                rw_flag = READ;
                read_len = (size_t) atoi(optarg);
                hex_flag = true;
                break;
            case 'w':
                rw_flag = WRITE;
                wstr = optarg;
                break;
            case 's':
                offset = (size_t) atoi(optarg);
                break;
            default:
                usageErr("%s file {r<length>|R<length>|w<string>|s<offset>}...\n", argv[0]);
                break;
        }
    }

    // 打开文件
    const char *file_path = argv[optind];
    if (file_path == NULL)
        errExit("filepath");

    int fd = open(file_path, O_RDWR | O_CREAT, 0666);
    if (fd == -1)
        errExit("open");

    // 设置偏移
    if (lseek(fd, offset, SEEK_SET) == -1)
        errExit("lseek");
    printf("s%ld success.\n", offset);

    // 根据读写标志做对应处理
    if (rw_flag == READ) {
        // 读文件处理
        char *read_buf;
        read_buf = malloc(read_len);
        if (read_buf == NULL)
            errExit("malloc");

        // 统计读出字符的数量
        ssize_t read_num = read(fd, read_buf, read_len);
        if (read_num == -1)
            errExit("read");

        if (read_num == 0)
            printf("%c%ld: end-of-file\n", hex_flag ? 'R' : 'r', read_num);
        else {
            printf("%c%ld: ", hex_flag ? 'R' : 'r', read_num);
            for (int i = 0; i < read_num; ++i) {
                if (hex_flag)
                    printf("%02x ", (unsigned int) read_buf[i]);
                else
                    printf("%c", isprint((unsigned char) read_buf[i]) ? read_buf[i] : '?');
            }
        }

    } else if (rw_flag == WRITE) {
        ssize_t write_num = write(fd, wstr, strlen(wstr));
        if (write_num == -1)
            errExit("write");

        printf("w%s: wrote %ld bytes.", wstr, write_num);
    } else {
        usageErr("%s file {r<length>|R<length>|w<string>|s<offset>}...\n", argv[0]);
    }

    // 关闭打开的文件
    if (close(fd) == -1)
        errExit("close");
    return 0;
}