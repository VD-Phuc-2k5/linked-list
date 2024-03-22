#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct SNode
{
	int info;
	SNode *next;
} node ;
typedef struct SList
{
	node* head;
	node* tail;
} list;

/*The location of declared functions */
//check
int isEmpty(list l);
//create
void initSList(list &l);
node* createNode(int x);
void createLinkedList(list &l, int len);
// input
node* inputNode();
// output
void showNode(node *p);
void showSList(list l);

/*The location of process functions*/
bool match(int x, list &l1, list l2);
/*Menu function*/
void process();

int main()
{
	process();
	system("pause");
	return 0;
}


void process() {
	list list1, list2;
	initSList(list1);
	initSList(list2);
	createLinkedList(list1, 5);
	createLinkedList(list2, 5);
	match(4, list1, list2);
	showSList(list1);
}

int isEmpty(list l){return l.head == NULL;}
void initSList(list &l){
	l.head = NULL;
	l.tail = NULL;
}
node* inputNode()
{
	int temp;
	scanf_s("%d", &temp);
	return createNode(temp);
}
node* createNode(int x){
	node *p = new node;
	if (p == NULL) return NULL;
	p->info = x;
	p->next = NULL;
	return p;
}
void createLinkedList(list &l, int len)
{
	while(len)
	{
		node* node = inputNode();
		if (isEmpty(l))
			l.head = node;
		else
			l.tail->next = node;
		l.tail = node;
		--len;
	}
}
void showNode(node *p){
	printf("%4d", p->info);
}
void showSList(list l){
	if (isEmpty(l)){
		printf("Danh sach rong!");
		return;
	}
	else
	{
		node *p = l.head;
		while (p){
			showNode(p);
			p = p->next;
		}
	}
	printf("\n");
}
bool match(int x, list &l1, list l2)
{
	node* temp_node = l1.head;
	while (temp_node->info != x && temp_node->next != NULL)
		temp_node = temp_node->next;
	if (temp_node->next == NULL && temp_node->info != x)
		return false;
	else
	{
		l2.tail->next = temp_node->next;
		temp_node->next = l2.head;
		return true;
	}
}
