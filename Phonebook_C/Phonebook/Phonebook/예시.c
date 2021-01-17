#include <stdio.h>
#include <stdlib.h>

//노드 정의
typedef struct node {
	int id;
	struct node* next;		// 다음 노드를 가리키는 포인터
}Node;

Node* start = NULL;
int value = 1;

void insert(void);
void delete(void);
void print(void);
void insert_start(Node* new_node);
void insert_mid(Node* mid, Node* new_node);
void insert_end(Node* end, Node* new_node);
void free_all(void);
void delete_start(void);
void delete_mid(Node *pre_del);
void delete_end(Node* pre_del);

int main(void)
{
	int sel;

	while (1)
	{
		system("cls");
		printf("<메뉴>\n");
		printf("1. insert\n");
		printf("2. delete\n");
		printf("3. print\n");
		printf("4. clear\n");
		printf("0. end\n");
		printf("==============\n");
		scanf("%d", &sel);		//사용자 선택

		switch (sel)
		{
		case 0 :
			free_all();
			return 0;
		case 1:
			insert();
			break;
		case 2:
			delete();
			break;
		case 3:
			print();
			break;
		case 4:
			free_all();
			break;
		default:
			printf("잘못된 입력입니다. \n");
		}
	}
	return 0;
}
void print(void)
{
	Node* cur = NULL;		//현재 노드를 가리키는 포인터(커서)
	
	for (cur = start; cur->next != NULL; cur = cur->next);
	{
		printf("%d -> ", cur->id);
	}
	printf("\n");
	getch();		//사용자 입력 대기(아무키나 누르세요)
}

void insert(void)
{
	Node* cur = NULL;	//현재 노드를 가리키는 포인터(커서)
	Node* new_node = NULL;		//새로 생성된 노드를 가리키는 포인터
	int sel, id;

	if (start == NULL)	//제일 처음 생성하는 노드
	{
		new_node = (Node*)malloc(sizeof(Node));		//노드 생성
		new_node->next = NULL;		//포인터 초기화
		new_node->id = value++;
		start = new_node;		//시작지점으로 설정
	}
	else
	{
		printf("1. 시작지점 insert\n");
		printf("2. 마지막지점 insert\n");
		printf("3. 중간지점 insert\n");
		printf("===============\n");
		scanf("%d", &sel);

		new_node = (Node*)malloc(sizeof(Node));		//노드생성
		new_node->next = NULL; //포인터 초기화
		new_node->id = value++;

		if (sel == 1)		//시작지점에 insert
		{
			insert_start(new_node);
		}
		else if (sel == 2)	//마지막지점에 insert
		{
			//cur가 마지막 노드를 가리키게 함.
			for (cur = start; cur->next != NULL; cur = cur->next);
			insert_end(cur, new_node);
		}
		else if (sel == 3)		//중간지점에 insert
		{
			print();
			printf("어떤 노드 뒤에 insert할지 노드 id를 입력하세요: ");
			scanf("%d", &id);
			//잘못 입력된 id에 대한 예외처리가 필요함

			for (cur = start; cur != NULL; cur = cur->next)
			{
				if (cur->id == id)
					break;
			}
			insert_mid(cur, new_node);
		}
		else // 잘못된 입력
		{
			free(new_node); //메모리 해제
			return 0;
		}
	}
}

//마지막지점 삽입 함수
void insert_end(Node *end, Node *new_node)
{
	end->next = new_node;
}

//시작지점 삽입 함수
void insert_start(Node* new_node)
{
	new_node->next = start;
	start = new_node;		//시작노드 갱신
}

//중간지점 삽입 함수
void insert_mid(Node* mid, Node* new_node)
{
	new_node->next = mid->next;
	mid->next = new_node;
}
