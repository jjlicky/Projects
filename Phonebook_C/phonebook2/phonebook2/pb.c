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
        printf("--------------\n");
        printf("-  1. ����   -\n");
        printf("-  2. ����   -\n");
        printf("-  3. �˻�   -\n");
        printf("-  4. ���   -\n");
        printf("-  5. ����   -\n");
        printf("-  6. ����   -\n");
        printf("--------------\n");
        printf("���� : ");
        scanf("%d", &menu);


        switch (menu)
        {
        case 1:  // ����
            input(name, tel, birth);
            add_number(name, tel, birth);
            break;
/*
        case 2:  //���� 
            del();
            break;
        case 3:  // �˻�
            find();
            break;
            */
        case 4:  // ���
            display();
            break;
            /*
        case 5:  // ����
            input(name, tel, birth);
            sort(name, tel, birth);
            break;
        case 6:  // ����
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