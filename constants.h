/**
 * @author 222100209_李炎东
 * @date 2022/2/25
 * @note 在这定义了要用的常量，以及一些结构
 */

#ifndef LINKEDLISTDEMO_CONSTANTS_H

#ifndef _NODE_DEFINED
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
#define _NODE_DEFINED
#endif

#ifndef _MENU_DEFINED
//菜单长度
const int MENU_LENGTH_1 = 80;
const int MENU_LENGTH_2 = 50;
//菜单选项
const char OPTION_1[] = "I,S,F,E,N,D,A,T,O,P,R,C,Q";
const char OPTION_2[] = "F,L,N,Q";
#define _MENU_DEFINED
#endif

#ifndef _FILE_DEFINED_
// 用于文件处理
// 但是现在还没完善
const int MAX_FILENAME = 100;
#define _FILE_DEFINED_
#endif

#ifndef _CDATE_DEINFED_
// 用于比较的日期
// 这里是用于计算距1901-01-01的天数
const struct Date cDate = {1901,01,01};
#define _CDATE_DEFINED_
#endif

#define LINKEDLISTDEMO_CONSTANTS_H
#endif //LINKEDLISTDEMO_CONSTANTS_H