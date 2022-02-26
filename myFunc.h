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
//创建链表(及其重载方法)并随机产生日期数据
struct List* createList(int n);
struct List* createList();
//释放链表
void freeList(struct List * head);
//输出所有链表数据
void showAll(struct List *head);
//输出链表数据(及其重载方法)
void showList(struct List *head,int n);
void showList(struct List *head);
