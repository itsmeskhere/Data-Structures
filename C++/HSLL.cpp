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
		    		len++;
		    		if(pos == len){
		    			insertNode(value, -1);
		    		}
		    		else if(pos < -1){
		    			insertNode(value, len+pos);
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
				int len = -1;
				bool flag = false; 
				while(curr->next != NULL){
					if(pos == len){
						cout<<"\n"<<curr->data<<" Deleted!";
						prev->next = curr->next;
						delete curr;
						flag = true;
						display();
						break;
					}
					len++;
					prev = curr;
					curr = curr->next;
				}
				len++;
				if(!flag){
					if(pos == len){
						cout<<"\n"<<curr->data<<" Deleted!";
						prev->next = curr->next;
						delete curr;
						display();
					}
					else if(pos == -1){
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
		}
		
		void deleteNodeValue(int value){
			node *curr = new node;
			node *prev = new node;
			curr = head;
			int len = 0;
			bool flag = false;
			while(curr->next != NULL){
				if(curr->data == value){
					cout<<"\nNode "<<len<<" Deleted!";
					if(len == 0){
						head = head->next;
						delete curr;
						flag = true;
					}
					else{
						prev->next = curr->next;
						delete curr;
						flag = true;
					}
				}
				len++;
				prev = curr;
				curr = curr->next;
			}
			len++;
			if(!flag){
				if(curr->data == value){
					cout<<"\n"<<curr->data<<" Deleted!";
					prev->next = curr->next;
					delete curr;
				}
				else{
					cout<<"\n"<<value<<" not Found!";
				}
				display();
			}
		}
		
		void swapNode(node *A, node *B){
			int temp;
			temp = A->data;
			A->data = B->data;
			B->data = temp;
		}
		
		void sortList(int order){
			node *temp = new node;
			temp = head;
			int len = 0;
			while(temp->next != NULL){
				len++;
				temp = temp->next;
			}
			len++;
			if(len > 1){
				node *cur = new node;
				node *nex = new node;
				for(int i = 0; i < len; i++){
					cur = head;
					nex = head->next;
					bool flag = false;
					while(cur->next != NULL){
						if((order == 1 && cur->data > nex->data) || (order == -1 && cur->data < nex->data)){
							swapNode(cur, nex);
							flag = true;
						}
						cur = nex;
						nex = nex->next;
					}
					if(!flag){
						break;
					}
				}
				cout<<"\nList Sorted!";
				display();	
			}
		}
};

int main(){
	SLL l;
	l.insertNode(5,0);
	l.insertNode(4,1);
	l.insertNode(3,2);
	l.insertNode(2,3);
	l.insertNode(1,4);
	l.insertNode(0,5);
	//l.deleteNode(5);
	//l.deleteNode(4);
	//l.deleteNodeValue(0);
	//l.deleteNodeValue(3);
	//l.deleteNodeValue(6);
	//l.deleteNodeValue(5);
	l.sortList(1);
	l.sortList(-1);
	return 0;
}
