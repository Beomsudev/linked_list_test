#include <iostream>

using namespace std;

//��� struct ���� (data���� nextNode�� ����)
struct node {
	int data;
	node* nextNode;
	node* prevNode;
};

//��ũ�� ����Ʈ Ŭ���� ����
class DoubleLinkedList {
	private:
		node* head;
		node* tail;
		
	public:
		DoubleLinkedList() {
			//head �� tail�� �����͸� �ʱ�ȭ;
			head = NULL;
			tail = NULL;
		}
		//ù��°�� node �߰�
		void insertFirstNode(int n);
		//�������� node �߰�
		void insertLastNode(int n);

		//node ����
		void insertNode(node* prevNode, int n);
		//node ����
		void deleteNode(node* prevNode);

		//ù��° ��� ��������
		node* getHead() {
			return head;
		}
		//LinkedList ���
		void display(node* head);
};

//ù��°�� node �߰�
void DoubleLinkedList::insertFirstNode(int n) {
	node* temp = new node;
	//temp�� �����ʹ� n
	temp->data = n;

	temp->nextNode = head;
	temp->prevNode = NULL;
	//LinkedList�� ���������
	if (head == NULL) {
		//ù node�� temp
		head = temp;
		//������ node�� temp
		tail = temp;
	}
	//LinkedList�� �����Ͱ� ������
	else {
		//temp�� nextNode�� head
		temp->nextNode = head;
		head->prevNode = temp;
		//head�� temp
		head = temp;
	}
}

//�������� node �߰�
void DoubleLinkedList::insertLastNode(int n) {
	node* temp = new node;

	//temp�� �����ʹ� n
	temp->data = n;
	//temp�� nextNode = NULL��
	temp->nextNode = NULL;
	temp->prevNode = head;
	//LinkedList�� ���������
	if (head == NULL) {
		//ù node�� temp
		head = temp;
		//������ node�� temp
		tail = temp;
	}
	//LinkedList�� �����Ͱ� ������
	else {
		//���� ������ node�� nextNode�� temp
		tail->nextNode = temp;
		//������ node�� temp
		tail = temp;
	}
}

//node ����
void DoubleLinkedList::insertNode(node* beforeNode, int n) {
	node* temp = new node;
	//temp�� �����ʹ� n
	temp->data = n;

	//temp�� nextNode ����
	//(���� �� �� node�� nextNode�� temp�� nextNode�� ����)
	temp->nextNode = beforeNode->nextNode;
	temp->prevNode = beforeNode;

	//temp ����
	//temp���� node�� nextNode�� temp�� ����
	beforeNode->nextNode = temp;
}

//node ����
void DoubleLinkedList::deleteNode(node* beforeNode) {

	//������ node�� temp�� ����
	//(������ node�� 1�ܰ� �� node�� nextNode) 
	node* temp = beforeNode->nextNode;

	//������ node�� ����
	//(������ node�� nextNode�� 1�ܰ� �� node�� nextNode�� ����)
	beforeNode->nextNode = temp->nextNode;
	temp->nextNode = beforeNode;
	//temp ����
	delete temp;
}

//LinkedList ���
void DoubleLinkedList::display(node* head) {
	if (head == NULL) {
		cout << "\n";
	}
	else {
		cout << head->data << " ";
		display(head->nextNode);
	}
	cout << endl;
}

//���� �Լ�
int main() {
	DoubleLinkedList a;
	//1�߰�
	a.insertLastNode(1);
	//2�߰�
	a.insertLastNode(2);
	//3�߰�
	a.insertLastNode(3);

	//display
	cout << "1,2,3�� DoubleLinkedList�� �߰�\n";
	a.display(a.getHead());


	//0�� ���� �տ� �߰�
	a.insertFirstNode(0);

	//1�� �׹�°�� �߰�
	a.insertNode(a.getHead()->nextNode, 21);
	cout << "0�� ù��°�� �߰�, 1�� �׹�°�� �߰�\n";
	a.display(a.getHead());



	//����° ��� ����
	a.deleteNode(a.getHead()->nextNode);

	//display
	cout << "����° ��带 ����\n"; 
	a.display(a.getHead());

}