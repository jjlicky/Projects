#include <stdio.h>
#include "Book.h"

void add_number(void);

Book* start = NULL;
int value = 1;
int main(void)
{
	
	int menu;
	printf("Menu1. add new number Menu2. Search name Menu3. Search number\n"); // ùȭ�鿡 �޴� ����
	while (1)
	{
		scanf("%d\n", &menu); //menu �Է¹ޱ�
		if (menu == 1)					// switch ~case�� �����ϸ� �� ���
		{
			add_number(); // 1�� �Է¹����� ��ȭ��ȣ �߰� �Լ�
			break;
		}
		/*else if (menu = 2)			// else if�� ���߿� �����Ұ�
		{
			search_name(Pb); // 2�� �Է¹����� �̸��˻� �Լ�
			return Pb;
		}
		else if (menu = 3)
		{
			search_number(Pb); // 3�� �Է¹����� ��ȭ��ȣ�˻� �Լ�
			return Pb;
		}
		else if (menu = 4)
		{
			line_up_name(Pb); // 4�� �Է¹����� �̸��� ���� �Լ�
			return Pb;
		}
		else if (menu = 5)
		{
			line_up_birth(Pb); // 5�� �Է¹����� ������ϼ� ���� �Լ�
			return Pb;
		}
		else if (menu = 6)
		{
			save_book(Pb); // 6�� �Է¹����� ��ȭ��ȣ�� ���� �Լ�
			return Pb;
		}
		else if (menu = 7)
		{
			open_book(Pb); // 7�� �Է¹����� ��ȭ��ȣ�� �ҷ����� �Լ�
			return Pb;
		}
		else if (menu = 8)
		{
			del_book(Pb); // 8�� �Է¹����� ��ȭ��ȣ ���� �Լ�
			return Pb;
		}
		else if (menu = 9)	//9�� �Է¹����� ����
		{
			break;
		}
		else continue; */
	}
	Book* cur = NULL;
	for (cur = start; cur->next != NULL; cur = cur->next);
	{
		printf("%s %s %d\n", cur->name, cur->tel, cur->birth);
	}
	printf("\n");
	getch();
	return 0;
}
