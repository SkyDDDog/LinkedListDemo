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
#include <cmath>
#include "constants.h"
#include "myFunc.h"

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
    for (int i = 0; i < MENU_LENGTH_1; ++i) {
        cout << '=';
    }
    cout << endl;
    copyRight();
    cout << endl;
    showTime();
    putchar('\n');
    for (int i = 0; i < MENU_LENGTH_1; ++i) {
        cout << '=';
    }
    cout << endl;
    cout << "$  C:����������������������                                                $" << endl
         << "$  S:��ʾ����ǰn���ڵ����������                                               $" << endl
         << "$  F:��������������ݴ����ļ�                                                  $" << endl
         << "$  E:��ʾ�������ڽڵ�����                                                      $" << endl
         << "$  N:��ʾ�Ƿ����ڵĽڵ�����                                                    $" << endl
         << "$  D:ɾ�������ͷ��β�ڵ㼰�Ƿ����ڵĽڵ�                                      $" << endl
         << "$  I:����ڵ�                                                                  $" << endl
         << "$  <����ͷ����β����һ�����ڵ�ǰ���ڵĽ��֮ǰ����һ��С�ڵ�ǰ���ڵĽڵ�֮��>  $" << endl
         << "$  T:��ʾ�ڵ��������1901-01-01��������                                      $"  << endl
         << "$  A:�������ڴ�С��������                                                    $"  << endl
         << "$  P:�����������������ݾ�Ϊ�����Ľڵ�                                          $" << endl
         << "$  R:����ת                                                                  $" << endl
         << "$  Q:�˳�ϵͳ                                                                  $" << endl;
    for (int i = 0; i < MENU_LENGTH_1; ++i) {
        cout << '=';
    }
    cout << endl;
}

/**
 * @func ����û�ѡ��
 * @param no param
 * @return �û�������ַ�(ת��Ϊ��д)
 */
