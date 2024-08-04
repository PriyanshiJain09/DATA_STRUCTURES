#include <iostream>
using namespace std;
class node{
	public:
		int data;
		node* prev;
		node* next;
		node(int value): data(value) , next(NULL) , prev(NULL) {}
};

class doubleylinkedlist{
	private:
		node* head;
		node* tail;
	public:
		doubleylinkedlist() : head(NULL) , tail(NULL) {}
		void insertatbegg(int value){
			node* newnode = new node(value);
			newnode->next=head;
			newnode->prev=NULL;
			if(head !=0){
				head->prev=newnode;
			}
			head=newnode;
			if(tail == 0){
				tail=newnode;
			}
		}
		void insertatend(int value){
			node* newnode = new node(value);
			newnode->next=NULL;
			newnode->prev=tail;
			if(tail == 0){
				head=newnode;
			}
			else{
				tail->next=newnode;
			}
			tail=newnode;
		}
		void insertatpos(int value){
			int pos;
			int i=1;
			cout<<"enter position :";
			cin>>pos;
			if(pos<1){
				cout<<"invalid position";
			}
			else if(pos ==1){
				insertatbegg(value);
			}
			else{
				node* newnode=new node(value);
				node* temp=head;
				newnode->prev=tail;
				newnode->next=NULL;
				while(i <pos-1){
					temp=temp->next;
					i++;
				}
				newnode->prev = temp;
				newnode->next = temp->next;
				temp->next = newnode;
				newnode->next->prev = newnode;			
				}
		}
		void deleteatbeg(){
			node* temp=head;
			if (head==0){
				cout<<"list empty";
			}
			else{
				head=head->next;
				head->prev=0;
				delete temp;
			}
		}
		void deleteatend(){
			node* temp=tail;
			if(tail==0){
				cout<<"list empty";
			}
			else{
				tail->prev->next=0;
				tail->prev=tail;
				delete temp;
			}
		}
		void display(){
			node* temp=head;
			while(temp!=0){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
};

/*#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class doubleylinkedlist {
private:
    node* head;
    node* tail;

public:
    doubleylinkedlist() {
        head = NULL;
        tail = NULL;
    }

    void insertatbegg(int value) {
        node* newnode = new node(value);
        newnode->prev = NULL;
        newnode->next = head;
        if (head != 0) {
            head->prev = newnode;
        }
        head = newnode;
        if (tail == 0) {
            tail = newnode;
        }
    }

    void insertatend(int value) {
        node* newnode = new node(value);
        newnode->prev = tail;
        newnode->next = 0;
        
        if (tail == 0) {
            head = newnode;
        } else {
            tail->next = newnode;
        }
        tail = newnode;
    }

    void insertatpos(int value) {
        int pos;
        int i = 1;
        cout << "Enter the position: ";
        cin >> pos;
        if (pos < 1) {
            cout << "Invalid position." << endl;
        } else if (pos == 1) {
            insertatbegg(value);
        } else {
            node* newnode = new node(value);
            node* temp = head;
            newnode->prev = tail;
            newnode->next = NULL;
            while (i < pos - 1) {
                temp = temp->next;
                i++;
            }
            newnode->prev = temp;
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->next->prev = newnode;
        }
    }

    void delatbegg() {
        node* temp = head;
        if (head == 0)
            cout << "List is empty" << endl;
        else {
            head = head->next;
            head->prev = 0;
            delete temp;
        }
    }

    void delatend() {
        node* temp = tail;
        if (tail == 0)
            cout << "List is empty" << endl;
        else {
            tail->prev->next = 0;
            tail = tail->prev;
            delete temp;
        }
    }

    void delatpos() {
        int pos, i = 1;
        node* temp = head;
        cout << "Enter the position: ";
        cin >> pos;
        if (pos < 1) {
            cout << "Invalid position." << endl;
        } else if (pos == 1) {
            delatbegg();
        } else {
            while (i < pos) {
                temp = temp->next;
                i++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    void display() {
        node* temp = head;
        while (temp != 0) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    doubleylinkedlist mylist;
    int choice, value;

    while (true) {
        cout << "DOUBLY LINKED LIST MENU:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a specific position" << endl;
        cout << "4. Delete at the beginning" << endl;
        cout << "5. Delete at the end" << endl;
        cout << "6. Delete at a specific position" << endl;
        cout << "7. Display the linked list" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to insert at the beginning: ";
            cin >> value;
            mylist.insertatbegg(value);
            break;
        case 2:
            cout << "Enter the value to insert at the end: ";
            cin >> value;
            mylist.insertatend(value);
            break;
        case 3:
            cout << "Enter the value to insert at a specific position: ";
            cin >> value;
            mylist.insertatpos(value);
            break;
        case 4:
            mylist.delatbegg();
            break;
        case 5:
            mylist.delatend();
            break;
        case 6:
            mylist.delatpost();
            break;
        case 7:
            cout << "DOUBLY LINKED LIST: ";
            mylist.display();
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
*/
