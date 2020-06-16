#查找目录下所有源文件
#并将名称保存到变量中
aux_source_directory(. DIR_TEST_SRCS)
aux_source_directory(../algorithm/sort DIR_TEST_SRCS)

#添加头文件包含路径
include_directories(.)
include_directories(../algorithm/sort)
include_directories(../googletest)
include_directories(../googletest/include)

#指定生成目标
add_executable(ALGTest ${DIR_TEST_SRCS} ../googletest/src/gtest-all.cc ../googletest/src/gtest_main.cc)