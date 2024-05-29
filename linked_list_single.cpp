#include<iostream>

using namespace std;

#define h head
#define t tail

class Node{
public:
	int data;
	Node* next;
	Node(int data){
		this -> data = data;
		this -> next = nullptr; 
	}
};
void push_front(int data,Node* &head){
	Node* temp = new Node(data);
	temp -> next = head;
	head = temp;
}
void push_back(int data,Node* &tail){
	Node* temp = new Node(data);
	tail -> next = temp;
	tail = temp;
}
void insert(int data,Node* &head,Node* &tail,int pos){
	Node* temp_head = head;
	Node* temp_next = head->next;
	int i = 0;
	while (i < pos-1 && head!=nullptr){
		head = head->next;
		i++;
	}
	if (head == nullptr) {push_back(data,tail); return; }
	if (pos == 0) {push_front(data,head);return;}
	Node* new_element = new Node(data);
	temp_next = head->next;
	head -> next = new_element;
	new_element->next = temp_next;
	head = temp_head;
}	
void pop_front(Node *&head) {head = head->next;}
void pop_back_h(Node *&head) { 	//Works in O(N);
								//Not extensively tested,
								//avoid using;
	Node *temp = head;
	Node *clone_head = head;
	if (!head->next) head = head->next;
	else{
		while (head -> next){
			temp = head;
			head = head->next;
		}
		temp -> next = nullptr;
		head = clone_head;
	}
}
void remove(Node *&head,int pos){
	if (!pos) {pop_front(head); return;}
	Node *clone_head = head;
	Node *temp = head;
	pos--; 	//pos-- is alternate to the approach of checking head -> next != nullptr 
	  	 	//in the while condition as written back in pop_back function.
			//Our approach is to get behind the target element which is to be removed.
	while(pos && head){
		pos--;
		temp = head;
		head = head->next;
	}
	if (!head) {pop_back(temp); head=clone_head; return;}
	head -> next = head -> next -> next;
	head = clone_head;
}
void display(Node* head){
	while (head!=nullptr){
		cout << head -> data << endl;
		head = head -> next;
	}
}

int main(){
	Node* head = new Node(1);
	Node* tail = head;
	push_front(10,head);
	push_front(20,head);
	push_front(30,head);
}