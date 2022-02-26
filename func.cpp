/**
 * @author 222100209_���׶�
 * @date 2022/2/25
 */
#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstring>
#include <cstdlib>

using namespace std;

struct List {
    struct Date {
        int year;
        int month;
        int day;
    }date;
    struct List *next;
};

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
    copyRight();
    showTime();
    putchar('\n');
    for (int i = 0; i < 61; ++i) {
        cout << '*';
    }
    cout << endl;
    cout << "*  C:����һ������������ݵ���������                         *" << endl
         << "*  O:��ʾ����ǰ�����ڵ����������                           *" << endl
         << "*  S:������������������ݴ����ļ�                           *" << endl
         << "*  X:������ʾ���������ļ���<ȫ��>����                       *" << endl
         << "*  N:��ʾ���ܹ��ɺϷ����ڵ�<����>�ڵ�                       *" << endl
         << "*  D:ɾ������ĵ�һ�������һ�������ܹ��ɺϷ����ڵĽڵ�     *" << endl
         << "*  I:����ڵ�<����ͷ����β�����֮ǰ���ڵ�֮��>             *" << endl
         << "*  T:��ʾ�ڵ�����ڶ�Ӧ������                               *"  << endl
         << "*  A:�������ڴ�С��������                                 *"  << endl
         << "*  P:����������\"������\"���������Ľڵ�                       *" << endl
         << "*  F:<����>����ת                                         *" << endl
         << "*  Q:�˳�ϵͳ                                               *" << endl;
    for (int i = 0; i < 61; ++i) {
        cout << '*';
    }
    cout << endl;
}

/**
 * @func ����û�ѡ��
 * @param no param
 * @return �û�������ַ�(ת��Ϊ��д)
 */
char getChoice() {
    char choice = 'Q';
    char option[] = "C,O,S,X,N,D,I,T,A,P,F,Q";
    while (true) {
        menu();
        cout << "��ѡ��(" << option << "):";
        choice = char(toupper(getche()));
        putchar('\n');
        if (strchr(option,choice) && choice!=',') {
            break;
        }
        cout << "\a\nѡ�����,����������......\n" << endl;
        system("pause");
        cout << endl;
    }
    return choice;
}

/**
 * @func ��ʼ������
 * @param n �����Ľڵ���
 * @return ����ͷָ��
 */
struct List* createList(int n) {
    struct List *head,*node;
    head=(struct List *)malloc(sizeof(struct List));
    //ͷ���(�ڱ�)��������Ϊ�գ�
    head->next=NULL;
    for (int i=0;i<n;i++) {
        node=(struct List *)malloc(sizeof(struct List));
        node->date.day = 0;
        node->date.month = 0;
        node->date.year = 0;
        node->next=head->next;
        head->next=node;
    }
    return head;
}

/**
 * @func ����createList()����
 * @return
 */
struct List* createList() {
    int n;
    struct List *head;
    cout << "������Ҫ�����Ľڵ���:";
    cin >> n;
    head = createList(n);
    cout << "�ɹ���������" << n << "���ڵ������!\n" << endl;

    system("pause");
    cout << endl;
    return head;
}

/**
 * @func �ͷ�����
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