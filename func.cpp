/**
 * @author 222100209_���׶�
 * @date 2022/2/25
 */
#include <iostream>
#include <ctime>

/**
 * @func �����Ȩ��Ϣ
 * @param no param
 */
void copyRight() {
    std::cout << "CopyRight <c> 2022-2022 ���׶�<222100209>. All Rights Reserved." << std::endl;
}

/**
 * @func �����ǰʱ��
 * @param no param
 */
void showTime() {
    struct tm tm;
    //��ȡʱ���
    time_t ts = time(0);
    localtime_r(&ts,&tm);
    char buf[128];
    strftime(buf,sizeof(buf),"%Y/%m/%d %H:%M:%S",&tm);
    std::cout << buf << std::endl;
}
