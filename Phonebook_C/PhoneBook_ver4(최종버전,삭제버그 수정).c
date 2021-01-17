#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��������±�� �߰�, delete ���Ḯ��Ʈ ��ũ���� ����-2021-01-17
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
void insert()
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

    if (start->next == NULL)
    {
        start->next = cur;  // ������ ��带 ù��° ��� ���ķ� ����
        printf(">>>data inserted\n");
        return;
    }

    else
    {
        new_num = start;
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



void display()
{
    Book* cur;

    if (start->next == NULL)
    {
        printf("Empty\n");
        return;
    }

    cur = start->next;

    while (cur != NULL)   // cur��带 �̵���Ű�鼭 ����� ��� ���� ���
    {
        printf("name : %s | tel : %s | birth : %s\n", cur->name, cur->tel, cur->birth);
        cur = cur->next;
    }
    printf(">>> Display all\n");
    return;
}

void find()
{
    Book* cur = start->next;
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

void del()      //��ũ���� ����
{
    Book* cur;
    Book* prev;
    cur = start;
    prev = (Book*)calloc(1, sizeof(Book));
 
    
    char dname[15]; //������ �̸�
    printf("Input name : ");
    scanf("%s", dname);
    
    if (start->next == NULL)      // ���� ��尡 ���ٸ�
    {
        printf("empty\n");
        return;
    }
    while (1)
    {
        prev=cur;
        cur = cur->next;
        
        if (strcmp(cur->name, dname) == 0)
        {
            prev->next = cur->next;
            free(cur);
            
            printf(">>>Delete complete");
            
            break;
        }
        
        else if (cur->next == NULL)
        {
            printf("doesn't exist");
            return;
        }
        
    }
}

void sort()
{
    Book* cur, * temp, * k;
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

void save()
{
    FILE* fp;
    Book* cur;


    fp = fopen("Phonebook.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        return 1;
    }
    cur = start->next;
    while (cur != NULL)
    {
        fprintf(fp, "%10s%10s%10s\n", cur->name, cur->tel, cur->birth);

        cur = cur->next;
    }
    fclose(fp);
    printf(">>> Save complete");
}

void load()
{
    FILE* fp;
    fp = fopen("Phonebook.txt", "r");
    Book* cur = (Book*)calloc(1, sizeof(Book));


    while (!feof(fp))
    {
        Book* loadn = (Book*)calloc(1, sizeof(Book));
        fscanf(fp, "%s %s %s\n", loadn->name, loadn->tel, loadn->birth);
        if (start->next == NULL)
        {
            cur = loadn;
            start->next = cur;
            cur->next = NULL;
        }
        else
        {
            cur->next = loadn;
            cur = cur->next;
            cur->next = NULL;
        }
    }
    cur = start;
    printf(">>>Load complete");
    fclose(fp);


}

int main()
{

    // �ʱ�ȭ
    start = (Book*)calloc(1, sizeof(Book));    // start���(���)
    start->next = NULL;        // start�� ������ NULL

    int menu;
    while (1)
    {
        Book* cur = start; //current��尡 start�� ����Ŵ
        printf("\n");
        printf("---------------------\n");
        printf("-  1. Insert        -\n");
        printf("-  2. Delete        -\n");
        printf("-  3. Find          -\n");
        printf("-  4. Display       -\n");
        printf("-  5. Sort          -\n");
        printf("-  6. Save          -\n");
        printf("-  7. Load          -\n");
        printf("-  8. Quit          -\n");
        printf("---------------------\n");
        printf("Select : ");
        scanf("%d", &menu);


        switch (menu)       // �ʿ伺�� ������ ������ first�Ű���������---2021-01-17
        {
        case 1:  // ����
            insert();
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
        case 5:  // ����
            sort();
            break;
        case 6:  // ����
            save();
            break;
        case 7:  // �ҷ�����
            load();
            break;
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