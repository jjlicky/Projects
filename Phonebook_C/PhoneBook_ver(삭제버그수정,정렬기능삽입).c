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
Book* start = NULL;  // 헤드


// 추가           // 2021-01-14 삭제시 첫번째 문장이 자동으로 삭제되는 버그가 발생, 원인이 입력을 따로받는것 같아 입력함수 지우고 추가함수에 포함.
void add_number(Book* first)
{
    Book* cur;          // cur노드
    Book* new_num;      // 새노드
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
        first->next = cur;  // 생성한 노드를 첫번째 노드 이후로 연결
        printf(">>>data inserted\n");
        return;
    }

    else
    {
        new_num = first;
        while (1)
        {
            if (new_num->next == NULL)      // 노드 맨 끝에 입력
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



void display(Book* first)
{
    Book* cur;

    if (first->next == NULL)
    {
        printf("Empty\n");
        return;
    }

    cur = first->next;

    while (cur != NULL)   // cur노드를 이동시키면서 연결된 노드 전부 출력
    {
        printf("name : %s | tel : %s | birth : %s\n", cur->name, cur->tel, cur->birth);
        cur = cur->next;
    }
    printf(">>> Display all\n");
    return;
}

void find(Book* first)
{
    Book* cur = first->next;
    char fname[15];     // 찾을 이름을 받을 변수
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

void del(Book* first)
{
    Book* del_num = first->next;
    char dname[15]; //삭제할 이름
    printf("Input name : ");
    scanf("%s", dname);
    if (first->next == NULL)      // 지울 노드가 없다면
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
    Book* cur = (Book*)calloc(1,sizeof(Book));
    
    
    while (!feof(fp))
    {
        Book* loadn = (Book*)calloc(1,sizeof(Book));
        fscanf(fp, "%s %s %s\n", loadn->name, loadn->tel, loadn->birth);
        if (start->next == NULL)
        {
            cur = loadn;
            start->next = cur;
            cur->next = NULL;
            printf("현규 바보 %s\n",start->next->name);     //
        }
        else
        {
            printf("%s\n", cur->name);  //
            cur->next = loadn;
            cur = cur->next;
            cur->next = NULL;
            printf("현규 바보 %s", cur->name);
        }
    }
    cur = start;
    while (cur->next->next != NULL)
    {
        printf("%s\n", cur->name);
        cur = cur->next;
    }
    fclose(fp);
    
    
}

int main()
{

    // 초기화
    start = (Book*)calloc(1,sizeof(Book));    // start노드(헤드)
    start->next = NULL;        // start의 다음은 NULL
    
int menu;
    while (1)
    {
        Book* cur = start; //current노드가 start를 가리킴
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


        switch (menu)
        {
        case 1:  // 삽입
            add_number(start);
            break;
        case 2:  //삭제
            del(start);
            break;
        case 3:  // 검색
            find(start);
            break;

        case 4:  // 출력
            display(start);
            break;
        case 5:  // 정렬
            sort();
            break;
        case 6:  // 저장
            save();
            break;
        case 7:  // 불러오기
            load();
            break;
        case 8:  // 종료
            while (cur->next != NULL)
            {
                cur = start->next;
                cur = cur->next;
                free(cur);
            }
            free(start);
            return 0;
        default:
            puts("잘못된 입력!");
            break;

        }
    }

    return 0;
}