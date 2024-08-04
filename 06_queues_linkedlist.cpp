#include <iostream>
using namespace std;
#define N 5
class node{
public:
	int data;
	node* next;
	node(int value): data(value) , next(NULL) {}
};
class queue{
private:
	node* front;
	node* rear;
public:
	queue() : front(NULL) , rear(NULL) {}
	
	void enqueue(int value){
		node * newnode = new node(value);
		newnode->data=value;
		newnode->next=NULL;
		if (front==NULL && rear== NULL){
			front =rear= newnode;
		}
		else{
			rear->next=newnode;
			rear=newnode;
		}
	}
	
	void display(){
		node* temp =front;
		if (front==NULL && rear== NULL){
			cout<<"queue is empty";
		}
		else{
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
	}
	
	void peek(){
		if (front==NULL && rear== NULL){
			cout<<"queue is empty";
		}
		else{
			cout<<"top element is : "<< front->data <<endl;
		}
	}
	
	void reverse() {
        node* current = front;
        node* prev = NULL;
        node* next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        front = prev;
        cout<<"Queue has been reversed."<<endl;
    }
    
	void dequeue(){
		node* temp =front;
		if (front == NULL && rear == NULL)
            cout << "queue is empty";
        else {
            cout << "element dequeued is " << temp->data;
            front = front->next;
            delete temp;
	   }
   }
};

int main(){
	queue q;
	int val;
	int choice;
	do{
	cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Reverse\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
		
		switch(choice){
			case 1:
				cout<<"enter the value you need to insert: "<<endl;
				cin>>val;
				q.enqueue(val);
				break;
			case 2:
				q.dequeue();
				break;
			case 3:
				q.peek();
				break;
			case 4:
				q.display();
				break;
			case 5:
				q.reverse();
				break;
			case 6:
				cout<<"Exiting the program."<<endl;
				break;
			default:
				cout<<"Invalid option."<<endl;
		}	
	}while (choice != 6);
	return 0;
}

