/**
 * @author 222100209_���׶�
 * @date 2022/2/25
 * @note ���ⶨ����Ҫ�õĳ������Լ�һЩ�ṹ
 */

#ifndef LINKEDLISTDEMO_CONSTANTS_H

#ifndef _NODE_DEFINED
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
#define _NODE_DEFINED
#endif

#ifndef _MENU_DEFINED
//�˵�����
const int MENU_LENGTH_1 = 80;
const int MENU_LENGTH_2 = 50;
//�˵�ѡ��
const char OPTION_1[] = "I,S,F,E,N,D,A,T,O,P,R,C,Q";
const char OPTION_2[] = "F,L,N,Q";
#define _MENU_DEFINED
#endif

#ifndef _FILE_DEFINED_
// �����ļ�����
// �������ڻ�û����
const int MAX_FILENAME = 100;
#define _FILE_DEFINED_
#endif

#ifndef _CDATE_DEINFED_
// ���ڱȽϵ�����
// ���������ڼ����1901-01-01������
const struct Date cDate = {1901,01,01};
#define _CDATE_DEFINED_
#endif

#define LINKEDLISTDEMO_CONSTANTS_H
#endif //LINKEDLISTDEMO_CONSTANTS_H