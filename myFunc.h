/**
 * @author 222100209_���׶�
 * @date 2022/2/25
 */

//��ʾ��Ȩ��Ϣ
void copyRight();
//��ʾʱ��
void showTime();
//��ʾ�˵�
void menu();
//��ȡ�û�ѡ��(���ɰ�Ȩ��Ϣ��ʱ�䣬�˵���)
char getChoice();
//��������(�������ط���)�����������������
struct List* createList(int n);
struct List* createList();
//�ͷ�����
void freeList(struct List * head);
//���������������
void showAll(struct List *head);
//�����������(�������ط���)
void showList(struct List *head,int n);
void showList(struct List *head);
//���������ݴ����ļ�
bool saveInFile(struct List *head);
//�ж����ںϷ���
bool isAc(int year,int month,int day);
//������Ϸ�����
void showNotAcDate(struct List *head);
//ɾ���ڵ�
void deleteNode(struct List *head);
//ɾ����һ���ڵ�(�����ڱ��ڵ�)
void deleteHead(struct List *head);
//ɾ�����һ���ڵ�
void deleteTail(struct List *head);
//��ȡ��ǰʱ��
struct Date getCurTime();
//���뵽��ͷ
void insertHead(struct List *head);
//���뵽��β
void insertTail(struct List *head);
//���뵽��һ�����ڵ�ǰ���ڵĽڵ�ǰ��
void insertPrev(struct List *head);
//���뵽��һ��С�ڵ�ǰ���ڵĽڵ����
void insertPost(struct List *head);
//��������ȫ���ڵ�
void insertNode(struct List *head);
