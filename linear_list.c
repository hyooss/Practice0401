#include <stdio.h>
#include <malloc.h>
#define MAX_SIZE 5 // max size�� 5�� ġȯ

//�ڷᱸ���� ����ȭ

typedef struct listType {
	int data[MAX_SIZE]; // �迭�� ����� ����Ʈ
	int length; // ����Ʈ�� ������ ����
}listType;

void linear_list_display(listType*list) {
	printf("Linear List = [");
	for (int index = 0; index < list->length; index++) {
		printf("%d", list->data[index]);
		// �ε����� �������� �ƴ϶�� ,�� �ٿ���
		if (index != list->length - 1)
			printf(", ");
	}
	printf("]\n");
}

void linear_list_insert(listType*list,int pos,int item) {
	int index;

	//����Ʈ�� ������ ���
	if (list->length == MAX_SIZE) {
		printf("List Full!!!\n");
		return;
	}

	// ���� ��ġ�� ���� ����ó��
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

	//����Ʈ�� ���������
	if (list->length == 0) {
		printf("List is Empty!!\n");
		return -1; //���� ����. �츮�� ���� ���� ������ �ƴ϶�� ����
	}

	//���� ��ġ ����
	if (pos<1 || pos>list->length) {
		printf("Position out of range\n");
		return -1;
	}

	delitem = list->data[pos - 1];
	for (index = pos - 1; index < list->length - 1; index++) {
		list->data[index] = list->data[index + 1];
	}
	list->length--;  // ���� ����
	return delitem;
}

void linear_list_menu(listType *list) {
	int pos;  // ��ġ
	int delitem;  // ������
	int item; //������ ������

	/*
	linear_list_display(data,length);
	linear_list_insert(data, &length,3,30); //�ǵڿ� ����
	linear_list_display(data, length);
	linear_list_insert(data,&length, 1, 40); //�Ǿտ� ����
	linear_list_display(data, length);
	linear_list_insert(data, &length, 3, 50); //�Ǿտ� ����
	linear_list_display(data, length);


	����
	delitem=linear_list_delete(data,&length,5); //������ ����
	printf("Delete Item : %d\n", delitem);
	linear_list_display(data, length);

	delitem = linear_list_delete(data, &length, 1); //ù��° ����
	printf("Delete Item : %d\n", delitem);
	linear_list_display(data, length);

	delitem = linear_list_delete(data, &length, 2); //�ι�° ����
	printf("Delete Item : %d\n", delitem);
	linear_list_display(data, length);
	*/

	//�޴�ȭ
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
	//���� �޸� �Ҵ�
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
	// �ڷᱸ���� �ʱ�ȭ
	listType list = { data,length };*/

	return 0;
}