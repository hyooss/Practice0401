#include <stdio.h>
#include <malloc.h>
#define MAX_SIZE 5 // max size를 5로 치환

//자료구조의 구조화

typedef struct listType {
	int data[MAX_SIZE]; // 배열을 사용한 리스트
	int length; // 리스트의 아이템 개수
}listType;

void linear_list_display(listType*list) {
	printf("Linear List = [");
	for (int index = 0; index < list->length; index++) {
		printf("%d", list->data[index]);
		// 인덱스가 마지막이 아니라면 ,를 붙여라
		if (index != list->length - 1)
			printf(", ");
	}
	printf("]\n");
}

void linear_list_insert(listType*list,int pos,int item) {
	int index;

	//리스트가 가득찰 경우
	if (list->length == MAX_SIZE) {
		printf("List Full!!!\n");
		return;
	}

	// 삽입 위치에 대한 예외처리
	if (pos<1 || pos>list->length + 1) {
		printf("Position out of range!!\n");
		return;
	}

	for (index = list->length - 1; index >= pos - 1; index--) {
		list->data[index + 1] = list->data[index];
	}
	list->data[pos - 1] = item;
	list->length++;

}

int linear_list_delete(listType*list,int pos) {
	int index;
	int delitem;

	//리스트가 비어있을때
	if (list->length == 0) {
		printf("List is Empty!!\n");
		return -1; //오류 정보. 우리가 넣을 값은 음수가 아니라고 가정
	}

	//삭제 위치 문제
	if (pos<1 || pos>list->length) {
		printf("Position out of range\n");
		return -1;
	}

	delitem = list->data[pos - 1];
	for (index = pos - 1; index < list->length - 1; index++) {
		list->data[index] = list->data[index + 1];
	}
	list->length--;  // 개수 감수
	return delitem;
}

void linear_list_menu(listType *list) {
	int pos;  // 위치
	int delitem;  // 삭제값
	int item; //삽입할 데이터

	/*
	linear_list_display(data,length);
	linear_list_insert(data, &length,3,30); //맨뒤에 삽입
	linear_list_display(data, length);
	linear_list_insert(data,&length, 1, 40); //맨앞에 삽입
	linear_list_display(data, length);
	linear_list_insert(data, &length, 3, 50); //맨앞에 삽입
	linear_list_display(data, length);


	삭제
	delitem=linear_list_delete(data,&length,5); //마지막 삭제
	printf("Delete Item : %d\n", delitem);
	linear_list_display(data, length);

	delitem = linear_list_delete(data, &length, 1); //첫번째 삭제
	printf("Delete Item : %d\n", delitem);
	linear_list_display(data, length);

	delitem = linear_list_delete(data, &length, 2); //두번째 삭제
	printf("Delete Item : %d\n", delitem);
	linear_list_display(data, length);
	*/

	//메뉴화
	int menu;
	while (1) {
		printf("Linear List: 1.Insert, 2.Delete, 3.Display, 4.Exit\n");
		printf("Input menu: ");
		scanf_s("%d", &menu);
		if (menu == 1) {
			printf("Insert position ? ");
			scanf_s("%d", &pos);
			printf("Insert Item ? ");
			scanf_s("%d", &item);
			linear_list_insert(list, pos, item);
		}
		else if (menu == 2) {
			printf("Delete position ? ");
			scanf_s("%d", &pos);
			delitem = linear_list_delete(list, pos);
			if (delitem >= 0) {
				printf("Delete Item : %d\n", delitem);
			}
		}
		else if (menu == 3) {
			linear_list_display(list);
		}
		else if (menu == 4) {
			printf("Exit\n");
			break;
		}
		else {
			printf("menu error");
		}
	}
}

listType* linear_list_init(void) {
	//동적 메모리 할당
	listType* list = (listType*)malloc(sizeof(listType));
	list->length = 0;
	return list;
}

int main(void) {
	listType* list = linear_list_init();
	linear_list_menu(list);
	free(list);

	/*int data[MAX_SIZE] = { 0 };
	int length = 0;
	// 자료구조의 초기화
	listType list = { data,length };*/

	return 0;
}