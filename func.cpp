/**
 * @author 222100209_���׶�
 * @date 2022/2/25
 */
#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "constants.h"

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
    cout << "$  C:����һ������������ݵ���������                             $" << endl
         << "$  O:��ʾ����ǰ�����ڵ����������                               $" << endl
         << "$  S:������������������ݴ����ļ�                               $" << endl
         << "$  X:������ʾ���������ļ���<ȫ��>����                           $" << endl
         << "$  N:��ʾ���ܹ��ɺϷ����ڵ�<����>�ڵ�                           $" << endl
         << "$  D:ɾ������ĵ�һ�������һ�������ܹ��ɺϷ����ڵĽڵ�         $" << endl
         << "$  I:����ڵ�<����ͷ����β�����֮ǰ���ڵ�֮��>                 $" << endl
         << "$  T:��ʾ�ڵ�����ڶ�Ӧ������                                   $"  << endl
         << "$  A:�������ڴ�С��������                                     $"  << endl
         << "$  P:����������\"������\"���������Ľڵ�                           $" << endl
         << "$  F:<����>����ת                                             $" << endl
         << "$  Q:�˳�ϵͳ                                                   $" << endl;
    for (int i = 0; i < 65; ++i) {
        cout << '=';
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
 * @func ��ʼ�����������������
 * @param n �����Ľڵ���
 * @return ����ͷָ��
 */
struct List* createList(int n) {
    struct List *head,*node;
    head=(struct List *)malloc(sizeof(struct List));
    //ͷ���(�ڱ�)��������Ϊ�գ�
    head->next=NULL;
    srand(time(NULL));
    for (int i=0;i<n;i++) {
        node=(struct List *)malloc(sizeof(struct List));
        node->date.day = rand()%31+1;
        node->date.month = rand()%12+1;
        node->date.year = rand()%100+1921;
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
    cout << "�ɹ�����" << n << "�����ڽڵ�!(1921<=��<=2021,1<=��<=12,1<=��<=31)\n" << endl;

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

/**
 * @func ��ҳ���������������
 * @param head ����ͷָ��
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
 * @finc ��ҳ����ض�������������Ϣ
 * @param head ����ͷָ��
 * @param n ��ѯ����Ϣ����
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
 * @func ��showList����������,��һ�㣬�ֿ�ʹ��showList()��showAll()
 * @param head ����ͷָ��
 */
void showList(struct List *head) {
    int n;
    cout << "������Ҫ��ʾ�Ľڵ����(����0����ʾ��������):";
    cin >> n;
    if (!n) {
        showAll(head);
    } else {
        showList(head,n);
    }
}

/**
 * @func ���������ݴ����ļ�
 * @param head ����ͷָ��
 * @return �Ƿ����ɹ�
 */
bool saveInFile(struct List *head) {
    ofstream outfile;
    outfile.open("D:\\tempFile\\test.db");
    if (!outfile) {
        cout << "\a�ļ���ʧ��!" << endl;
        return false;
    }
    for (struct List *current = head->next; current ; current=current->next) {
        outfile << current->date.year << '.'
                << current->date.month << '.'
                << current->date.day << '.'
                << endl;
    }
    outfile.close();
    cout << "�ļ�����ɹ�,���\"D:\\tempFile\\test.db\"�鿴���" << endl;

    system("pause");
    cout << endl;
    return true;
}

/**
 * @func �ж����ںϷ���
 * @param year ��
 * @param month ��
 * @param day ��
 * @return �����Ƿ�Ϸ�
 */
bool isAc(int year,int month,int day) {
    if (month = 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        if (day > 29) {
            return false;
        } else {
            return true;
        }
    } else if (month == 2) {
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
 * @func ������Ϸ�����
 * @param head ����ͷָ��
 */
void showNotAcDate(struct List *head) {
    int cnt = 0;
    int row = 1;
    for (struct List *current = head->next; current ; current=current->next) {
        if (!isAc(current->date.year,current->date.month,current->date.day)) {
            cnt++;
            printf(" %04d.%02d.%02d "
                    ,current->date.year,current->date.month,current->date.day);
            if ((!((cnt+1)%5)) && cnt) {
                cout << endl;
            }
        }
    }
    cout << endl;
    cout << "���ܹ��ɺϷ����ڵĸ���Ϊ:" << cnt << endl;

    system("pause");
    cout << endl;
}