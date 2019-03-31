#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/01_FileSystem)

# copy
add_executable(copy Chapter_04_fileio_copy.c)
target_link_libraries(copy
        error_functions)

# lseek
add_executable(lseek Chapter_04_fileio_lseek.c)
target_link_libraries(lseek
        error_functions)

# lseek io file
add_executable(seekio Chapter_04_fileio_seekio.c)
target_link_libraries(seekio
        error_functions)

# 原子操作例子
add_executable(atomicity Chapter_05_atomicity.c)
target_link_libraries(atomicity
        error_functions)

# fcntl
add_executable(fcntl Chapter_05_fcntl.c)
target_link_libraries(fcntl
        error_functions)

# dup
add_executable(dup Chapter_05_dup.c)
target_link_libraries(dup
        error_functions)

# pread/pwrite
add_executable(pread_pwrite Chapter_05_pread_pwrite.c)
target_link_libraries(pread_pwrite
        error_functions)

# readv
add_executable(readv Chapter_05_readv.c)
target_link_libraries(readv
        error_functions)

# 课后习题
add_executable(tee Chapter_04_answer_tee.c)
target_link_libraries(tee
        error_functions)

add_executable(cp Chapter_04_answer_cp.c)
target_link_libraries(cp
        error_functions)

