#include<bits/stdc++.h>
#include<stdexcept>

using namespace std;
const int max_size = pow(10.0,5.0);
class stack0{

	int top;
	int stack_size;
public:
	int stack[max_size]={0};
	stack0(const int size){
		stack_size = size;
		top = -1; 
	}
	void push(int val){
		try{
			if (top >= stack_size) throw runtime_error("Stack Overflow");
			top++;
			stack[top] = val;
		}
		catch(exception &aww){
			cerr << "Exception : " << aww.what() << endl;
		}
	}
	void pop(){
		try{
			if (top<0) throw runtime_error("Stack Underflow");
		}
		catch(exception &aww){
			cerr << "Exception : " << aww.what() << endl;
		}
		stack[top] = 0;
		top--;
	}
	void display(){
		if (top<0) {cout << "Empty Stack"; return;}
		cout << stack[top] << " <--TOP" << endl;
		for (int i = top-1;i>-1;i--){
			cout << stack[i] << endl;
		}
	}
};
int main(){
	stack0 arr(10);	
	arr.push(1);
	arr.push(2);
	arr.push(3);
	arr.pop();
	arr.pop();
	arr.display();
}