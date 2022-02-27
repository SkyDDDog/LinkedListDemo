/**
 * @author 222100209_���׶�
 * @version 1.0
 * @date 2022/2/25
 * @note ����Ŀ��github(https://github.com/SkyDDDog/LinkedListDemo.git)�����йܱ���
 *       (������ȫ���õ��ĳ�Ϯ����github�Ͽ��Կ�����һ��һ���ύ����Ĺ���)
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

int main() {
    //��ʼ������
    List *head = (List *) malloc(sizeof(List));
    //�û���ѡ��
    char choice;
    while ((choice=getChoice())!='Q') {
        if (choice!='C' && head->next==NULL) {
            cout << "\a\n����Ϊ��!���ȴ�������!\n" << endl;
            system("pause");
            cout << endl;
            continue;
        }
        switch (choice) {
            // Create
            case 'C':
                head = createList();
                break;
            // Show
            case 'S':
                showList(head);
                break;
            // FIle
            case 'F':
                saveInFile(head);
                break;
            // Every
            case 'E':
                showAll(head);
                break;
            // Not legal
            case 'N':
                showNotAcDate(head);
                break;
            // Delete
            case 'D':
                deleteNode(head);
                break;
            // Insert
            case 'I':
                insertNode(head);
                break;
            // Time
            case 'T':
                showListDays(head);
                break;
            // Asc
            case 'A':
                printByAsc(head);
                break;
            // Prime
            case 'P':
                printPrime(head);
                break;
            // Reverse
            case 'R':
                reverseList(head);
                break;
            default:
                cout << "û�����ѡ�������ѡ��!" << endl;
                system("pause");
                cout << endl;
                break;
        }
    }
    freeList(head);
    cout << "�����ͷųɹ�!��л����ʹ��!" << endl;
    system("pause");
    return 0;
}

