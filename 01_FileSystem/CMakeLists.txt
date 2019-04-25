#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/01_FileSystem)

# copy
add_executable(04_copy Chapter_04_fileio_copy.c)
target_link_libraries(04_copy
        error_functions)

# lseek
add_executable(04_lseek Chapter_04_fileio_lseek.c)
target_link_libraries(04_lseek
        error_functions)

# lseek io file
add_executable(04_seekio Chapter_04_fileio_seekio.c)
target_link_libraries(04_seekio
        error_functions)

# 原子操作例子
add_executable(05_atomicity Chapter_05_atomicity.c)
target_link_libraries(05_atomicity
        error_functions)

# fcntl
add_executable(05_fcntl Chapter_05_fcntl.c)
target_link_libraries(05_fcntl
        error_functions)

# dup
add_executable(05_dup Chapter_05_dup.c)
target_link_libraries(05_dup
        error_functions)

# pread/pwrite
add_executable(05_pread_pwrite Chapter_05_pread_pwrite.c)
target_link_libraries(05_pread_pwrite
        error_functions)

# readv
add_executable(05_readv Chapter_05_readv.c)
target_link_libraries(05_readv
        error_functions)

# create 100mb file
add_executable(13_create_100mb Chapter_13_create_100MB_file.c)
target_link_libraries(13_create_100mb
        error_functions)

# copy
add_executable(13_copy Chapter_13_copy.c)
target_link_libraries(13_copy
        error_functions)

# cache
add_executable(13_copy_stdio Chapter_13_copy_stdio.c)
target_link_libraries(13_copy_stdio
        error_functions)

# 课后习题
add_executable(04_tee Chapter_04_answer_tee.c)
target_link_libraries(04_tee
        error_functions)

add_executable(04_cp Chapter_04_answer_cp.c)
target_link_libraries(04_cp
        error_functions)

