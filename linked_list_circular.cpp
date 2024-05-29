#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	Node *next;
	int data;
	Node(int data){
		this -> next = this;
		this -> data = data;
	}
};
void push_front(int data,Node *&head,Node *&tail){
	Node *element = new Node(data);
	element -> next = head;
	head = element;
	tail -> next = head;
}
void push_back(int data,Node *&head,Node *&tail){
	Node *element = new Node(data);
	tail -> next = element;
	element -> next = head;
	tail = element;
}
void display(Node *head){
	if (!head) return;
	cout << head->data << endl;
	Node *temp_head = head;
	head = head->next;
	bool flag = false;//put flag = true for double traversal.
	while (head != temp_head || flag){
		//if (head==temp_head) flag = !flag;//Comment out this situation 
		cout << head -> data << endl;
		head = head->next;
	}
}
void pop_front(Node *&head,Node *&tail){
	if (!head || head->next==head){head = nullptr;return;}
	tail -> next = tail -> next -> next;
	head = head->next;
}
void pop_back(Node *&head,Node *&tail){
	if (!head || head->next==head){head=nullptr;return;}
	Node* temp_head = head;
	while (head->next->next!=temp_head){
		head=head->next;
	}
	head->next = temp_head;
	tail = head;
	head = tail->next; //or head=temp_head;
}
bool solve(Node *head){
	Node *temp = head;
	while (head){
		//cout<<head->data<<"head"<<endl;
		Node *target = head->next;
		Node *h1 = temp;
		while (h1!=head){
			if (h1==target) return true;
			h1 = h1->next;
			//cout << h1 -> data << "h1" << endl;
		}
		head=head->next;
	}
	return false;
}
int main(){
	Node *h = new Node(1);
	Node *t = h;
	push_back(4,h,t);
	push_back(5,h,t);
	push_front(-1,h,t);
	push_front(-2,h,t);
	pop_front(h,t);
	pop_back(h,t);
	display(h);
	cout << solve(h);
}