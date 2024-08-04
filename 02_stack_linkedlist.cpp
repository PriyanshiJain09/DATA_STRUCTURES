#include<iostream>
#define n 5
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int value) : data(value) , next(NULL) {}
};

class Stack{
	private:
		Node* top;
	public:
		Stack() : top(NULL) {}
	
	void push(){
		int value;
		cout<<"enter value to be pushed: ";
		cin>>value;
		Node* newnode = new Node(value);
		newnode->next=top;
		top=newnode;
	}
	
	void pop(){
		if(top == NULL){
			cout<<"stack underflow" <<endl;
			return;
		}
		Node * temp =top;
		top =top->next;
		cout<<"popped element is: " <<temp->data <<endl;
		delete temp;
	}	
	
	void display(){
		if(top==NULL){
			cout<<"stack is empty"<<endl;
			return;
		}
		Node* temp=top;
		cout<<"stack elements are : ";
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};

int main(){
	Stack st;
	int choice;
	do {
		cout<<"====MENU===="<<endl;
		cout<<"1. PUSH"<<endl;
		cout<<"2. POP"<<endl;
		cout<<"3. DISPLAY"<<endl;
		cout<<"4.EXIT"<<endl;
		cout<<"============"<<endl;
		cout<<"enter your choice : "<<endl;
		cin>>choice;
		
		switch(choice){
			case 1:
				st.push();
				break;
			case 2:
				st.pop();
				break;
			case 3:
				st.display();
				break;
			case 4:
				cout<<"exiting the program!!!"<<endl;
				break;
			default:
				cout<<"Invalid option."<<endl;
				break;
		}
	}while (choice != 4);
		return 0;
		
}


  
