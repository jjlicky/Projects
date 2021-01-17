#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//파일입출력기능 추가, delete 연결리스트 링크오류 수정-2021-01-17
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
void insert()
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

    if (start->next == NULL)
    {
        start->next = cur;  // 생성한 노드를 첫번째 노드 이후로 연결
        printf(">>>data inserted\n");
        return;
    }

    else
    {
        new_num = start;
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



void display()
{
    Book* cur;

    if (start->next == NULL)
    {
        printf("Empty\n");
        return;
    }

    cur = start->next;

    while (cur != NULL)   // cur노드를 이동시키면서 연결된 노드 전부 출력
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

void del()      //링크오류 수정
{
    Book* cur;
    Book* prev;
    cur = start;
    prev = (Book*)calloc(1, sizeof(Book));
 
    
    char dname[15]; //삭제할 이름
    printf("Input name : ");
    scanf("%s", dname);
    
    if (start->next == NULL)      // 지울 노드가 없다면
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

    // 초기화
    start = (Book*)calloc(1, sizeof(Book));    // start노드(헤드)
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


        switch (menu)       // 필요성이 떨어져 기존의 first매개변수삭제---2021-01-17
        {
        case 1:  // 삽입
            insert();
            break;
        case 2:  //삭제
            del();
            break;
        case 3:  // 검색
            find();
            break;

        case 4:  // 출력
            display();
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