#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ItemType;
struct SNode
{
	ItemType info;
	SNode *next;
};
typedef SNode node;
struct SList
{
	node* head;
	node* tail;
};
typedef SList list;
/*The location of declared functions */
node* createNode(ItemType x);
void showNode(node *p);
void initSList(list &l);
int isEmpty(list l);
void showSList(list l);
void createLinkedList(int value, list &l);
/*The location of process functions*/
int insertHead(list &l, node *p);
void createListByHand(list &l);
void createListRandom(list &l);
void swap(node* curr, node* next);
void sortDescending(list &l);
void sortAscending(list &l);
bool isAscending(list l);
bool isDescending(list l);
void addElementAtSortedLL(int value, list &l);
bool isExist(int value, list l);
bool match(int x, list &l, list sl2);
/*Menu function*/
void menu();
void process();
/*Main function*/
int main(){
	process();
	return 0;
}

void menu(){
	printf("\n***************************************************************");
	printf("\n*                          MENU                               *");
	printf("\n***************************************************************");
	printf("\n*0. EXIT                                                      *");
	printf("\n*1. CREATE SINGLE NODE                                        *");
	printf("\n*2. CREATE LINKED LIST BY HANDMADE                            *");
	printf("\n*3. CREATE LINKED LIST USING RANDOM FUNCTION                  *");
	printf("\n*4. SHOW LINKED LIST                                          *");
	printf("\n*5. SORT ASCENDING LINKED LIST                                *");
	printf("\n*6. SORT DESCENDING LINKED LIST                               *");
	printf("\n*7. CHECK LINKED LIST IS ASCENDING?                           *");
	printf("\n*8. CHECK LINKED LIST IS DESCENDING?                          *");
	printf("\n*9. INSERT ELEMENT AT SORTED LIST                             *");
	printf("\n*10. MATCH SL2 WITH SL1                                       *");
	printf("\n*11. CLEAR DATA                                               *");
	printf("\n***************************************************************");
}

void process(){
	ItemType select, value, element, k;
	node *p;
	list l, sl2;

	initSList(l);

	do{
		menu();
		printf("\nPlease enter your choice: ");
		scanf("%d", &select);
		switch (select)
		{
		case 0:
			break;
		case 1:
			printf("Please get value of new node: ");
			scanf("%d", &value);
			p = createNode(value);
			if (insertHead(l, p))
			{
				printf("The content of new node: ");
				showSList(l);
			}
			break;
		case 2:
			createListByHand(l);
			printf("\nThe content of linked list: ");
			showSList(l);
			break;
		case 3:
			createListRandom(l);
			printf("\nThe content of linked list: ");
			showSList(l);
			break;
		case 4:
			printf("\nThe content of linked list: ");
			showSList(l);
			break;
		case 5:
			sortAscending(l);
			printf("\nThe content of linked list after sort ascending: ");
			showSList(l);
			break;
		case 6:
			sortDescending(l);
			printf("\nThe content of linked list after sort descending: ");
			showSList(l);
			break;
		case 7:
			if (isAscending(l)){
				printf("Situation: Sorted!");
			}
			else
			{
				printf("Situation: Not sorted!");
			}
			break;
		case 8:
			if (isDescending(l)){
				printf("Situation: Sorted!");
			}
			else
			{
				printf("Situation: Not sorted!");
			}
			break;
		case 9:
			if (isAscending(l)){
				printf("Please get value of new node: ");
				scanf("%d", &element);
				addElementAtSortedLL(element, l);
				printf("\nThe content of linked list after add: ");
				showSList(l);
			}
			else{
				printf("\nThe linked list are not sorted!");
			}
			break;
		case 10:
			printf("\nLet's create SL2!");
			createListRandom(sl2);
			printf("\nThe content of SL2: ");
			showSList(sl2);
			printf("\nThe value wanna find: ");
			scanf("%d", &k);
			if (match(k, l, sl2) == false){
				printf("\nElement does not exist!");
			}
			else{
				printf("\nThe content of list after match.");
				showSList(l);
			}
			break;
		case 11:
			initSList(l);
			printf("\nThe linked list has been removed!");
			break;
		default:
			printf("\nError!");
			break;
		}
	} while (select != 0);
}

