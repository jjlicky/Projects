#include <stdio.h>
#include "Book.h"

void add_number(void);

Book* start = NULL;
int value = 1;
int main(void)
{
	
	int menu;
	printf("Menu1. add new number Menu2. Search name Menu3. Search number\n"); // 첫화면에 메뉴 설명
	while (1)
	{
		scanf("%d\n", &menu); //menu 입력받기
		if (menu == 1)					// switch ~case로 수정하면 더 깔끔
		{
			add_number(); // 1을 입력받으면 전화번호 추가 함수
			break;
		}
		/*else if (menu = 2)			// else if로 나중에 수정할것
		{
			search_name(Pb); // 2를 입력받으면 이름검색 함수
			return Pb;
		}
		else if (menu = 3)
		{
			search_number(Pb); // 3을 입력받으면 전화번호검색 함수
			return Pb;
		}
		else if (menu = 4)
		{
			line_up_name(Pb); // 4를 입력받으면 이름순 정렬 함수
			return Pb;
		}
		else if (menu = 5)
		{
			line_up_birth(Pb); // 5를 입력받으면 생년월일순 정렬 함수
			return Pb;
		}
		else if (menu = 6)
		{
			save_book(Pb); // 6을 입력받으면 전화번호부 저장 함수
			return Pb;
		}
		else if (menu = 7)
		{
			open_book(Pb); // 7을 입력받으면 전화번호부 불러오기 함수
			return Pb;
		}
		else if (menu = 8)
		{
			del_book(Pb); // 8을 입력받으면 전화번호 삭제 함수
			return Pb;
		}
		else if (menu = 9)	//9를 입력받으면 종료
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
