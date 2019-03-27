#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/01_FileSystem)

add_executable(copy Chapter_04_fileio_copy.c)
target_link_libraries(copy
        error_functions)

add_executable(lseek Chapter_04_fileio_lseek.c)
target_link_libraries(lseek
        error_functions)

add_executable(seekio Chapter_04_fileio_seekio.c)
target_link_libraries(seekio
        error_functions)

# 课后习题
add_executable(tee Chapter_04_answer_tee.c)
target_link_libraries(tee
        error_functions)

add_executable(cp Chapter_04_answer_cp.c)
target_link_libraries(cp
        error_functions)