node* createNode(ItemType x){
	node *p = new node;
	if (p == NULL)
	{
		printf("Khong the cap phat");
		getch();
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void showNode(node *p){
	printf("%4d", p->info);
}

void initSList(list &l){
	l.head = NULL;
	l.tail = NULL;
}

int isEmpty(list l){
	if (l.head == NULL)
		return 1;
	return 0;
}
void showSList(list l){
	if (isEmpty(l)){
		printf("Danh sach rong!");
		return;
	}
	node *p = l.head;
	while (p){
		showNode(p);
		p = p->next;
	}
}

int insertHead(list &l, node *p){
	if (p == NULL){
		return 0;
	}
	if (isEmpty(l))
	{
		l.head = p;
		l.tail = p;
	}
	else{
		p->next = l.head;
		l.head = p;
	}
	return 1;
}

void createLinkedList(int value, list &l){
	node* node = createNode(value);
	if (isEmpty(l)) {
		l.head = node;
		l.tail = node;
	}
	l.tail->next = node;
	l.tail = node;
}

void createListByHand(list &l){
	ItemType length;
	do{
		printf("\nInput the length of linked list (length >=0): ");
		scanf("%d", &length);
	} while (length <= 0);

	for (int i = 0; i < length; i++)
	{
		ItemType value;
		printf("\nInput node: ");
		scanf("%d", &value);
		node *p = createNode(value);
		if (insertHead(l, p) == 0) continue;
	}
}

void createListRandom(list &l){
	ItemType length;
	do{
		printf("\nInput the length of linked list (length >=0): ");
		scanf("%d", &length);
	} while (length <= 0);
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		ItemType value;
		value = (rand() % 199) + 1;
		node *p = createNode(value);
		if (insertHead(l, p) == 0) continue;
	}
}
void swap(node *curr, node *next){
	int temp = curr->info;
	curr->info = next->info;
	next->info = temp;
}

void sortDescending(list &l){
	bool isSorted = false;
	while (!isSorted){
		isSorted = true;
		node *head = l.head;
		while (head->next)
		{
			if (head->next->info > head->info){
				isSorted = false;
				swap(head, head->next);
			}
			head = head->next;
		}
	}
}

void sortAscending(list &l){
	bool isSorted = false;
	while (!isSorted){
		isSorted = true;
		node *head = l.head;
		while (head->next)
		{
			if (head->next->info < head->info){
				isSorted = false;
				swap(head, head->next);
			}
			head = head->next;
		}
	}
}

bool isAscending(list l){
	node *head = l.head;

	if (isEmpty(l)) return true;
	while (head->next){
		if (head->next->info < head->info)
			return false;
		head = head->next;
	}
	return true;
}

bool isDescending(list l){
	node *head = l.head;

	if (isEmpty(l)) return true;
	while (head->next){
		if (head->next->info > head->info)
			return false;
		head = head->next;
	}
	return true;
}

void addElementAtSortedLL(int value, list &l){
	node* head = l.head;
	node* tail = l.tail;
	node* p = createNode(value);

	if (head->info >= value){
		p->next = head;
		l.head = p;
		return;
	}
	if (tail->info <= value){
		tail->next = p;
		l.tail = p;
		return;
	}
	while (head->next->info < value && head->next->next != NULL){
		head = head->next;
	}
	p->next = head->next;
	head->next = p;
}


bool match(int x, list &l, list sl2)
{
	node* temp_node = l.head;
	while (temp_node->info != x && temp_node->next != NULL)
		temp_node = temp_node->next;
	if (temp_node->next == NULL && temp_node->info != x)
		return false;
	else
	{
		sl2.tail->next = temp_node->next;
		temp_node->next = sl2.head;
		return true;
	}
}
