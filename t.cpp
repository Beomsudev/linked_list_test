#include <iostream>

using namespace std;

//?????? struct ���� (data���� nextNode?? ����)
struct node {
	int data;
	node* nextNode;
    node* prevNode;
};

//��ũ??? ����??? ????????? ??????
class SingleLinkedList {
	private:
		node* head;
		node* tail;
		
	public:
		SingleLinkedList() {
			//head ??? tail??? ??????????? �ʱ�???;
			head = NULL;
			tail = NULL;
		}
		//ù��°�� node ��???
		void insertFirstNode(int n);
		//��???���� node ��???
		void insertLastNode(int n);

		//node ??????
		void insertNode(node* prevNode, int n);
		//node ??????
		void deleteNode(node* prevNode);

		//ù��?? ?????? ??????????
		node* getHead() {
			return head;
		}
		//SingleLinkedList ���
		void display(node* head);
};

//ù��°�� node ��???
void SingleLinkedList::insertFirstNode(int n) {
	node* temp = new node;
	//temp??? ???????????? n
	temp->data = n;

	//SingleLinkedList?? ���????????
	if (head == NULL) {
		//?? node??? temp
		head = temp;
		//��????? node??? temp
		tail = temp;
	}
	//SingleLinkedList??? ??????????? ????????
	else {
		//temp??? nextNode??? head
		temp->nextNode = head;
        temp->prevNode = head;
		//head??? temp
		head = temp;
	}
}

//��???���� node ��???
void SingleLinkedList::insertLastNode(int n) {
	node* temp = new node;

	//temp??? ???????????? n
	temp->data = n;
	//temp??? nextNode = NULL??
	temp->nextNode = NULL;

	//SingleLinkedList?? ���????????
	if (head == NULL) {
		//?? node??? temp
		head = temp;
		//��????? node??? temp
		tail = temp;
	}
	//SingleLinkedList??? ??????????? ????????
	else {
		//?????? ��????? node??? nextNode??? temp
		tail->nextNode = temp;
		//��????? node??? temp
		tail = temp;
	}
}

//node ??????
void SingleLinkedList::insertNode(node* prevNode,int n) {
	node* temp = new node;
	//temp??? ???????????? n
	temp->data = n;

	//temp??? nextNode ??????
	//(?????? ??? ??? node??? nextNode?? temp??? nextNode??? ??????)
	temp->nextNode = prevNode->nextNode;

	//temp ??????
	//temp?????? node??? nextNode?? temp?? ??????
	prevNode->nextNode = temp;
}

//node ??????
void SingleLinkedList::deleteNode(node* prevNode) {

	//????????? node?? temp??? ??????
	//(????????? node??? 1????? ??? node??? nextNode) 
	node* temp = prevNode->nextNode;

	//????????? node?? ??????
	//(????????? node??? nextNode?? 1????? ??? node??? nextNode??? ??????)
	prevNode->nextNode = temp->nextNode;

	//temp ??????
	delete temp;
}

//SingleLinkedList ���
void SingleLinkedList::display(node* head) {
	if (head == NULL) {
		cout << "\n";
	}
	else {
		cout << head->data << " ";
		display(head->nextNode);
	}
	cout << endl;
}



//���� ??????
int main() {
	SingleLinkedList a;
	//1��???
	a.insertLastNode(1);
	//2��???
	a.insertLastNode(2);
	//3��???
	a.insertLastNode(3);

	//display
	cout << "1,2,3??? SingleLinkedList??? ��???\n";
	a.display(a.getHead());

	//0??? ?????? ?????? ��???
	a.insertFirstNode(0);

	//1??? ???��°??? ��???
	a.insertNode(a.getHead()->nextNode, 21);
	cout << "0??? ù��°�� ��???, 1??? ???��°??? ��???\n";
	a.display(a.getHead());

	//???��° ?????? ??????
	a.deleteNode(a.getHead()->nextNode);

	//display
	cout << "???��° ???????? ??????\n"; 
	a.display(a.getHead());
}