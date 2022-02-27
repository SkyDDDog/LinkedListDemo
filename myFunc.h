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
//将链表数据存入文件
bool saveInFile(struct List *head);
//判断日期合法性
bool isAc(int year,int month,int day);
//输出不合法日期
void showNotAcDate(struct List *head);
//删除节点
void deleteNode(struct List *head);
//删除第一个节点(不算哨兵节点)
void deleteHead(struct List *head);
//删除最后一个节点
void deleteTail(struct List *head);
//获取当前时间
struct Date getCurTime();
//插入到链头
void insertHead(struct List *head);
//插入到链尾
void insertTail(struct List *head);
//插入到第一个大于当前日期的节点前面
void insertPrev(struct List *head);
//插入到第一个小于当前日期的节点后面
void insertPost(struct List *head);
//插入以上全部节点
void insertNode(struct List *head);
