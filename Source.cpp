#include <stdio.h>
#include <stdlib.h>

class linked_list {
private:
	int len, temp;
	struct Node {
		int data;
		Node* next;
	};
	struct Slist {
		Node* head;
		Node* tail;
	} l;
public:
	// initialize function
	void initialize() {
		l.head = NULL;
		l.tail = NULL;
	}
	bool isEmpty(Slist l) {
		return l.head == NULL ? true : false;
	}
	bool isFull(Node* p) {
		return p == NULL ? true : false;
	}
	bool isExist() {
		return isEmpty(l) == 0 ? true : false; 
	}
	// operation on linked list
	Node* createNode(int data) {
		Node* node = new Node;
		if (isFull(node)) exit(1);
		node->data = data;
		node->next = NULL;
		return node;
	}
	void createLinkedList() {
		if (isExist()) deleteLinkdedList();
		printf("Nhap so luong phan tu: "); scanf_s("%d", &len);
		int n = len; 
		while (n) {
			scanf_s("%d", &temp);
			Node* node = createNode(temp);
			if (isEmpty(l)) {
				l.head = node;
				l.tail = node;
			}		
			l.tail->next = node;
			l.tail = node;
			--n;
		}
		printf("Notification: Danh sach lien ket da duoc tao!\n");
	}
	void printLinkedList() {
		if (!isExist()) {printf("Error: Danh sach chua duoc tao!\n"); return;}
		printf("linked list: ");
		Node* head = l.head;
		while (head) {
			printf("%d ", head->data);
			head = head->next;
		}
	}
	// sort function
	void swap(Node* curr, Node* next) {
		int temp = curr->data;
		curr->data = next->data;
		next->data = temp;
	}
	void Ascending() {
		if (!isExist()) {printf("Error: Danh sach chua duoc tao!\n"); return;}
		bool sorted = false;
		while (!sorted) {
			sorted = true;
			Node* head = l.head;
			while (head->next) {
				if (head->data > head->next->data) {
					sorted = false;
					swap(head, head->next);
				}
				head = head->next;
			}
		}
		printf("Notification: Da sap sep xong!\n");
	}
	void Decending() {
		if (!isExist()) {printf("Error: Danh sach chua duoc tao!\n"); return;}
		bool sorted = false;
		while (!sorted) {
			sorted = true;
			Node* head = l.head;
			while (head->next) {
				if (head->data < head->next->data) {
					sorted = false;
					swap(head, head->next);
				}
				head = head->next;
			}
		}
		printf("Notification: Da sap sep xong!\n");
	}
	// odd and even
	void isEven() {
		if (!isExist()) {printf("Error: Danh sach chua duoc tao!\n"); return;}
		Node* head = l.head;
		printf("Phan tu chan trong danh sach: ");
		while(head) {
			if (!(head->data & 1))
				printf("%d ", head->data); 
			head = head->next;
		}
	}
	void isOdd() {
		if (!isExist()) {printf("Error: Danh sach chua duoc tao!\n"); return;}
		Node* head = l.head;
		printf("Phan tu le trong danh sach: ");
		while(head) {
			if (head->data & 1)
				printf("%d ", head->data); 
			head = head->next;
		}
	}
	// searching
	void findX() {
		if (!isExist()) {printf("Error: Danh sach chua duoc tao!\n"); return;}
		Node* head = l.head;
		bool flag = false;
		int x, index = 1;
		printf("Nhap gia tri can tim: ");
		scanf_s("%d", &x);
		while(head) {
			if (head->data == x) {
				flag = true;
				break;
			}
			++index;
			head = head->next;
		}
		if (flag)
			printf("%d nam tai nut %d cua danh sach lien ket.\n", x, index);
		else
			printf("Khong tim thay x trong danh sach.\n");
	}
	// counter
	void countLen() {
		if (!isExist()) {printf("Error: Danh sach chua duoc tao!\n"); return;}
		printf("So phan tu cua danh sach lien ket la: %d\n", len);
	}
	void countX() {
		if (!isExist()) {printf("Error: Danh sach chua duoc tao!\n"); return;}
		int count = 0, x;
		printf("Nhap x: "); 
		scanf_s("%d", &x);
		Node* head = l.head;
		while (head) {
			if (head->data == x)
				++count;
			head = head->next;
		}
		printf("Tren danh sach lien ket co %d gia tri %d\n", count, x);
	}
	// sum 
	void total() {
		if (!isExist()) {printf("Error: Danh sach chua duoc tao!\n"); return;}
		int total = 0;
		Node* head = l.head;
		while(head) {
			total += head->data;
			head = head->next;
		}
		printf("Tong cac phan tu cua danh sach lien ket la: %d\n", total);
	}
	// remove
	void deleteLinkdedList() {
		int n = len;
		while (n) {
			Node* temp = l.head;
			l.head = l.head->next;
			delete temp;
			--n;
		}
		l.tail = NULL;
	}
	void getMaxAndMin(int *max, int *min) {
		Node* head = l.head->next;
		while (head) {
			if (head->data > *max)
				*max = head->data;
			if (head->data < *min)
				*min = head->data;
			head = head->next;
		}
	}
	void getEvenNumberMaxAndMin(int *max, int *min, int *status) {
		Node* temp = l.head;
		while ((temp->data & 1) && temp->next != NULL)
			temp = temp->next;
		if (temp->next == NULL)
			*status = -1;
		else
		{
			Node* head = l.head;
			*max = *min = temp->data;
			getMaxAndMin(max, min);
			*status = 1;
		}
	}
};

void menu();

void main(){
	linked_list l;
	l.initialize();
	int choosen;
	bool flag = true; 
	while (flag) {
		menu();
		printf("lua chon: ");
		scanf_s("%d", &choosen);
		switch (choosen) {
		case 0: flag = false; break;
		case 1: l.createLinkedList(); break;
		case 2: l.Ascending(); break;
		case 3: l.Decending(); break;
		case 4: l.isEven(); break;
		case 5: l.isOdd(); break;
		case 6: l.findX(); break;
		case 7: l.countLen(); break;
		case 8: l.countX(); break;
		case 9: l.total(); break;
		case 10: l.printLinkedList(); break;
		case 11: l.getEvenNumberMaxAndMin(&max, &min, &status);
			if (status != -1) {
				printf("Max: %d\n", max);
				printf("Min: %d\n", min);
			}
			else
				printf("Khong co so chan trong dslk\n");
			break;
		default: printf("Khong co lua chon nay!\n"); break;
		}
		system("pause");
		system("cls");
	}
	system("pause");
}

void menu()
{
	printf("menu:\n");
	printf("**********************************************************\n");
	printf("* 1 . Tao danh sach lien ket                             *\n");
	printf("* 2 . Sap xep danh sach tang dan                         *\n");
	printf("* 3 . Sap xep danh sach giam dan                         *\n");
	printf("* 4 . Xuat cac phan tu chan trong danh sach lien ket     *\n");
	printf("* 5 . Xuat cac phan tu le trong danh sach lien ket       *\n");
	printf("* 6 . Tim kiem x tren danh sach lien ket                 *\n");
	printf("* 7 . Dem so phan tu cua danh sach lien ket              *\n");
	printf("* 8 . Dem tren danh sach lien ket co bao nhieu gia tri x *\n");
	printf("* 9 . Tinh tong cac phan tu cua danh sach lien ket       *\n");
	printf("* 10. Xuat danh sach lien ket                            *\n");
	printf("* 0. Thoat                                               *\n");
	printf("**********************************************************\n");
}
