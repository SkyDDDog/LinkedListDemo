/**
 * @author 222100209_���׶�
 * @date 2022/2/25
 * @note ���ⶨ����Ҫ�õĳ������Լ�һЩ�ṹ
 */

#ifndef LINKEDLISTDEMO_CONSTANTS_H
#define LINKEDLISTDEMO_CONSTANTS_H

// ����ṹ�ڴ˶���
struct Date {
    int year;
    int month;
    int day;
};

struct List {
    struct Date date;
    struct List *next;
};

//�˵�����
const int MENU_LENGTH_1 = 80;
const int MENU_LENGTH_2 = 50;
//�˵�ѡ��
const char OPTION_1[] = "C,S,F,E,N,D,I,T,A,P,R,Q";
const char OPTION_2[] = "F,L,N,Q";
// �����ļ�����
// �������ڻ�û����
const int MAX_FILENAME = 100;
// ���ڱȽϵ�����
// ���������ڼ����1901-01-01������
const struct Date cDate = {1901,01,01};

#endif //LINKEDLISTDEMO_CONSTANTS_H