char getChoice(const char option[],void (* menu)()) {
    char choice = 'Q';
//    char option[] = "C,S,F,E,N,D,I,T,A,P,R,Q";
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
        node = (struct List *)malloc(sizeof(struct List));
        node->date.day = rand()%31+1;
        node->date.month = rand()%12+1;
        node->date.year = rand()%124+1921;
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
    cout << "�ɹ�����" << n << "�����ڽڵ�!(1921<=��<=2025,1<=��<=12,1<=��<=31)\n" << endl;

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
    cout << endl;
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
bool saveInFile(struct List *head,char *filename) {
    string f = ".\\";
    f.append(filename).append(".db");
    ofstream outfile;
    outfile.open(f.c_str());
    if (!outfile) {
        cout << "\a�ļ���ʧ��!" << endl;
        return false;
    }
    for (struct List *current = head->next; current ; current=current->next) {
        outfile << current->date.year << '.'
                << current->date.month << '.'
                << current->date.day << endl;
    }
    outfile.close();
    cout << "�ļ�����ɹ�,��� "+ f +" �鿴���" << endl;

    system("pause");
    cout << endl;
    return true;
}

/**
 * @func �����ݴ����ļ���Ҫ���û������ļ���
 * @param head
 * @return
 */
bool saveInFile(struct List *head) {
    char fileName[MAX_FILENAME];
    cout << "�������ļ���:";
    cin >> fileName;
    if (saveInFile(head,fileName)) {
        return true;
    } else {
        return false;
    }

}

/**
 * @func ������
 * @param year
 * @return �Ƿ�������
 */
bool isLeapYear(int year) {
    if ((year%4 == 0 && year%100 != 0) || year%400 == 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * @func �ж����ںϷ���
 * @param year ��
 * @param month ��
 * @param day ��
 * @return �����Ƿ�Ϸ�
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
 * @func ������Ϸ�����
 * @param head ����ͷָ��
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
    cout << "���ܹ��ɺϷ����ڵĸ���Ϊ:" << cnt << endl;

    system("pause");
    cout << endl;
}

/**
 * @func ɾ���ڵ�Ķ����˵�
 */
void deleteMenu() {
    // �����˵�
    cout << endl;
    for (int i = 0; i < MENU_LENGTH_2; ++i) {
        cout << '-';
    }
    cout << endl;
    cout << "F:ɾ����һ���ڵ�" << endl;
    cout << "L:ɾ�����һ���ڵ�" << endl;
    cout << "N:ɾ���Ƿ��ڵ�" << endl;
    cout << "Q:�˳������˵�" << endl;
    for (int i = 0; i < MENU_LENGTH_2; ++i) {
        cout << '-';
    }
    cout << endl;
}

/**
 * @func ɾ���ڵ�(�����˵�)
 * @param head
 */
int deleteNode(struct List *head) {
    char choice;
    int a, b, c;
    while ((choice = getChoice(OPTION_2,deleteMenu)) != 'Q') {
        switch (choice) {
            // First Node
            case 'F':
                a = deleteHead(head);
                cout << endl;
                cout << "�ɹ�ɾ����һ���ڵ�" << endl;
                cout << endl;
                system("pause");
                break;
            // Last Node
            case 'L':
                b = deleteTail(head);
                cout << endl;
                cout << "�ɹ�ɾ�����Ľڵ�" << endl;
                cout << endl;
                system("pause");
                break;
            // Not Ac Node
            case 'N':
                c = deleteNoAcNode(head);
                if (a) {
                    cout << endl;
                    cout << "�ɹ�ɾ��" << a << "���Ƿ��ڵ�!" << endl;
                    cout << endl;
                    system("pause");
                    cout << endl;
                } else {
                    cout << endl;
                    cout << "�����Ƿ��ڵ�" << endl;
                    cout << endl;
                    system("pause");
                    cout << endl;
                }
        }
    }
    cout << endl;
    cout << "�����˳�ɾ���˵���" << endl;
    cout << endl;
    system("pause");
    cout << endl;
    return (a+b+c);
}

/**
 * @func ɾ����һ���ڵ㣬���ڷǷ��Ľڵ㣬���һ���ڵ�
 * @param head ����ͷָ��
 */
int deleteNoAcNode(struct List *head)
{
    struct List *current,*prev;
    int cnt = 0;
    current=head->next;
    while (current) {
        if (!isAc(current->date.year,current->date.month,current->date.day)) {
            prev->next=current->next;
//            free(current);
            current = prev;
            cnt++;
        }
        prev = current;
        current = current->next;
    }

    return cnt;
}

/**
 * @func ɾ����һ���ڵ�(�����ڱ��ڵ�)
 * @param head
 */
int deleteHead(struct List *head) {
    struct List *current;
    current = head->next;
    head->next = current->next;
    free(current);

    return 1;
}

/**
 * @func ɾ�����һ���ڵ�
 * @param head
 */
int deleteTail(struct List *head) {
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

    return 1;
}

/**
 * @func ��ȡ��ǰ����
 * @return ���ڽṹ
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
 * @func �Ƚ����ڴ�С
 * @param d1 ��һ������
 * @param d2 �ڶ�������
 * @return d1>d2 ����true
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
 * @func ���뵱ǰ���ڳ�Ϊ��һ���ڵ�
 * @param head ����ͷָ��
 */
void insertHead(struct List *head) {
    struct List *node;
    node = (struct List *)malloc(sizeof(struct List));
    node->date = getCurTime();
    node->next = head->next;
    head->next = node;
}

/**
 * @func ���뵱ǰ���ڳ�Ϊ�������һ���ڵ�
 * @param head ����ͷָ��
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
 * @func ���뵽��һ�����ڵ�ǰ���ڵĽڵ�ǰ��
 * @param head ����ͷָ��
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
 * @func ���뵽��һ��С�ڵ�ǰ���ڵĽڵ����
 * @param head ����ͷָ��
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
 * @func ���õ�ǰ���ڹ����һ���½��ӵ���ͷ
 *       ���õ�ǰ���ڹ����һ���½��ӵ���β
 *       ���õ�ǰ���ڹ����һ���½����뵽��һ�����ڸý�����ڵ�ǰ��
 *       ���õ�ǰ���ڹ����һ���½����뵽��һ��С�ڸý�����ڵĺ���
 * @param head
 */
void insertNode(struct List *head) {
    insertHead(head);
    insertTail(head);
    insertPrev(head);
    insertPost(head);
    cout << "�ڵ����ɹ�" << endl;
    system("pause");
    cout << endl;
}

/**
 * @func �����0000-00-00������
 * @param date ����
 * @return ����
 */
int getDays(struct Date date) {
    //���鶨��ÿ���µ����� days_month[0]����
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
 * @func �����1901-01-01������
 * @param date ����
 * @return ����
 */
int getSDays(struct Date date) {
    return (getDays(date) - getDays(cDate));
}

/**
 * @func ��ʾ����ÿ���ڵ�����ں;�1901-01-01������
 * @param head ����ͷָ��
 */
void showListDays(struct List *head) {
    struct List *current;
    for (current = head->next; current ; current = current->next) {
        printf("%04d-%02d-%02d\t��1901-01-01%6d ��\n"
            ,current->date.year,current->date.month,current->date.day,getSDays(current->date));
    }
    system("pause");
    cout << endl;
}

/**
 * @func ����(��С����)�������ڽڵ�
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
 * @func ���ڽڵ�����(��С����)���к����
 * @param head
 */
void printByAsc(struct List *head) {
    sortByAsc(head);
    showAll(head);
    cout << "�ѽ�����ȫ�������ڴ�С��������!" << endl;
    system("pause");
    cout << endl;
}

/**
 * @func ������
 * @param n Ҫ���жϵ���
 * @return �Ƿ�Ϊ����
 */
bool isPrime(int n) {
    int k = int(sqrt(n)) + 1;
    if(n<2)
        return false;
    if(n==2)
        return true;
    if(n%2==0)
        return false;
    for(int i = 3; i <= k ; i++)
    {
        if(n%i==0)
            return true;
    }
    return true;
}

/**
 * @func �ж������Ƿ�Ϊ����
 * @param date ����
 * @return �Ƿ�Ϊ����
 */
bool isPrime(struct Date date) {
    if (isPrime(date.year) && isPrime(date.month) && isPrime(date.day)) {
        return true;
    } else {
        return false;
    }
}

/**
 * @func ��������վ�Ϊ�����Ľڵ�
 * @param head ����ͷָ��
 */
void printPrime(struct List *head) {
    int cnt = 0;
    for (struct List *current = head; current ; current = current->next) {
        if (isPrime(current->date)) {
            cnt++;
            printf(" %04d.%02d.%02d "
                    ,current->date.year,current->date.month,current->date.day);
            if ((!(cnt%5)) && cnt) {
                cout << endl;
            }
        }
    }
    cout << endl;
    system("pause");
    cout << endl;
}

/**
 * @func ��ת����
 * @param head ����ͷָ��
 */
void reverseList(struct List * head) {
    struct List *current,*prev,*post;
    prev = NULL;
    current = head->next;
    post = current->next;
    if (current == NULL || post == NULL)
        return;
    while (post!=NULL) {
        current->next = prev;
        prev = current;
        current = post;
        post = post->next;
    }
    current->next = prev;
    head->next = current;

    cout << "����ת�ɹ�!" << endl;
    system("pause");
    cout << endl;
}

/**
 * @func ����
 */
void clear() {
    system("cls");
    cout << "�����ɹ�" << endl;
    system("pause");
    cout << endl;
}