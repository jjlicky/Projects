#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Phonebook
{
	char name[15];
	char tel[30];
    char birth[30];
	struct Phonebook* next;
};
typedef struct Phonebook Book;
Book *start = 0;  // ���


// �Է� �Լ�
int input(char* pname, char *ptel, char *pbirth)  // �̸��� ��ȭ��ȣ, ��������� �Է¹���
{
    printf("\n�̸� : ");
    scanf("%s", pname);
    printf("\n��ȭ��ȣ : ");
    scanf("%s", ptel);
    printf("\n������� : ");
    scanf("%s", pbirth);
    return 0;
}


// �߰�
void add_number(char* pname, char *ptel, char *pbirth) // ���ڷ� �̸��� ��ȭ��ȣ, ������� ����
{
    Book *cur;          // cur��带 ���� cur��尡 ��带 ����Ű����
    Book* new_num;      // �����
    cur = start;

    while (cur->next)    // cur��尡 �ϳ��� ���� ���� �̵� �ϸ鼭 ������ ����
        cur = cur->next;
    // ���� p���� ����� ��

    new_num = (Book*)malloc(sizeof(Book)); // �����Ҵ����� �� ��� �Ҵ�

    strcpy(new_num->name, pname);       // ����忡 �̸�����
    strcpy(new_num->tel, ptel);         // ����忡 ��ȭ��ȣ ����
    strcpy(new_num->birth, pbirth);     // ����忡 ������� ����
    new_num->next = NULL;               // ���������� ���� �ǹ��ϴ� NULL 
    cur->next = new_num;                // ���� ���� ����Ű�� cur��� ���� ����忡 ����
}



// ���
void display()
{
   Book* cur;
    cur = start;
    start = start->next;

    while (cur != 0)   // cur��带 �̵���Ű�鼭 ����� ��� ���� ���
    {
        printf("\n�̸�: %s  ��ȭ��ȣ: %s  �������: %s", cur->name, cur->tel, cur->birth);
        cur = cur->next;
    }
    printf("\n");
}

void find()
{
    Book* cur;
    char fname[15];     // ã�� �̸��� ���� ����
    printf("ã�� �̸� �Է� :");
    scanf("%s", fname);
    cur = start;

    while (1)
    {
        if (strcmp(cur->name, fname) == 0)      // cur�� ����Ű�� name�� �Է¹��� name ������
        {
            printf("�̸� : %s, ��ȭ��ȣ : %s, ������� : %s\n", cur->name, cur->tel, cur->birth);
            return;
        }
        else if (cur->next == NULL)
        {
            printf("��ġ�ϴ� �̸��� �����ϴ�.\n");
            return;
        }
        cur = cur->next;
    }
}

void del()
{
    Book* cur, * temp, * before;
    char dname[20];
    printf("������ �̸� : ");
    scanf("%s", dname);
    cur = start;
    cur = cur->next;
    before = start;
    while (cur != 0)
    {
        if (strcmp(cur->name, dname) == 0)
        {
            temp = cur;
            before->next = cur->next;
            cur = before;
            free(temp);
            printf("�����Ϸ�");
            return;
        }
        before = cur;
        cur = cur->next;
    }
}
int main()
{
    // ����
    int menu;   // �޴�
    char name[15];  // �̸�
    char tel[30];  // ��ȣ
    char birth[30]; //�������
// �ʱ�ȭ
    start = (Book*)malloc(sizeof(Book));    // start���(���)
    strcpy(start->name, "Jeongwoo");        // start�� ����� �����Ⱚ���� �������Ƿ� �ʱ�ȭ
    strcpy(start->tel, "010-5295-7430");
    strcpy(start->birth, "94019");
    start->next = NULL;        // start�� ������ NULL

    while (1)
    {
        printf("\n");
        printf("------------------\n");
        printf("-  1. ����       -\n");
        printf("-  2. ����       -\n");
        printf("-  3. �˻�       -\n");
        printf("-  4. ���       -\n");
        printf("-  5. ����       -\n");
        printf("-  6. ����       -\n");
        printf("-  7. �ҷ�����   -\n");
        printf("-  8. ����       -\n");
        printf("------------------\n");
        printf("���� : ");
        scanf("%d", &menu);


        switch (menu)
        {
        case 1:  // ����
            input(name, tel, birth);
            add_number(name, tel, birth);
            break;
            
        case 2:  //����
            del();
            break;
        case 3:  // �˻�
            find();
            break;
                        
        case 4:  // ���
            display();
            break;
            /*
        case 5:  // ����
            input(name, tel, birth);
            sort(name, tel, birth);
            break;
        case 6:  // ����
            save();
        case 7:  // �ҷ�����
            load();
        case 8:  // ����
            puts("�����մϴ�.");
            return 0;
        default:
            puts("�߸��� �Է�!");
            break;
            */
        }
    }

    return 0;
}