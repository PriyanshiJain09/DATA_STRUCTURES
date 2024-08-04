#include <iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node(int value): data(value), next(NULL) {}
};
class linkedlist{
	private:
		node* head;
	public:
		linkedlist() : head(NULL) {}
		void insertatbeg(int value){
			node* newnode= new node(value);
			newnode->next=head;
			head=newnode;
		}
		void insertatend(int value){
			node* newnode= new node(value);
			if(!head){
				head=newnode;
			}
			else{
				node* temp=head;
				while(temp->next){
					temp=temp->next;
				}
				temp->next=newnode;
			}
		}
		void insertatpos(int value , int position){
			if(position<0){
				cout<<"invalid position"<<endl;
			}
			else if(position==0){
				insertatbeg(value);
			}
			else{
				node* newnode= new node(value);
				node* current=head;
				int currentposition=1;
				while(current && currentposition <position){
					current=current->next;
					currentposition++;
				}
				if(!current || !current->next){
					cout<<"invalid position"<<endl;
				}
				else{
					newnode->next=current->next;
					current->next=newnode;
				}
			}
		}
		void deleteatbeg(){
			node* temp=head;
			if(!head){
				cout<<"list is empty"<<endl;
			}
			else{
				cout<<"element deleted"<<endl;
				head=head->next;
				delete temp;
			}
		}
		void deleteatend(){
			if(!head){
				cout<<"list is empty"<<endl;
			}
			else if(!head->next){
				delete head;
				head=NULL;
			}
			else{
				node* temp=head;
				while(temp->next->next){
					temp=temp->next;
				}
				delete temp->next;
				temp->next=NULL;
			}
			cout<<"element deleted"<<endl;
		}
		void deleteatpos(int position){
			if(position<0){
				cout<<"invalid position"<<endl;
			}
			else if(position==0){
				deleteatbeg();
			}
			else{
				node* current=head;
				int currentposition=1;
				while(current && currentposition <position){
					current=current->next;
					currentposition++;
				}
				if(!current || !current->next){
					cout<<"invalid position"<<endl;
				}
				else{
					node* temp= current->next;
					current->next= temp->next;
					delete temp;
				}
			}
		}
		void reverse(){
			if(!head){
				cout<<"List is empty"<<endl;
			}
			node* prevnode=NULL;
			node* currentnode=head;
			node* nextnode;
			while(currentnode){
				nextnode=currentnode->next;
				currentnode->next=prevnode;
				prevnode=currentnode;
				currentnode=nextnode;
			}
			head=prevnode;
			cout<<"linkedlist reversed !!"<<endl;
			display();
		}
		void search(int value){
			if(!head){
				cout<<"List is empty"<<endl;
			}
			node* current=head;
			while(current){
				if(current->data==value){
					cout<<"element found"<<endl;
				}
				current=current->next;
			}
		}
		int countnodes(){
			int count=0;
			node* current=head;
			if(!head){
				cout<<"list is empty"<<endl;
			}
			else{
				while(current){
					count++;
					current=current->next;
				}
				cout<<"number of nodes are :"<<count<<endl;
			}
		}
		int display(){
			if(!head){
				cout<<"list is empty"<<endl;
			}
			node* current=head;
			while(current){
				cout<<current->data<<" ";
				current=current->next;
			}
			cout<<endl;
		}
};

int main() {
    linkedlist mylist;

    int choice, value, position;

    do {
        cout << "====MENU====" << endl;
        cout << "1. Insert at the Beginning" << endl;
        cout << "2. Insert at the End" << endl;
        cout << "3. Insert at a Specific Position" << endl;
        cout << "4. Delete at the Beginning" << endl;
        cout << "5. Delete at the End" << endl;
        cout << "6. Delete at a Specific Position" << endl;
        cout << "7. Reverse the List" << endl;
        cout << "8. Display the List" << endl;
        cout << "9. Search for an Element" << endl;
        cout << "10. Count Nodes" << endl;
        cout << "11. Exit" << endl;
        cout << "============" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert at the beginning: ";
                cin >> value;
                mylist.insertatbeg(value);
                break;
            case 2:
                cout << "Enter the value to insert at the end: ";
                cin >> value;
                mylist.insertatend(value);
                break;
            case 3:
                cout << "Enter the value to insert: ";
                cin >> value;
                cout << "Enter the position: ";
                cin >> position;
                mylist.insertatpos(value, position);
                break;
            case 4:
                mylist.deleteatbeg();
                break;
            case 5:
                mylist.deleteatend();
                break;
            case 6:
            	cout << "Enter the position: ";
                cin >> position;
                mylist.deleteatpos(position);
                break;
            case 7:
                mylist.reverse();
                break;
            case 8:
                cout << "LINKED LIST: ";
                mylist.display();
                break;
            case 9:
                cout << "Enter the value to search: ";
                cin >> value;
                mylist.search(value);
                break;
            case 10:
                mylist.countnodes();
                break;
            case 11:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid option" << endl;
        }
    } while (choice != 11);

    return 0;
}

