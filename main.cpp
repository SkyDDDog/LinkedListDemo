/**
 * @author 222100209_李炎东
 * @version 1.0
 * @date 2022/2/25
 * @note 本项目在github(https://github.com/SkyDDDog/LinkedListDemo.git)进行托管备份
 * A LinkedList Demo
 *  1)显示版权(Copyright)信息,显示(系统)当前的日期,显示用户(功能)选择菜单
 *  2)获得用户的(功能)选择
 *  3)初始化(空)链表（创建哨兵结点）；释放链表
 *  4)在没有“创建 (无序)链表”之前，选择使用其他大部分功能
 *  5)创建 (无序)链表（结点数也可以由用户输入）
 *  6)输出链表的前n个结点（结点数n可以定义为常量或由用户输入，n=0输出整个链表）
 *  7)将整个链表数据存入一个文件中（文件夹当然也可以由用户输入）
 *  8)(分屏、加行号)显示链表数据文件的(全部)内容
 *  9)显示（所有）不能构成合法日期的结点
 *  10)删除链表的第一个结点；删除链表的最后一个结点；删除链表中不能构成合法日期的结点（当然可以用二级菜单实现就更为合理）
 *  11)将用当前日期构造的一个新结点加到链头；
 *      将用当前日期构造的一个新结点加到链尾；
 *      将用当前日期构造的一个新结点插入到第一个大于该结点日期的前面；
 *      将用当前日期构造的一个新结点插入到第一个小于该结点日期的后面
 *  12)显示链表每个结点的日期距离xxxx年1月1日的天数
 *  13)链表按日期从小到大排序输出
 *  14)统计并输出年月日都是素数的结点
 *  15)链表翻转(不建立新的表来实现)
 */
#include <iostream>
#include <cstdlib>
#include "constants.h"
#include "myFunc.h"

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

struct List {
    struct Date date;
    struct List *next;
};

int main() {
    //初始化链表
    List *head = (List *) malloc(sizeof(List));
    //用户的选择
    char choice;
    while ((choice=getChoice())!='Q') {
        if (choice!='C' && head->next==NULL) {
            cout << "\a\n链表为空!请先创建链表!\n" << endl;
            continue;

            system("pause");
            cout << endl;
        }
        switch (choice) {
            case 'C':
                head = createList();
                break;
            case 'O':
                showList(head);
                break;
            case 'S':
                saveInFile(head);
                break;
            case 'X':
                showAll(head);
                break;
            case 'N':
                showNotAcDate(head);
                break;
            case 'D':
                deleteList(head);
                break;
            case 'I':
                break;
            case 'T':
                break;
            case 'A':
                break;
            case 'P':
                break;
            case 'F':
                break;
        }
    }
    freeList(head);

    system("pause");
    return 0;
}

