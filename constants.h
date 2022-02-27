/**
 * @author 222100209_李炎东
 * @date 2022/2/25
 * @note 在这定义了要用的常量，以及一些结构
 */

#ifndef LINKEDLISTDEMO_CONSTANTS_H
#define LINKEDLISTDEMO_CONSTANTS_H

// 链表结构在此定义
struct Date {
    int year;
    int month;
    int day;
};

struct List {
    struct Date date;
    struct List *next;
};

//菜单长度
const int menuLength = 80;
// 用于文件处理
// 但是现在还没完善
const int maxFileName = 100;
const char fileName[] = "test.db";
// 用于比较的日期
// 这里是用于计算距1901-01-01的天数
const struct Date cDate = {1901,01,01};

#endif //LINKEDLISTDEMO_CONSTANTS_H