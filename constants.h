/**
 * @author 222100209_���׶�
 * @date 2022/2/25
 */

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

// �����ļ�����
// �������ڻ�û����
const int maxFileName = 100;
const char fileName[] = "test.db";
// ���ڱȽϵ�����
// ���������ڼ����1901-01-01������
const struct Date cDate = {1901,01,01};
