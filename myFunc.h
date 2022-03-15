/**
 * @author 222100209_���׶�
 * @date 2022/2/25
 * @note ���ⶨ�������еĺ�������
 */

#ifndef LINKEDLISTDEMO_MYFUNC_H

#include <iostream>
#include <cstdlib>

//��ʾ��Ȩ��Ϣ
void copyRight();
//��ʾʱ��
void showTime();
//��ʾ�˵�
void menu();
//��ȡ�û�ѡ��(���ɰ�Ȩ��Ϣ��ʱ�䣬�˵���)
char getChoice(const char option[],void (* menu)());
//��������(�������ط���)�����������������
struct List* createList(int n);
struct List* createList();
//�ͷ�����
void freeList(struct List * head);
//���������������
void showAll(struct List *head);
//�����������(�������ط���)
void showList(struct List *head,int n);
void showList(struct List *head);
//���������ݴ����ļ�
bool saveInFile(struct List *head,char *filename);
//���������ݴ����ļ�(���أ�Ҫ���û������ļ���)
bool saveInFile(struct List *head);
//������
bool isLeapYear(int year);
//�ж����ںϷ���
bool isAc(int year,int month,int day);
//������Ϸ�����
void showNotAcDate(struct List *head);
//ɾ���ڵ�Ķ����˵�
void deleteMenu();
//ɾ���ڵ�
int deleteNode(struct List *head);
//ɾ���Ƿ����ڽڵ�
int deleteNoAcNode(struct List *head);
//ɾ����һ���ڵ�(�����ڱ��ڵ�)
int deleteHead(struct List *head);
//ɾ�����һ���ڵ�
int deleteTail(struct List *head);
//��ȡ��ǰʱ��
struct Date getCurTime();
//�ж����ڱȽ����ڴ�С
bool isBiggerDate(struct Date d1,struct Date d2);
//���뵽��ͷ
void insertHead(struct List *head);
//���뵽��β
void insertTail(struct List *head);
//���뵽��һ�����ڵ�ǰ���ڵĽڵ�ǰ��
void insertPrev(struct List *head);
//���뵽��һ��С�ڵ�ǰ���ڵĽڵ����
void insertPost(struct List *head);
//��������ȫ���ڵ�
void insertNode(struct List *head);
//�����0000-00-00������
int getDays(struct Date date);
//�����1901-01-01������
int getSDays(struct Date date);
//��ʾ����ÿ���ڵ�����ں;�1901-01-01������
void showListDays(struct List *head);
//�������нڵ�
void sortByAsc(struct List *head);
//������������
void printByAsc(struct List *head);
//������
bool isPrime(int n);
//�������Ƿ�Ϊ����(��������)
bool isPrime(struct Date date);
//��������վ�Ϊ�����Ľڵ�
void printPrime(struct List *head);
//��ת����
void reverseList(struct List *head);

#define LINKEDLISTDEMO_MYFUNC_H
#endif //LINKEDLISTDEMO_MYFUNC_H