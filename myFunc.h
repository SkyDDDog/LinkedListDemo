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
