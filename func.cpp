/**
 * @author 222100209_李炎东
 * @date 2022/2/25
 */
#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "constants.h"
#include "myFunc.h"

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
    for (int i = 0; i < 65; ++i) {
        cout << '=';
    }
    cout << endl;
    copyRight();
    cout << endl;
    showTime();
    putchar('\n');
    for (int i = 0; i < 65; ++i) {
        cout << '=';
    }
    cout << endl;
    cout << "$  C:创建一个存放日期数据的无序链表                             $" << endl
         << "$  O:显示链表前几个节点的日期数据                               $" << endl
         << "$  S:将整个链表的所有数据存入文件                               $" << endl
         << "$  X:分屏显示日期数据文件的<全部>内容                           $" << endl
         << "$  N:显示不能构成合法日期的<所有>节点                           $" << endl
         << "$  D:删除链表的第一个、最后一个、不能构成合法日期的节点         $" << endl
         << "$  I:插入节点<至链头、链尾、结点之前、节点之后>                 $" << endl
         << "$  T:显示节点的日期对应的天数                                   $"  << endl
         << "$  A:链表按日期从小到大排序                                     $"  << endl
         << "$  P:查找链表中\"年月日\"都是素数的节点                           $" << endl
         << "$  F:<单向>链表翻转                                             $" << endl
         << "$  Q:退出系统                                                   $" << endl;
    for (int i = 0; i < 65; ++i) {
        cout << '=';
    }
    cout << endl;
}

/**
 * @func 获得用户选择
 * @param no param
 * @return 用户输入的字符(转化为大写)
 */
char getChoice() {
    char choice = 'Q';
    char option[] = "C,O,S,X,N,D,I,T,A,P,F,Q";
    while (true) {
        menu();
        cout << "请选择(" << option << "):";
        choice = char(toupper(getche()));
        putchar('\n');
        if (strchr(option,choice) && choice!=',') {
            break;
        }
        cout << "\a\n选择错误,请重新输入......\n" << endl;
        system("pause");
        cout << endl;
    }
    return choice;
}

/**
 * @func 初始化链表并插入随机日期
 * @param n 创建的节点数
 * @return 链表头指针
 */
struct List* createList(int n) {
    struct List *head,*node;
    head=(struct List *)malloc(sizeof(struct List));
    //头结点(哨兵)的数据域为空！
    head->next=NULL;
    srand(time(NULL));
    for (int i=0;i<n;i++) {
        node = (struct List *)malloc(sizeof(struct List));
        node->date.day = rand()%31+1;
        node->date.month = rand()%12+1;
        node->date.year = rand()%100+1921;
        node->next=head->next;
        head->next=node;
    }
    return head;
}

/**
 * @func 重载createList()方法
 * @return
 */
struct List* createList() {
    int n;
    struct List *head;
    cout << "请输入要创建的节点数:";
    cin >> n;
    head = createList(n);
    cout << "成功创建" << n << "个日期节点!(1921<=年<=2021,1<=月<=12,1<=日<=31)\n" << endl;

    system("pause");
    cout << endl;
    return head;
}

/**
 * @func 释放链表
 * @param head
 */
void freeList(struct List * head)
{
    struct List *current;
    current = head;
    while (head!=NULL) {
        current=head;
        head = current->next;
        free(current);
    }
}

/**
 * @func 分页输出链表所有数据
 * @param head 链表头指针
 */
void showAll(struct List *head) {
    struct List *current;
    current = head->next;
    int row=1;
    for (int i = 0; current; ++i,current = current->next) {
        if (!(i%5)) {
            printf("%2d:",row);
            row++;
        }
        printf(" %04d.%02d.%02d "
                ,current->date.year,current->date.month,current->date.day);
        if ((!((i+1)%5)) && i) {
            cout << endl;
        }
    }

    cout << endl;
    system("pause");
    cout << endl;
}

/**
 * @finc 分页输出特定数量的链表信息
 * @param head 链表头指针
 * @param n 查询的信息数量
 */
void showList(struct List *head,int n) {
    struct List *current;
    int row = 1, cnt = n;
    current=head->next;
    for (int i = 0; i < n && current; ++i,--cnt,current = current->next) {
        if (!(i%5)) {
            printf("%2d:",row);
            row++;
        }
        printf(" %04d.%02d.%02d "
               ,current->date.year,current->date.month,current->date.day);
        if ((!((i+1)%5)) && i) {
            cout << endl;
        }
        if(!cnt) {
            cout << endl;
            break;
        }
    }

    system("pause");
    cout << endl;
}

