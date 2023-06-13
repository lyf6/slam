#include <hello.h>
#include <iostream>
#include <glog/logging.h>
// void sayHello() { std::cout << "Hello SLAM" << std::endl; }
void sayHello()
{
    // google::InitGoogleLogging(argv[0]);
    google::SetLogDestination(google::GLOG_FATAL, "./log/log_fatal_");     // 设置 google::FATAL 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_ERROR, "./log/log_error_");     // 设置 google::ERROR 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_WARNING, "./log/log_warning_"); // 设置 google::WARNING 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_INFO, "./log/log_info_");       // 设置 google::INFO 级别的日志存储路径和文件名前缀
    LOG(INFO) << "HELLO"
              << "ok!";
    LOG(INFO) << "Hello SLAM";
}

int add_int(int a, int b)
{
    return a + b;
}