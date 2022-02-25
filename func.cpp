/**
 * @author 222100209_李炎东
 * @date 2022/2/25
 */
#include <iostream>
#include <ctime>

/**
 * @func 输出版权信息
 * @param no param
 */
void copyRight() {
    std::cout << "CopyRight <c> 2022-2022 李炎东<222100209>. All Rights Reserved." << std::endl;
}

/**
 * @func 输出当前时间
 * @param no param
 */
void showTime() {
    struct tm tm;
    //获取时间戳
    time_t ts = time(0);
    localtime_r(&ts,&tm);
    char buf[128];
    strftime(buf,sizeof(buf),"%Y/%m/%d %H:%M:%S",&tm);
    std::cout << buf << std::endl;
}
