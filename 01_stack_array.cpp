#include <iostream>
using namespace std;
#define N 5
template <class T>
class Stack{
	private:
		T stack[N];
		int top;
	public:
		Stack() : top(-1) {}
		void push(){
			T x;
			cout<<"enter element: ";
			cin>>x;
			if(top== N-1){
				cout<<"overflow condition"<<endl;
			}
			else{
				top++;
				stack[top] =x;
			}
		}
		
		void pop(){
			int item;
			if (top == -1){
				cout <<"underflow condition"<<endl;
			}
			else{
				item=stack[top];
				top--;
				cout<<"popped item is : "<<item<<endl;
			}
		}
		
		void peek(){
			if (top== -1){
				cout<<"stack is empty"<<endl;
			}
			else{
				cout<<"top element: "<<stack[top]<<endl;
			}
		}
		
	void display(){
		if(top == -1){
			cout<<"stack is empty"<<endl;
		}
		else{
			cout<<"stack elements: ";
			for(int i=top ; i>=0; i--){
				cout<<stack[i]<<" ";
			}
			cout<<endl;
		}
	}
};
int main(){
	Stack<int> mystack;
	int choice;
	do{
		cout<<"====MENU===="<<endl;
		cout<<"1. PUSH"<<endl;
		cout<<"2. POP"<<endl;
		cout<<"3. PEEK"<<endl;
		cout<<"4. DISPLAY"<<endl;
		cout<<"5. EXIT THE PROGRAM"<<endl;
		cout<<"Enter your CHOICE : "<<endl;
		cin>>choice;
		
		switch(choice){
			case 1:
				mystack.push();
				break;
			case 2:
				mystack.pop();
				break;
			case 3:
				mystack.peek();
				break;
			case 4:
				mystack.display();
				break;
			case 5:
				cout<<"Exiting the program."<<endl;
				break;
			default:
				cout<<"Invalid Choice. Please try again. "<<endl;
		}	
	} while(choice!=5);
	return 0;
}


