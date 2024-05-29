#include<cmath>
#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<bits/stdc++.h>

using namespace std;

bool _BALANCED_VAL = true;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this -> data = data;
		this -> left = nullptr;
		this -> right = nullptr;
	}
};	
bool flag = true;
Node* BuildTree(Node* &root){
	int data;
	cin >> data;
	//cout << data << endl;
	if (data == -1){return root;}
	root = new Node(data);
	BuildTree(root->left);
	BuildTree(root->right);
	//root = temp;
	return root;
}

void RecursiveLevelOrderTraversal(Node* root){
	if (!root) return;
	cout << root->data << " ";
	RecursiveLevelOrderTraversal(root->left);
	RecursiveLevelOrderTraversal(root->right);
}

void LevelOrderTraversal(Node* root){
	queue<Node*> q;
	if (root) q.push(root);
	q.push(nullptr);
	while (!q.empty()){
		Node* temp = q.front();
		q.pop();
		if (temp==nullptr){
			cout << endl;
			if (!q.empty()){
				q.push(nullptr);
			}
			continue;
		}
		cout << temp->data << " ";
		if (temp->left) q.push(temp->left);
		if (temp->right) q.push(temp->right);
		
	}
}

void ReverseLevelOrderTraversal(Node* root){
	queue<Node*> q;
	stack<Node*> s;
	q.push(root);
	q.push(nullptr);
	while (!q.empty()){
		Node* temp = q.front();
		s.push(q.front());
		q.pop();
		if (!temp) {
			if (!q.empty()){
				q.push(nullptr);
			}
			continue;
		}
		if (temp->right) q.push(temp->right);
		if (temp->left) q.push(temp->left);
	}
	s.pop(); //for popping null value
	while(!s.empty()){
		Node* temp = s.top();
		if (temp){
			cout << temp->data << " ";
		}
		else cout << endl;
		s.pop();
	}
}

Node* no_recursion_build(Node* root){
	//binary tree max 2 child;
	stack<Node*> s;
	int data;
	cin >> data;
	root = new Node(data);
	s.push(root);
	while(!s.empty()){
		Node* temp = s.top();
		while(!temp->left){
			int data;
			cin >> data;
			if (data!=-1){ 
				Node* element = new Node(data);
				temp->left=element;
				s.push(element);
				temp=s.top();
			}
			else break;
		}
		s.pop();
		if (!temp->right){ //!temp->right condition is unnecessary as the !temp->right is always
						   //going to be true;
			cin >> data;
			if (data!=-1){
				Node* element = new Node(data);
				temp->right=element;
				s.push(element);
			}
		}
	}
	return root;
}

void InorderTraversal(Node* root){
	if (root == nullptr){
		return;
	}
	InorderTraversal(root->left);
	cout << root->data << endl;
	InorderTraversal(root->right);
}

void PreorderTraversal(Node* root){
	if (root == nullptr){ return;}
	cout << root -> data << endl;
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}

void PostorderTraversal(Node* root){
	if (root == nullptr){ return;}
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
	cout << root -> data << endl;
}

int get_height(Node* root){
	if (root == nullptr){
		return 0;
	}
	int left = get_height(root->left);
	int right = get_height(root->right);
	return max(left,right)+1;
}

int diameter(Node* root,int& height){
	if (root == nullptr) {height = 0;return 0;}
	int lh=0,rh=0,ld=0,rd=0;
	diameter(root->left,lh);
	diameter(root->right,rh);
	height = max(lh,rh)+1;
	return max(lh+rh+1,max(ld,rd));
}

int get_diameter(Node* root){
	int h = 0;
	return diameter(root,h);
}

bool balance_check(Node* root,int& height,bool flag = true){
	if (root == nullptr) {height = 0; return flag;} //always returns true
	int lh=0,rh=0;
	balance_check(root->left,lh);
	balance_check(root->right,rh);
	height = max(lh,rh)+1;
	if (abs(lh-rh) > 1) _BALANCED_VAL = false;
	return flag;
}


void ZigZagTraversal(Node* root){
	vector<Node*> v;
	if (root == nullptr) return;
	v.push_back(root);
	v.push_back(nullptr);
	bool flag = true;
	int i = 0;int j = 1;
	while(i<j){
		Node* temp = v[i];
		
		if (temp == nullptr){	
			v.push_back(nullptr);
			j++;	
		}
		else{
			if (temp -> left) {
				j++;
				v.push_back(temp->left);
			}
			if (temp -> right){
				j++;
				v.push_back(temp->right);
			}
		}
		i++;
	}
	 
	j = v.size(); // not necessary
	int k = 0;int l = 1;
	for (int i = 0;i<j;i++){
		Node* temp = v[i];
		if (temp == nullptr){
			vector<int> v2;
			int k = i;k++;
			while (k<j && v[k]!=nullptr){

				v2.push_back(k);
				k++;
			}
			for (int i = v2.size()-1;i>=0;i--){ cout << v[v2[i]]->data << " ";}
			cout << endl;
			i=k;
		}
		else{
			cout << temp -> data << " ";
		}
	}
}

void VerticalOrderTraversal(Node* root){
	map<int,map<int,vector<Node*>>> multiset;
	queue<pair<Node*,pair<int,int>>> q;
	q.push(make_pair(root,make_pair(0,0)));
	
	while (!q.empty()){
		Node* temp = q.front().first;	 
		pair<int,int> coordinates = q.front().second;
		q.pop();
		if (temp -> left){
			q.push({temp->left,{coordinates.first-1,coordinates.second+1}});
		}
		if (temp -> right){
			q.push({temp->right,{coordinates.first+1,coordinates.second+1}});
		}
		multiset[coordinates.first][coordinates.second].push_back(temp);
	}
	for (auto x : multiset){
		// key:int and value: map<int,vector<Node*>>
		cout << x.first << endl;
		for (auto y: x.second){
			// key: int and value: vector<Node*>
			cout << y.first << " -> ";
			
			for (auto z:y.second){
				cout << z->data << " ";
			}
			cout << endl;
		}
		cout << "-----" << endl;
	}
}

void TopView(Node *root){
	map<int,Node*> multiset;
	map<int,int> mp;
	mp[1] = 10;
	mp[2] = 20;
	mp[3] = 30;
	mp[4] = 40;
	queue<pair<Node*,int>> q;
	q.push(make_pair(root,0));
	while (!q.empty()){
		Node* temp = q.front().first;
		int x  = q.front().second;
		q.pop();
		if (multiset.find(x) != multiset.end()){
			continue;
		}
		if (temp->left) q.push({temp->left,x-1});
		if (temp->right) q.push({temp->right,x+1});
		multiset[x] = temp;
	}
	for (auto x:multiset){
		cout << x.second->data << endl;
	}
}	

int main(){
	Node* root = nullptr;
	//root = no_recursion(root);
	//root = BuildTree(root);
	// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
	// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
	root = no_recursion_build(root);
	TopView(root);
}