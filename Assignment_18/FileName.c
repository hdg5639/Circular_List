#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
		head = node;		// (3)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

ListNode* delete_first(ListNode* head) {
	if (head == NULL) {
		return NULL;
	}
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (head != NULL) {
		node = head;
		node = head->link;
		head->link = node->link;
	}
	return head;
}

ListNode* delete_last(ListNode* head) {
	if (head == NULL) {
		return NULL;
	}

	ListNode* node = head;
	ListNode* p = NULL;

	while (node->link != head) {
		p = node;
		node = node->link;
	}

	if (p == NULL) { 
		free(node);
		return NULL;
	}
	else {
		p->link = node->link;
		head->data = node->data;
		free(node);
		return head;
	}
}



// 리스트의 항목 출력
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
}

int main(void)
{
	ListNode* head = NULL;
	int select, number;
	while (1) {
		printf("***** Menu *****\n(1) Insert First\n(2) Insert Last\n(3) Delete First\n(4) Delete Last\n(5) Print List\n(0) Exit\n");
		printf("Enter the menu: ");
		scanf("%d", &select);
		switch (select) {
		case 1:
			printf("Input a number: ");
			scanf("%d", &number);
			head = insert_first(head, number);
			printf("\n");
			break;
		case 2:
			printf("Input a number: ");
			scanf("%d", &number);
			head = insert_last(head, number);
			printf("\n");
			break;
		case 3:
			head = delete_first(head);
			printf("First node has been deleted.\n\n");
			break;
		case 4:
			head = delete_last(head);
			printf("Last node has been deleted.\n\n");
			break;
		case 5:
			print_list(head);
			printf("\n\n");
			break;
		case 0:
			printf("Exit the program.\n\n---------------------");
			exit(1);
			break;
		}
	}

	return 0;
}