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
Book *start = 0;  // 헤드


// 입력 함수
int input(char* pname, char *ptel, char *pbirth)  // 이름과 전화번호, 생년월일을 입력받음
{
    printf("\n이름 : ");
    scanf("%s", pname);
    printf("\n전화번호 : ");
    scanf("%s", ptel);
    printf("\n생년월일 : ");
    scanf("%s", pbirth);
    return 0;
}


// 추가
void add_number(char* pname, char *ptel, char *pbirth) // 인자로 이름과 전화번호, 생년월일 받음
{
    Book *cur;          // cur노드를 만들어서 cur노드가 헤드를 가리키게함
    Book* new_num;      // 새노드
    cur = start;

    while (cur->next)    // cur노드가 하나씩 다음 노드로 이동 하면서 끝에서 멈춤
        cur = cur->next;
    // 현재 p노드는 노드의 끝

    new_num = (Book*)malloc(sizeof(Book)); // 동적할당으로 새 노드 할당

    strcpy(new_num->name, pname);       // 새노드에 이름복사
    strcpy(new_num->tel, ptel);         // 새노드에 전화번호 복사
    strcpy(new_num->birth, pbirth);     // 새노드에 생년월일 복사
    new_num->next = NULL;               // 새노드다음은 끝을 의미하는 NULL 
    cur->next = new_num;                // 현재 끝을 가리키는 cur노드 다음 새노드에 연결
}



// 출력
void display()
{
   Book* cur;
    cur = start;
    start = start->next;

    while (cur != 0)   // cur노드를 이동시키면서 연결된 노드 전부 출력
    {
        printf("\n이름: %s  전화번호: %s  생년월일: %s", cur->name, cur->tel, cur->birth);
        cur = cur->next;
    }
    printf("\n");
}

void find()
{
    Book* cur;
    char fname[15];     // 찾을 이름을 받을 변수
    printf("찾을 이름 입력 :");
    scanf("%s", fname);
    cur = start;

    while (1)
    {
        if (strcmp(cur->name, fname) == 0)      // cur이 가리키는 name과 입력받은 name 같으면
        {
            printf("이름 : %s, 전화번호 : %s, 생년월일 : %s\n", cur->name, cur->tel, cur->birth);
            return;
        }
        else if (cur->next == NULL)
        {
            printf("일치하는 이름이 없습니다.\n");
            return;
        }
        cur = cur->next;
    }
}

void del()
{
    Book* cur, * temp, * before;
    char dname[20];
    printf("삭제할 이름 : ");
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
            printf("삭제완료");
            return;
        }
        before = cur;
        cur = cur->next;
    }
}
int main()
{
    // 변수
    int menu;   // 메뉴
    char name[15];  // 이름
    char tel[30];  // 번호
    char birth[30]; //생년월일
// 초기화
    start = (Book*)malloc(sizeof(Book));    // start노드(헤드)
    strcpy(start->name, "Jeongwoo");        // start의 멤버가 쓰레기값으로 차있으므로 초기화
    strcpy(start->tel, "010-5295-7430");
    strcpy(start->birth, "94019");
    start->next = NULL;        // start의 다음은 NULL

    while (1)
    {
        printf("\n");
        printf("------------------\n");
        printf("-  1. 삽입       -\n");
        printf("-  2. 삭제       -\n");
        printf("-  3. 검색       -\n");
        printf("-  4. 출력       -\n");
        printf("-  5. 정렬       -\n");
        printf("-  6. 저장       -\n");
        printf("-  7. 불러오기   -\n");
        printf("-  8. 종료       -\n");
        printf("------------------\n");
        printf("선택 : ");
        scanf("%d", &menu);


        switch (menu)
        {
        case 1:  // 삽입
            input(name, tel, birth);
            add_number(name, tel, birth);
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
            /*
        case 5:  // 정렬
            input(name, tel, birth);
            sort(name, tel, birth);
            break;
        case 6:  // 저장
            save();
        case 7:  // 불러오기
            load();
        case 8:  // 종료
            puts("종료합니다.");
            return 0;
        default:
            puts("잘못된 입력!");
            break;
            */
        }
    }

    return 0;
}