#include <iostream>
#include <stdlib.h>
#include <string.h>

struct Node
{
	int data;
	Node* next;
};
struct List 
{
	Node *head, *tail;
};

class linked_list 
{
private: int size;
public:
	linked_list(int len) {size = len;}
	void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	// check
	bool isEmpty(List l) {return l.head == NULL;}
	bool isAscendingOrDescending(List l, char type)
	{
		if(isEmpty(l)) return false;
		while (l.head->next)
		{
			if (type == 'a' && l.head->data > l.head->next->data)
				return false;
			if (type == 'd' && l.head->data < l.head->next->data)
				return false;
			l.head = l.head->next;
		}
		return true;
	}
	//input
	Node* inputNode()
	{
		int temp;
		std::cin >> temp;
		return createNode(temp);
	}
	//output
	void printNode(Node* node) {std::cout << node->data << ' ';}
	void printLinkedList(List l)
	{
		if (isEmpty(l)) 
			std::cout << "Linked List is Empty!\n";
		else
		{
			while(l.head)
			{
				printNode(l.head);
				l.head = l.head->next;
			}
		}
	}
	// create
	List creatList()
	{
		List l;
		l.head = NULL;
		l.tail = NULL;
		return l;
	}
	Node* createNode(int value)
	{
		Node* node = new Node;
		if (node == NULL) return NULL;
		node->data = value;
		node->next = NULL;
		return node;
	}
	void createLinkedList(List &l)
	{
		int length = size;
		while(length)
		{
			Node* temp = inputNode();
			if (isEmpty(l))
				l.head = temp;
			else
				l.tail->next = temp;
			l.tail = temp;
			--length;
		}
	}
	// insert
	void insertHead(List &l, int value)
	{
		Node* node = createNode(value);
		if (isEmpty(l)) 
			l.tail = node;
		else
			node->next = l.head;
		l.head = node;
	}
	void insertTail(List &l, int value)
	{
		Node* node = createNode(value);
		if (isEmpty(l)) 
			l.head = node;
		else
			l.tail->next = node;
		l.tail = node;
	}
	void insertAfter(List &l, Node* current, int value)
	{
		Node* node = createNode(value);
		if (current == NULL || isEmpty(l)) return;
		if (current->next = NULL) insertTail(l, value);
		else
		{
			node->next = current->next;
			current->next = node;
		}
	}
	// delete
	int deleteHead(List &l)
	{
		if (isEmpty(l)) return NULL;
		Node* temp = l.head;
		l.head = l.head->next;
		int value = temp->data;
		delete temp;
		return value;
	}
	int deleteAfter(List &l, Node* current)
	{
		if (isEmpty(l) || current == NULL) return NULL;
		Node* next_next = current->next->next;
		int value = current->next->data;
		delete current->next;
		current->next = next_next;
		return value;
	}
	void deleteMaxOrMin(List &l, char* type)
	{
		if (isEmpty(l)) return;
		Node *next_next, *current = l.head;
		if (!strcmp(type, "max"))
			int value = findMaxOrMin(l, type);
		int value = findMaxOrMin(l, type);
		while (current->next)
		{
			if(current->next->data == value)
				deleteAfter(l, current);
			else
				current = current->next;
		}
		if (l.head->data == value) deleteHead(l);
	}
	// sort
	void sort(List l, char type)
	{
		bool sorted = false, compare;
		if(isEmpty(l)) return;
		while (!sorted)
		{
			sorted = true;
			Node* current = l.head;
			while (current->next)
			{
				if (type == 'a')
					compare = current->data > current->next->data;
				else if (type == 'd')
					compare = current->data < current->next->data;
				else return;

				if (compare)
				{
					sorted = false;
					swap(current->data, current->next->data);
				}
				current = current->next;
			}
		}
	}
	// EvenOrOddNumber()
	void EvenOrOddNumber(List l, char type)
	{
		if (isEmpty(l)) return;
		bool condition;
		while(l.head)
		{
			switch (type)
			{
				case 'e': condition = !(l.head->data & 1); break;
				case 'o': condition = l.head->data & 1; break;
				default: return;
			}
			condition ? printNode(l.head) : std::cout << "";
			l.head = l.head->next;
		}
		std::cout << std::endl;
	}
	// search
	int findX(List l, int x)
	{
		if(isEmpty(l)) return -1;
		int index = 1;
		while (l.head)
		{
			if (l.head->data == x)
				return index;
			++index;
			l.head = l.head->next;
		}
		return -1;
	}
	int findMaxOrMin(List l, char *type)
	{
		if (isEmpty(l)) return -1;
		int result = l.head->data;
		while(l.head)
		{
			if (!strcmp(type, "max"))
				result = l.head->data > result ? l.head->data : result;
			if (!strcmp(type, "min"))
				result = l.head->data < result ? l.head->data : result;
			l.head = l.head->next;
		}
		return result;
	}
	int findMaxOrMinEvenNumber(List l, char* type)
	{
		if (strcmp(type, "max") && strcmp(type, "min") && isEmpty(l)) return -1;
		bool condition;
		while (l.head->data & 1)
			l.head = l.head->next;
		if (l.head == NULL) return -1;
		int result = l.head->data;
		while(l.head)
		{
			if (!strcmp(type, "max")) 
				condition = l.head->data > result && !(l.head->data & 1);
			if (!strcmp(type, "min")) 
				condition = l.head->data < result && !(l.head->data & 1);
			if(condition)
				result = l.head->data;
			l.head = l.head->next;
		}
		return result;
	}
	int findMaxOrMinOddNumber(List l, char* type)
	{
		if (strcmp(type, "max") && strcmp(type, "min") && isEmpty(l)) return 0;
		bool condition;
		while (!(l.head->data & 1))
			l.head = l.head->next;
		if (l.head == NULL) return 0;
		int result = l.head->data;
		while(l.head)
		{
			if (!strcmp(type, "max")) 
				condition = l.head->data > result && l.head->data & 1;
			if (!strcmp(type, "min")) 
				condition = l.head->data < result && l.head->data & 1;
			if(condition)
				result = l.head->data;
			l.head = l.head->next;
		}
		return result;
	}
	void findLongestAscendingSubNode(List l)
	{
		// fixing ...
		if (isEmpty(l)) return;
		int current_length = 1, max_length = 1;
		Node* current, *start_longest_subnode;
		current = start_longest_subnode = l.head;

		while (current->next) {
			if (current->data < current->next->data) {
				++current_length;
				if (current_length > max_length) {
					max_length = current_length;
					start_longest_subnode = current;
				}
			} 
			else
				current_length = 1;
			current = current->next;
		}
		if (max_length == 1) return;
		while(max_length--) {
			printf("%d ", start_longest_subnode->data);
			start_longest_subnode = start_longest_subnode->next;
		}
		printf("\n");
	}
	// counter
	int getSize(List l) 
	{
		int count = 0;
		while (l.head)
		{
			++count;
			l.head = l.head->next;
		}
		return count;
	}
	int counterX(List l, int x)
	{
		int count = 0;
		while (l.head)
		{
			if (l.head->data == x)
				++count;
			l.head = l.head->next;
		}
		return count;
	}
	int greaterAfter(List l)
	{
		int count = 0;
		while (l.head->next)
		{
			if (l.head->data > l.head->next->data)
				++count;
			l.head = l.head->next;
		}
		return count;
	}
	// sum
	int total(List l)
	{
		int total = 0;
		while (l.head)
		{
			total += l.head->data;
			l.head = l.head->next;
		}
		return total;
	}
	// match sl2 after x in sl1
	bool match(int x, List &l1, List l2)
	{
		Node* temp_node = l1.head;
		while(temp_node->data != x && temp_node->next != NULL)
			temp_node = temp_node->next;
		if (temp_node->next == NULL && temp_node->data != x)
			return false; // ko tim thay x
		else
		{
			l2.tail->next = temp_node->next;
			temp_node->next = l2.head;
			return true;
		}
	}
};

int main()
{
	linked_list dslk(5);
	List list1 = dslk.creatList();
	dslk.createLinkedList(list1);
	List list2 = dslk.creatList();
	dslk.createLinkedList(list2);
	//dslk.insertAfter(list1, list1.head, 10);
	//dslk.deleteHead(list1);
	//dslk.sort(list1, 'd');
	//dslk.EvenOrOddNumber(list1, 'e');
	//dslk.findX(list1, 10);
	//dslk.getSize(list1);
	//dslk.counterX(list1, 1);
	//dslk.total(list1);
	//dslk.greaterAfter(list1);
	//dslk.findMaxOrMin(list1, "min");
	//dslk.findMaxOrMinEvenNumber(list1, "min");
	//dslk.match(4, list1, list2);
	//dslk.findMaxOrMinOddNumber(list1, "min");
	//dslk.deleteMaxOrMin(list1, "min");
	//dslk.isAscendingOrDescending(list1, 'd');
	//dslk.findLongestAscendingSubNode(list1) - fixing;
	dslk.printLinkedList(list1);
	system("pause>0");
	return 0;
}
