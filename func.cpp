/**
 * @author 222100209_李炎东
 * @date 2022/2/25
 */
#include <iostream>
#include <ctime>

using namespace std;

/**
 * @func 输出版权信息
 * @param no param
 */
void copyRight() {
    cout << "CopyRight <c> 2022-2022 李炎东<222100209>. All Rights Reserved." << endl;
}

/**
 * @func 输出当前时间
 * @param no param
 */
void showTime() {
    struct tm tm;
    static char wday[][4]={"日","一","二","三","四","五","六"};
    //获取时间戳
    time_t ts = time(0);
    localtime_r(&ts,&tm);
    char buf[128];
    strftime(buf,sizeof(buf),"%Y-%m-%d %a %H:%M:%S",&tm);
    cout << "当前时间:" << buf << endl;
}

/**
 * @func 输出菜单
 * @param no param
 */
void menu() {
    for (int i = 0; i < 50; ++i) {
        cout << '*';
    }
    cout << endl;
    cout << "*  C:创建一个存放日期数据的无序链表                     *" << endl
         << "*  O:显示链表前几个节点的日期数据                      *" << endl
         << "*  S:将整个链表的所有数据存入文件                      *" << endl
         << "*  X:分屏显示日期数据文件的<全部>内容                   *" << endl
         << "*  N:显示不能构成合法日期的<所有>节点                   *" << endl
         << "*  D:删除链表的第一个、最后一个、不能构成合法日期的节点     *" << endl
         << "*  I:插入节点<至链头、链尾、结点之前、节点之后>           *" << endl
         << "*  T:显示节点的日期对应的天数                         *"  << endl
         << "*  A:链表按日期从小到大排序                           *"  << endl
         << "*  P:查找链表中\"年月日\"都是素数的节点                   *" << endl
         << "*  F:<单向>链表翻转                                 *" << endl
         << "*  Q:退出系统                                      *" << endl;
    for (int i = 0; i < 50; ++i) {
        cout << '*';
    }
    cout << endl;
}
