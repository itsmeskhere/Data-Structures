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
				node *curr = new node;
				node *next = new node;
				for(int i = 0; i < len; i++){
					curr = head;
					next = head->next;
					bool flag = false;
					while(curr->next != NULL){
						if((order == 1 && curr->data > next->data) || (order == -1 && curr->data < next->data)){
							swapNode(curr, next);
							flag = true;
						}
						curr = next;
						next = next->next;
					}
					if(!flag){
						break;
					}
				}
				cout<<"\nList Sorted!";
				display();	
			}
		}
		
		void reverseList(){
			node *curr = head;
			node *prev = NULL;
			node *next = NULL;
			while(curr != NULL){
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			head = prev;
			display();
		}
		
		void nthNode(int n){
			int i = 0;
			bool flag = false;
			node *temp = new node();
			temp = head;
			while(temp != NULL){
				i++;
				if(i == n){
					cout<<"\nNode "<<n<<": "<<temp->data;
					flag = true;
					break;
				}
				temp = temp->next;
			}
			if(!flag){
				cout<<"\nOut of Range of List";
			}
		}
		
		void searchNode(int n){
			int i = 0;
			bool flag = false;
			node *temp = new node();
			temp = head;
			while(temp != NULL){
				i++;
				if(temp->data == n){
					cout<<"\nNode "<<i;
					flag = true;
					break;
				}
				temp = temp->next;
			}
			if(!flag){
				cout<<"\n"<<n<<" is not in List";
			}
		}
		
		void maxNode(){
			int max = -999999999;
			node *temp = new node();
			temp = head;
			while(temp != NULL){
				if(max < temp->data){
					max = temp->data;
				}
				temp = temp->next;
			}
			if(temp == NULL){
				cout<<"\nMax Node: "<<max;
			}
		}
		
		void minNode(){
			int min = 999999999;
			node *temp = new node();
			temp = head;
			while(temp != NULL){
				if(min > temp->data){
					min = temp->data;
				}
				temp = temp->next;
			}
			if(temp == NULL){
				cout<<"\nMin Node: "<<min;
			}	
		}
		
		void frequencyList(){
			cout<<"\nFrequency Table";
			int max = -999999999;
			int min = 999999999;
			node *temp = new node();
			temp = head;
			while(temp != NULL){
				if(min > temp->data){
					min = temp->data;
				}
				if(max < temp->data){
					max = temp->data;
				}
				temp = temp->next;
			}
			
			min*=-1;
			int pos[max+1] = {0};
			int neg[min+1] = {0};
			if(max == -999999999){
				max = 0;
			}
			if(min == -999999999){
				min = 0;
			}
			
			temp = head;
			while(temp != NULL){
				if(temp->data >= 0){
					pos[temp->data]++;
				}
				else if(temp->data < 0){
					int x;
					x = temp->data;
					x*=-1;
					neg[x]++;
				}
				temp = temp->next;
			}
			for(int i = min; i > 0; i--){
				if(neg[i] != 0){
					cout<<"\n-"<<i<<"==>"<<neg[i];
				}
			}
			for(int i = 0; i < max+1; i++){
				if(pos[i] != 0){
					cout<<"\n"<<i<<"==>"<<pos[i];
				}
			}
		}
		
		void mergeList(node* a, node* b){
			while(a != NULL || b != NULL){
				if(a != NULL){
					insertNode(a->data, -1);
					a = a->next;
				}
				if(b != NULL){
					insertNode(b->data, -1);
					b = b->next;
				}
			}
			cout<<"\nMerged List";
			display();
		}
};



int main(){
	SLL l;
	l.insertNode(5,0);
	l.insertNode(4,1);
	l.insertNode(3,2);
	l.insertNode(0,3);
	l.insertNode(1,4);
	l.insertNode(2,5);
	//l.deleteNode(5);
	//l.deleteNode(4);
	//l.deleteNodeValue(0);
	//l.deleteNodeValue(3);
	//l.deleteNodeValue(6);
	//l.deleteNodeValue(5);
	//l.sortList(1);
	//l.sortList(-1);
	//l.reverseList();
	//l.reverseList();
	//l.nthNode(0);
	//l.nthNode(3);
	//l.nthNode(6);
	//l.nthNode(7);
	//l.nthNode(10);
	l.searchNode(0);
	l.searchNode(1);
	l.searchNode(4);
	l.searchNode(5);
	l.searchNode(10);
	l.maxNode();
	l.minNode();
	l.frequencyList();
	l.display();
	return 0;
}
