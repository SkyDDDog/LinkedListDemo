/**
 * @author 222100209_���׶�
 * @version 1.0
 * @date 2022/2/25
 * @note ����Ŀ��github(https://github.com/SkyDDDog/LinkedListDemo.git)�����йܱ���
 * A LinkedList Demo
 *  1)��ʾ��Ȩ(Copyright)��Ϣ,��ʾ(ϵͳ)��ǰ������,��ʾ�û�(����)ѡ��˵�
 *  2)����û���(����)ѡ��
 *  3)��ʼ��(��)���������ڱ���㣩���ͷ�����
 *  4)��û�С����� (����)����֮ǰ��ѡ��ʹ�������󲿷ֹ���
 *  5)���� (����)���������Ҳ�������û����룩
 *  6)��������ǰn����㣨�����n���Զ���Ϊ���������û����룬n=0�����������
 *  7)�������������ݴ���һ���ļ��У��ļ��е�ȻҲ�������û����룩
 *  8)(���������к�)��ʾ���������ļ���(ȫ��)����
 *  9)��ʾ�����У����ܹ��ɺϷ����ڵĽ��
 *  10)ɾ������ĵ�һ����㣻ɾ����������һ����㣻ɾ�������в��ܹ��ɺϷ����ڵĽ�㣨��Ȼ�����ö����˵�ʵ�־͸�Ϊ����
 *  11)���õ�ǰ���ڹ����һ���½��ӵ���ͷ��
 *      ���õ�ǰ���ڹ����һ���½��ӵ���β��
 *      ���õ�ǰ���ڹ����һ���½����뵽��һ�����ڸý�����ڵ�ǰ�棻
 *      ���õ�ǰ���ڹ����һ���½����뵽��һ��С�ڸý�����ڵĺ���
 *  12)��ʾ����ÿ���������ھ���xxxx��1��1�յ�����
 *  13)�������ڴ�С�����������
 *  14)ͳ�Ʋ���������ն��������Ľ��
 *  15)����ת(�������µı���ʵ��)
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
    //��ʼ������
    List *head = (List *) malloc(sizeof(List));
    //�û���ѡ��
    char choice;
    while ((choice=getChoice())!='Q') {
        if (choice!='C' && head->next==NULL) {
            cout << "\a\n����Ϊ��!���ȴ�������!\n" << endl;
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

