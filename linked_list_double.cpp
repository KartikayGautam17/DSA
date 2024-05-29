#include<iostream>

using namespace std;

class Node{
public:
	int data;
	Node *next = nullptr;
	Node *prev = nullptr;
	Node(int data){
		this -> data = data;
		this -> next = nullptr;
		this -> prev = nullptr;
	}
};
void AppendAtStart(Node *&head,int data){
	Node *element = new Node(data);
	element -> next = head;
	head -> prev = element;
	head = element;
}
void AppendAtEnd(Node *&tail,int data){
	Node *element = new Node(data);
	element -> prev = tail;
	tail -> next = element;
	tail = element;
}
void Insert(Node *&head,Node *&tail,int data,int pos){
	if (!pos) {AppendAtStart(head,data);return;}
	Node *clone_head = head;
	//Node *head2 = head;
	pos--;
	while (pos-- && head->next){
		head = head->next;	
	}
	if (!head || !head->next) {AppendAtEnd(tail,data);head = clone_head;return;}
	Node *element = new Node(data);
	element -> prev = head;
	element -> next = head->next;
	head -> next = element;
	head = element;
	head = clone_head;
}
void Display_Neighbours(Node *head){
	while (head != nullptr){
		if (head -> prev == 0) cout << '_' << " ";
		else cout << head -> prev -> data << " ";
		cout << head -> data << " ";
		if (head -> next == 0) cout << '_' << endl;
		else cout << head->next->data << endl;
		head = head-> next;
	}
}
void PopAtStart(Node *&head){			
	if (!head->next) head = nullptr;
	else{
		head = head->next;
		head -> prev = nullptr;
	}
}
void PopAtEnd(Node *&tail,Node *&head){ //Pop at end using tail ptr. Works in O(1).
	if (!tail->prev){
		head = nullptr;
		tail = nullptr;
		return;
	}
	//cout << tail->data << " " << tail->prev->data << endl;
	tail = tail->prev;
	tail->next = nullptr;
}
void PopAtEnd_h(Node *&head,Node *&tail){
	//Never Tested so not sure lolz;
	//Pop at end using head ptr. O(N) complexity in time;
	if (!head->next && !head->prev) head=nullptr;
	Node *temp = head;
	while (head->next){
		head = head->next;
	}
	head = head->prev;
	head -> next = nullptr;
	tail = head;
}
void remove(Node *&head,Node *&tail,int pos){
	if (!pos) {PopAtStart(head);return;}
	Node *temp_head = head;
	Node *temp_tail = tail;
	while (pos-- && head->next){
		head = head->next;
	}
	if (!head || !head->next){ PopAtEnd(tail,head);head=temp_head;return;}
	head -> prev -> next = head -> next;
	head -> next -> prev = head -> prev;
	head = temp_head;
}
void Traverse(Node *head){
	while (head != nullptr){
		cout << head -> data << endl;
		head = head->next;
	}
}
int main(){
	Node *head = new Node(2);
	Node *tail = head;
	AppendAtEnd(tail,10);
	AppendAtStart(head,6);
	remove(head,tail,4);
	Traverse(head);
}