#include <stdio.h>
#include <stdlib.h>

//��� ����
typedef struct node {
	int id;
	struct node* next;		// ���� ��带 ����Ű�� ������
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
		printf("<�޴�>\n");
		printf("1. insert\n");
		printf("2. delete\n");
		printf("3. print\n");
		printf("4. clear\n");
		printf("0. end\n");
		printf("==============\n");
		scanf("%d", &sel);		//����� ����

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
			printf("�߸��� �Է��Դϴ�. \n");
		}
	}
	return 0;
}
void print(void)
{
	Node* cur = NULL;		//���� ��带 ����Ű�� ������(Ŀ��)
	
	for (cur = start; cur->next != NULL; cur = cur->next);
	{
		printf("%d -> ", cur->id);
	}
	printf("\n");
	getch();		//����� �Է� ���(�ƹ�Ű�� ��������)
}

void insert(void)
{
	Node* cur = NULL;	//���� ��带 ����Ű�� ������(Ŀ��)
	Node* new_node = NULL;		//���� ������ ��带 ����Ű�� ������
	int sel, id;

	if (start == NULL)	//���� ó�� �����ϴ� ���
	{
		new_node = (Node*)malloc(sizeof(Node));		//��� ����
		new_node->next = NULL;		//������ �ʱ�ȭ
		new_node->id = value++;
		start = new_node;		//������������ ����
	}
	else
	{
		printf("1. �������� insert\n");
		printf("2. ���������� insert\n");
		printf("3. �߰����� insert\n");
		printf("===============\n");
		scanf("%d", &sel);

		new_node = (Node*)malloc(sizeof(Node));		//������
		new_node->next = NULL; //������ �ʱ�ȭ
		new_node->id = value++;

		if (sel == 1)		//���������� insert
		{
			insert_start(new_node);
		}
		else if (sel == 2)	//������������ insert
		{
			//cur�� ������ ��带 ����Ű�� ��.
			for (cur = start; cur->next != NULL; cur = cur->next);
			insert_end(cur, new_node);
		}
		else if (sel == 3)		//�߰������� insert
		{
			print();
			printf("� ��� �ڿ� insert���� ��� id�� �Է��ϼ���: ");
			scanf("%d", &id);
			//�߸� �Էµ� id�� ���� ����ó���� �ʿ���

			for (cur = start; cur != NULL; cur = cur->next)
			{
				if (cur->id == id)
					break;
			}
			insert_mid(cur, new_node);
		}
		else // �߸��� �Է�
		{
			free(new_node); //�޸� ����
			return 0;
		}
	}
}

//���������� ���� �Լ�
void insert_end(Node *end, Node *new_node)
{
	end->next = new_node;
}

//�������� ���� �Լ�
void insert_start(Node* new_node)
{
	new_node->next = start;
	start = new_node;		//���۳�� ����
}

//�߰����� ���� �Լ�
void insert_mid(Node* mid, Node* new_node)
{
	new_node->next = mid->next;
	mid->next = new_node;
}
