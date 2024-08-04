#include <iostream>
using namespace std;

class Queue {
private:
    int* queue;
    int rear;
    int front;
    int size;

public:
    Queue(int n) : size(n), rear(-1), front(-1) {
        queue = new int[size];
    }

    bool isFull() {
        return (rear == size - 1);
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Overflow" << endl;
        } else {
            if (isEmpty()) {
                rear = front = 0;
            } else {
                rear++;
            }
            queue[rear] = x;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
        } else {
            cout << "Element dequeued is: " << queue[front] << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front element is: " << queue[front] << endl;
        }
    }

    void reverse() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            int i = rear;
            int j = front;
            while (i > j) {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
                i--;
                j++;
            }
            cout << "Queue reversed." << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    Queue myqueue(size);
    int x;
    int choice;
    do {
        cout << "====MENU====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Reverse" << endl;
        cout << "6. Exit" << endl;
        cout << "============" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert:" << endl;
                cin >> x;
                myqueue.enqueue(x);
                break;
            case 2:
                myqueue.dequeue();
                break;
            case 3:
                myqueue.peek();
                break;
            case 4:
                myqueue.display();
                break;
            case 5:
                myqueue.reverse();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid option" << endl;
        }
    } while (choice != 6);

    return 0;
}


/*
#include <iostream>
using namespace std;
#define N 5

class Queue {
private:
    int queue[N];
    int rear;
    int front;

public:
    Queue() : rear(-1), front(-1) {}

    bool isFull() {
        return (rear == N - 1);
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Overflow" << endl;
        } else {
            if (isEmpty()) {
                rear = front = 0;
            } else {
                rear++;
            }
            queue[rear] = x;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
        } else {
            cout << "Element popped: " << queue[front] << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front element is: " << queue[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }

    void reverse() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            int i = front;
            int j = rear;
            while (i < j) {
                // Swap elements at positions i and j
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
                i++;
                j--;
            }
            cout << "Queue reversed" << endl;
        }
    }
};

int main() {
    Queue myqueue;
    int x;
    int choice;
    do {
        cout << "====MENU====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Reverse" << endl;
        cout << "6. Exit" << endl;
        cout << "============" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert:" << endl;
                cin >> x;
                myqueue.enqueue(x);
                break;
            case 2:
                myqueue.dequeue();
                break;
            case 3:
                myqueue.peek();
                break;
            case 4:
                myqueue.display();
                break;
            case 5:
                myqueue.reverse();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid option" << endl;
        }
    } while (choice != 6);

    return 0;
}

*/
