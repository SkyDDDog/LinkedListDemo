/**
 * @author 222100209_���׶�
 * @date 2022/2/25
 */
#include <iostream>
#include <ctime>

using namespace std;

/**
 * @func �����Ȩ��Ϣ
 * @param no param
 */
void copyRight() {
    cout << "CopyRight <c> 2022-2022 ���׶�<222100209>. All Rights Reserved." << endl;
}

/**
 * @func �����ǰʱ��
 * @param no param
 */
void showTime() {
    struct tm tm;
    static char wday[][4]={"��","һ","��","��","��","��","��"};
    //��ȡʱ���
    time_t ts = time(0);
    localtime_r(&ts,&tm);
    char buf[128];
    strftime(buf,sizeof(buf),"%Y-%m-%d %a %H:%M:%S",&tm);
    cout << "��ǰʱ��:" << buf << endl;
}

/**
 * @func ����˵�
 * @param no param
 */
void menu() {
    for (int i = 0; i < 50; ++i) {
        cout << '*';
    }
    cout << endl;
    cout << "*  C:����һ������������ݵ���������                     *" << endl
         << "*  O:��ʾ����ǰ�����ڵ����������                      *" << endl
         << "*  S:������������������ݴ����ļ�                      *" << endl
         << "*  X:������ʾ���������ļ���<ȫ��>����                   *" << endl
         << "*  N:��ʾ���ܹ��ɺϷ����ڵ�<����>�ڵ�                   *" << endl
         << "*  D:ɾ������ĵ�һ�������һ�������ܹ��ɺϷ����ڵĽڵ�     *" << endl
         << "*  I:����ڵ�<����ͷ����β�����֮ǰ���ڵ�֮��>           *" << endl
         << "*  T:��ʾ�ڵ�����ڶ�Ӧ������                         *"  << endl
         << "*  A:�������ڴ�С��������                           *"  << endl
         << "*  P:����������\"������\"���������Ľڵ�                   *" << endl
         << "*  F:<����>����ת                                 *" << endl
         << "*  Q:�˳�ϵͳ                                      *" << endl;
    for (int i = 0; i < 50; ++i) {
        cout << '*';
    }
    cout << endl;
}
