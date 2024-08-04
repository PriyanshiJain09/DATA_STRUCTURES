#include <iostream>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
        Node(int value) : data(value) , next(NULL) {} 
    };
class CircularQueue {
private:
    Node* front; 
    Node* rear;  

public:
    CircularQueue() : front(NULL), rear(NULL) {}

    void enqueue(int value) {
        Node* newNode = new Node(value);
        newNode->data = value;
        newNode->next = NULL;

        // If the queue is empty, make the new node front and rear
        if (front == NULL) {
            front = newNode;
            rear = newNode;
            rear->next = front; // Circular linking
        } else {
            rear->next = newNode; // Link the new node with the rear
            rear = newNode;       // Update the rear
            rear->next = front;    // Circular linking
        }

        cout << "Enqueued: " << value << std::endl;
    }

    // Function to dequeue an element from the circular queue
    void dequeue() {
        // If the queue is empty, do nothing
        if (front == NULL) {
            cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        Node* temp = front;     // Temporary pointer to the front node
        cout << "Dequeued: " << front->data << std::endl;
        if (front == rear) {    // If there's only one node in the queue
            front = NULL;
            rear = NULL;
        } else {
            front = front->next; // Move front to the next node
            rear->next = front;  // Circular linking
        }
        delete temp;            // Free the memory of the dequeued node
    }

    void display() {
        if (front == NULL) {
            cout << "Circular Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    CircularQueue queue;
    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            }
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

