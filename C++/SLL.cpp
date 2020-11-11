//Singly Linked List

#include<iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

class SLL {
	private:
    		node *head; 
    		//node *tail;
    	public:
    		SLL(){
      			head = NULL;
      			//tail = NULL;
    		}

		void display(){
		    	node *temp = new node;
		    	temp = head;
		    	cout<<"\nList\n";
		   	while(temp != NULL){
		    		cout<<temp->data<<"  ";
		    		temp = temp->next;
		    	}
		}

		void insertNode(int value, int pos){
		    	node *temp = new node;
		    	temp->data = value;
		    	temp->next = NULL;
		    	
		    	if(head == NULL){
		    		head = temp;
				//tail = temp;
				//temp = NULL;
				cout<<"\nInsert Success!";
				display();
		    	}
			else if(pos == 0){
		    		temp->next = head;
		    		head = temp;
		    		cout<<"\nInsert Success!";
		    		display();
		    	} 
		    	else if(pos == -1){
		    		//tail->next = temp;
		    		//tail = temp;
		    		node *last = new node;
		    		last = head;
		    		while(last->next != NULL){
		    			last = last->next;
		    		}
		    		last->next = temp;
		    		cout<<"\nInsert Success!";
		    		display();
		    	}
		    	else {
		    		node *prev = new node;
		    		prev = head;
		    		int len = 0;
		    		while(prev->next != NULL){
		    			len++;
		    			if(pos == len){
		    				temp->next = prev->next;
		    				prev->next = temp;
		    				cout<<"\nInsert Success!";
		    				display();
		    				break;
		    			}
		    			prev = prev->next;
		    		}
		    		if(pos == len+1){
		    			insertNode(value, -1);
		    		}
		    		else if(pos < -1){
		    			insertNode(value, len+pos+2);
		    		}
		    		else if(pos > len){
		    			cout<<"\nInvalid Position!";
		    			display();
		    		}
		    	}
		}
		
		void deleteNode(int pos){
			if(pos == 0){
				node *temp = new node;
				temp = head;
				head = head->next;
				cout<<"\n"<<temp->data<<" Deleted!";
				delete temp;
				display();
			}
			else {
				node *curr = new node;
				node *prev = new node;
				curr = head;
				int len = 0;
				while(curr->next != NULL){
					if(pos == len){
						cout<<"\n"<<curr->data<<" Deleted!";
						prev->next = curr->next;
						delete curr;
						display();
						break;
					}
					len++;
					prev = curr;
					curr = curr->next;
				}
				if(pos == -1){
					cout<<"\n"<<curr->data<<" Deleted!";
					prev->next = NULL;
					delete curr;
					display();
				}
				else if(pos < -1){
		    			deleteNode(len+pos+1);
		    		}
				else if(pos > len){
		    			cout<<"\nInvalid Position!";
		    			display();
				}
			}
		}
};

int main(){
	SLL l;
	l.insertNode(0,0);
	l.insertNode(1,1);
	l.insertNode(2,2);
	l.insertNode(3,3);
	l.insertNode(4,4);
	l.insertNode(5,5);
	l.deleteNode(0);
	l.deleteNode(1);
	l.deleteNode(-1);
	l.deleteNode(-2);
	return 0;
}
