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
Book* start = NULL;  // ���


// �߰�           // 2021-01-14 ������ ù��° ������ �ڵ����� �����Ǵ� ���װ� �߻�, ������ �Է��� ���ι޴°� ���� �Է��Լ� ����� �߰��Լ��� ����.
void add_number(Book* first)
{
    Book* cur;          // cur���
    Book* new_num;      // �����
    cur = malloc(sizeof(Book));
    cur->next = NULL;
    printf("Input name : ");
    scanf("%s", cur->name);
    printf("Input tel : ");
    scanf("%s", cur->tel);
    printf("Input birth : ");
    scanf("%s", cur->birth);

    if (first->next == NULL)
    {
        first->next = cur;  // ������ ��带 ù��° ��� ���ķ� ����
        printf(">>>data inserted\n");
        return;
    }

    else
    {
        new_num = first;
        while (1)
        {
            if (new_num->next == NULL)      // ��� �� ���� �Է�
            {
                new_num->next = cur;
                printf(">>>data inserted\n");
                return;
            }
            else
                new_num = new_num->next;
        }
    }
}



    // ���
void display(Book * first)
{
        Book* cur;

        if (first->next == NULL)
        {
            printf("Empty\n");
            return;
        }

        cur = first->next;

        while (cur != NULL)   // cur��带 �̵���Ű�鼭 ����� ��� ���� ���
        {
            printf("name : %s | tel : %s | birth : %s\n", cur->name, cur->tel, cur->birth);
            cur = cur->next;
        }
        printf(">>> Display all\n");
        return;
}

void find(Book * first)
{
        Book* cur = first->next;
        char fname[15];     // ã�� �̸��� ���� ����
        printf("Input name :");
        scanf("%s", fname);

        if (cur == NULL)
        {
            printf("Nothing\n");
            return;
        }
        while (1)
        {
            if (strcmp(cur->name, fname) == 0)
            {
                printf("name : %s | tel : %s | birth : %s\n", cur->name, cur->tel, cur->birth);
                printf(">>>Find complete");
                return;
            }
            else if (cur->next == NULL)
            {
                printf("Doesn't exist\n");
                return;
            }
            else
                cur = cur->next;
        }
}

void del(Book * first)
{
        Book* del_num = first->next;
        char dname[15]; //������ �̸�
        printf("Input name : ");
        scanf("%s", dname);
        if (first->next == NULL)      // ���� ��尡 ���ٸ�
        {
            printf("empty\n");
            return;
        }
        while (1)
        {
            if (strcmp(del_num->name, dname) == 0)
            {
                del_num = first->next;
                first->next = del_num->next;
                free(del_num);
                printf(">>>Delete complete");
                return;
            }
            else if (del_num->next == NULL)
            {
                printf("Doesn't exist\n");
                return;
            }
            else
                del_num = del_num->next;
        }
}

void sort()
{
    Book* cur, *temp, *k;
    cur = start;
    while (cur->next != NULL)
    {
        k = cur;
        cur = cur->next;

        if (cur->next != NULL)
        {
            temp = cur->next;
            if (strcmp(cur->name, temp->name) > 0)
            {
                k->next = temp;
                cur->next = temp->next;
                temp->next = cur;
                cur = start;
            }
        }
    }
    printf(">>>Sort complete\n");
}
int main()
{

        // �ʱ�ȭ
        start = (Book*)malloc(sizeof(Book));    // start���(���)
        start->next = NULL;        // start�� ������ NULL
        int menu;
        while (1)
        {
            Book* cur = start; //current��尡 start�� ����Ŵ
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
                add_number(start);
                break;

            case 2:  //����
                del(start);
                break;
            case 3:  // �˻�
                find(start);
                break;

            case 4:  // ���
                display(start);
                break;
                
            case 5:  // ����
                sort(start->name,start->tel,start->birth);
                break;
                /*
            case 6:  // ����
                save();
            case 7:  // �ҷ�����
                load(); 
                */
            case 8:  // ����
                while (cur->next != NULL)
                {
                    cur = start->next;
                    cur = cur->next;
                    free(cur);
                }
                free(start);
                return 0;
            default:
                puts("�߸��� �Է�!");
                break;

            }
        }

        return 0;
}