/**
 * @func 对showList方法的重载,加一层，分开使用showList()和showAll()
 * @param head 链表头指针
 */
void showList(struct List *head) {
    int n;
    cout << "请输入要显示的节点个数(输入0以显示所有数据):";
    cin >> n;
    if (!n) {
        showAll(head);
    } else {
        showList(head,n);
    }
}

/**
 * @func 将链表数据存入文件
 * @param head 链表头指针
 * @return 是否存入成功
 */
bool saveInFile(struct List *head) {
    ofstream outfile;
    outfile.open("D:\\tempFile\\test.db");
    if (!outfile) {
        cout << "\a文件打开失败!" << endl;
        return false;
    }
    for (struct List *current = head->next; current ; current=current->next) {
        outfile << current->date.year << '.'
                << current->date.month << '.'
                << current->date.day << endl;
    }
    outfile.close();
    cout << "文件输入成功,请打开\"D:\\tempFile\\test.db\"查看结果" << endl;

    system("pause");
    cout << endl;
    return true;
}

/**
 * @func 判闰年
 * @param year
 * @return 是否是闰年
 */
bool isLeapYear(int year) {
    if ((year%4 == 0 && year%100 != 0) || year%400 == 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * @func 判断日期合法性
 * @param year 年
 * @param month 月
 * @param day 日
 * @return 日期是否合法
 */
bool isAc(int year,int month,int day) {
    if (month == 2 && isLeapYear(year)) {
        if (day > 29) {
            return false;
        } else {
            return true;
        }
    }
    if (month == 2) {
        if (day > 28) {
            return false;
        } else {
            return true;
        }
    }
    if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
        return true;
    } else {
        if (day > 30) {
            return false;
        } else {
            return true;
        }
    }
}

/**
 * @func 输出不合法日期
 * @param head 链表头指针
 */
void showNotAcDate(struct List *head) {
    int cnt = 0;
    for (struct List *current = head->next; current ; current=current->next) {
        if (!isAc(current->date.year,current->date.month,current->date.day)) {
            cnt++;
            printf(" %04d.%02d.%02d "
                    ,current->date.year,current->date.month,current->date.day);
            if ((!(cnt%5)) && cnt) {
                cout << endl;
            }
        }
    }
    cout << endl;
    cout << "不能构成合法日期的个数为:" << cnt << endl;

    system("pause");
    cout << endl;
}

/**
 * @func 删除第一个节点，日期非法的节点，最后一个节点
 * @param head 链表头指针
 */
void deleteNode(struct List *head)
{
    struct List *current,*prev;
    current=head->next;
    //删除第一个节点
    deleteHead(head);
    while (current) {
        if (!isAc(current->date.year,current->date.month,current->date.day)) {
            prev->next=current->next;
//            free(current);
            current = prev;
        }
        prev = current;
        current = current->next;
    }
    //删除最后一个节点
    deleteTail(head);
    cout << "删除成功" << endl;
    system("pause");
    cout << endl;
}

/**
 * @func 删除第一个节点(不算哨兵节点)
 * @param head
 */
void deleteHead(struct List *head) {
    struct List *current;
    current = head->next;
    head->next = current->next;
    free(current);
}

/**
 * @func 删除最后一个节点
 * @param head
 */
void deleteTail(struct List *head) {
    struct List *prev = head;
//    if (head->next == NULL) {
//        free(head);
//        head = NULL;
//    }
    while (prev->next->next) {
        prev = prev->next;
    }
    free(prev->next);
    prev->next = NULL;
}

/**
 * @func 获取当前日期
 * @return 日期结构
 */
struct Date getCurTime() {
    time_t timep;
    time(&timep);
    struct tm *p;
    p = gmtime(&timep);
    struct Date date = {1900 + p->tm_year,1 + p->tm_mon,p->tm_mday};
    return date;
}

/**
 * @func 比较日期大小
 * @param d1 第一个日期
 * @param d2 第二个日期
 * @return d1>d2 返回true
 */
bool isBiggerDate(struct Date d1,struct Date d2) {
    if (d1.year > d2.year) {
        return true;
    }
    if (d1.year == d2.year && d1.month > d2.month) {
        return true;
    }
    if (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day) {
        return true;
    }
    return false;
}

/**
 * @func 插入当前日期成为第一个节点
 * @param head 链表头指针
 */
void insertHead(struct List *head) {
    struct List *node;
    node = (struct List *)malloc(sizeof(struct List));
    node->date = getCurTime();
    node->next = head->next;
    head->next = node;
}

/**
 * @func 插入当前日期成为链表最后一个节点
 * @param head 链表头指针
 */
void insertTail(struct List *head) {
    struct List *current,*node;
    current = head;
    node = (struct List *)malloc(sizeof(struct List));
    node->date = getCurTime();
    node->next = NULL;
    while (current->next) {
        current = current->next;
    }
    current->next = node;
}

/**
 * @func 插入到第一个大于当前日期的节点前面
 * @param head 链表头指针
 */
void insertPrev(struct List *head) {
    struct List *current,*node;
    current = head;
    node = (struct List *)malloc(sizeof(struct List));
    node->date = getCurTime();
    while (current->next) {
        if (isBiggerDate(current->next->date,node->date)) {
            node->next = current->next;
            current->next = node;
            break;
        }
        current = current->next;
    }
}

/**
 * @func 插入到第一个小于当前日期的节点后面
 * @param head 链表头指针
 */
void insertPost(struct List *head) {
    struct List *current,*node;
    current = head;
    node = (struct List *)malloc(sizeof(struct List));
    node->date = getCurTime();
    while (current) {
        if (!isBiggerDate(current->next->date,node->date)) {
            node->next = current->next;
            current->next = node;
            break;
        }
        current = current->next;
    }
}

/**
 * @func 将用当前日期构造的一个新结点加到链头
 *       将用当前日期构造的一个新结点加到链尾
 *       将用当前日期构造的一个新结点插入到第一个大于该结点日期的前面
 *       将用当前日期构造的一个新结点插入到第一个小于该结点日期的后面
 * @param head
 */
void insertNode(struct List *head) {
    insertHead(head);
    insertTail(head);
    insertPrev(head);
    insertPost(head);
    cout << "节点插入成功" << endl;
    system("pause");
    cout << endl;
}

/**
 * @func 计算距0000-00-00多少天
 * @param date 日期
 * @return 天数
 */
int getDays(struct Date date) {
    //数组定义每个月的天数 days_month[0]留空
    int days_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int sum=0;
    for (int i = 0; i < date.year; ++i) {
        if (isLeapYear(date.year)) {
            sum += 366;
        } else {
            sum += 365;
        }
    }
    if (isLeapYear(date.year)) {
        days_month[2] = 29;
    } else {
        days_month[2] = 28;
    }
    for (int i = 0; i < date.month; ++i) {
        sum += days_month[i];
    }

    return sum + date.day;
}

/**
 * @func 计算距1901-01-01的天数
 * @param date 日期
 * @return 天数
 */
int getSDays(struct Date date) {
    return (getDays(date) - getDays(cDate));
}

/**
 * @func 显示链表每个节点的日期和距1901-01-01的天数
 * @param head 链表头指针
 */
void showListDays(struct List *head) {
    struct List *current;
    for (current = head->next; current ; current = current->next) {
        printf("%04d-%02d-%02d\t距1901-01-01%6d 天\n"
            ,current->date.year,current->date.month,current->date.day,getSDays(current->date));
    }
    system("pause");
    cout << endl;
}

/**
 * @func 升序(从小到大)排列日期节点
 * @param head
 */
void sortByAsc(struct List *head) {
    struct List *current,*post;
    struct Date temp;
    current = head->next;
    while (current) {
        post = current->next;
        while (post) {
            if (isBiggerDate(current->date,post->date)) {
                temp = current->date;
                current->date = post->date;
                post->date = temp;
            }
            post = post->next;
        }
        current = current->next;
    }
}

/**
 * @func 日期节点升序(从小到大)排列后输出
 * @param head
 */
void printByAsc(struct List *head) {
    sortByAsc(head);
    showAll(head);
    cout << "已将数据全部按日期从小到大排序!" << endl;
    system("pause");
    cout << endl;
}

