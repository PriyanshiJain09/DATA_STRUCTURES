#include <iostream>
using namespace std;
#define n 5
	
class Queue{
	private:
		int queue[n];
		int front;
		int rear;
	
	public:
		Queue(){
			front=-1;
			rear=-1;
		}
		void isfull(){
			if(rear==n-1)
			cout<<"queue is full"<<endl;
			
		
		}
		void isempty(){
			if(front==-1 && rear==-1)
			cout<<"queue is empty"<<endl;
		}
		void enqueue(int x){
			if(rear==n-1)
			cout<<"queue is full"<<endl;
		
		else if(front==-1 && rear==-1){
			front=rear=0;
			queue[rear] = x;
		}
		else{
			rear++;
			queue[rear]=x;
		}
	}
	void dequeue(){
		if(front==-1 && rear==-1)
			cout<<"queue is empty"<<endl;
		else if(front==rear==0){
			front=rear=-1;
		}
		else{
			cout<<"dequeued element is "<<queue[front];
			front++;
		}
	}		
	void peek(){
		if(front==-1 && rear==-1)
		cout<<"queue is empty"<<endl;
		else{
			cout<<"The front element is"<<queue[front];
		}
	
	}
	void display(){
	if(front == -1 && rear == -1){
	cout<<"queue is empty"<<endl;
        }
	else{
		for(int i=front;i<rear+1;i++)
		cout<<queue[i]<<" ";
		}
	}
	
	
};
int main() {
    Queue myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);

    myQueue.display();

    // Queue is full

    myQueue.dequeue();
    myQueue.dequeue();

    myQueue.display();

    myQueue.peek();

    return 0;
}


/*#include <iostream>
using namespace std;
#define N 5
int s1[N], s2[N];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int data) {
    if (top1 == N - 1) {
        cout << "stack is full." << endl;
    } else {
        top1++;
        s1[top1] = data;
    }
}
void push2(int data) {
    if (top2 == N - 1) {
        cout << "stack is full." << endl;
    } else {
        top2++;
        s2[top2] = data;
    }
}
int pop1() {
    return s1[top1--];
}
int pop2() {
    return s2[top2--];
}
void enqueue(int x) {
    push1(x);
    count++;
}
void dequeue() {
    int a;
    int b;
    if (top1 == -1 && top2 == -1) {
        cout << "queue is empty." << endl;
    } else {
        for (int i = 0; i < count; i++) {
            a = pop1();
            push2(a);
        }
        b = pop2();
        count--;
        cout << "Dequeued element is: " << b << endl;
        // Push the elements from stack 2 to stack 1 back
        // after performing the dequeue operation
        for (int i = 0; i < count; i++) {
            a = pop2();
            push1(a);
        }
    }
}
void display() {
    for (int i = 0; i <= top1; i++)
        cout << s1[i] << " ";
    cout << endl;
}
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
    return 0;
}*/
