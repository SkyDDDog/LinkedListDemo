/**
 * @author 222100209_李炎东
 * @date 2022/2/25
 */

//显示版权信息
void copyRight();
//显示时间
void showTime();
//显示菜单
void menu();
//获取用户选择(集成版权信息，时间，菜单等)
char getChoice();
//创建链表(及其重载方法)
struct List* createList(int n);
struct List* createList();
//创建链表并随机存放日期数据
struct List* initList();
//释放链表
void freeList(struct List * head);
