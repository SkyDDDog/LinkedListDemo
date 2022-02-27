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
const int menuLength = 80;
// �����ļ�����
// �������ڻ�û����
const int maxFileName = 100;
const char fileName[] = "test.db";
// ���ڱȽϵ�����
// ���������ڼ����1901-01-01������
const struct Date cDate = {1901,01,01};

#endif //LINKEDLISTDEMO_CONSTANTS_H