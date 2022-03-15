/**
 * @author 222100209_李炎东
 * @date 2022/2/25
 * @note 在这定义了所有的函数声明
 */

#ifndef LINKEDLISTDEMO_MYFUNC_H

#include <iostream>
#include <cstdlib>

//显示版权信息
void copyRight();
//显示时间
void showTime();
//显示菜单
void menu();
//获取用户选择(集成版权信息，时间，菜单等)
char getChoice(const char option[],void (* menu)());
//创建链表(及其重载方法)并随机产生日期数据
struct List* createList(int n);
struct List* createList();
//释放链表
void freeList(struct List * head);
//输出所有链表数据
void showAll(struct List *head);
//输出链表数据(及其重载方法)
void showList(struct List *head,int n);
void showList(struct List *head);
//将链表数据存入文件
bool saveInFile(struct List *head,char *filename);
//将链表数据存入文件(重载，要求用户输入文件名)
bool saveInFile(struct List *head);
//判闰年
bool isLeapYear(int year);
//判断日期合法性
bool isAc(int year,int month,int day);
//输出不合法日期
void showNotAcDate(struct List *head);
//删除节点的二级菜单
void deleteMenu();
//删除节点
int deleteNode(struct List *head);
//删除非法日期节点
int deleteNoAcNode(struct List *head);
//删除第一个节点(不算哨兵节点)
int deleteHead(struct List *head);
//删除最后一个节点
int deleteTail(struct List *head);
//获取当前时间
struct Date getCurTime();
//判断日期比较日期大小
bool isBiggerDate(struct Date d1,struct Date d2);
//插入到链头
void insertHead(struct List *head);
//插入到链尾
void insertTail(struct List *head);
//插入到第一个大于当前日期的节点前面
void insertPrev(struct List *head);
//插入到第一个小于当前日期的节点后面
void insertPost(struct List *head);
//插入以上全部节点
void insertNode(struct List *head);
//计算距0000-00-00的天数
int getDays(struct Date date);
//计算距1901-01-01的天数
int getSDays(struct Date date);
//显示链表每个节点的日期和距1901-01-01的天数
void showListDays(struct List *head);
//升序排列节点
void sortByAsc(struct List *head);
//升序排序后输出
void printByAsc(struct List *head);
//判素数
bool isPrime(int n);
//判日期是否为素数(方法重载)
bool isPrime(struct Date date);
//输出年月日均为素数的节点
void printPrime(struct List *head);
//翻转链表
void reverseList(struct List *head);

#define LINKEDLISTDEMO_MYFUNC_H
#endif //LINKEDLISTDEMO_MYFUNC_H