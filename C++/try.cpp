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
    		
		node* getHead(){
			return head;
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
		    			if(pos == len){
		    				temp->next = prev->next;
		    				prev->next = temp;
		    				cout<<"\nInsert Success!";
		    				display();
		    				break;
		    			}
		    			len++;
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
	SLL l, a, b, c;
//	l.insertNode(-1,0);
//	l.insertNode(-10,1);
//	l.insertNode(0,2);
//	l.insertNode(-1,3);
//	l.insertNode(1,4);
//	l.insertNode(1,5);
//	l.insertNode(0,6);
//	l.insertNode(2,7);
//	l.display();
//	l.maxNode();
//	l.minNode();
//	l.frequencyList();
//	l.display();
	a.insertNode(-1,-1);
	a.insertNode(-2,-1);
	a.insertNode(-3,-1);
	b.insertNode(1,-1);
	b.insertNode(2,-1);
	b.insertNode(3,-1);
	//c.mergeList(a.head, b.head);
	c.mergeList(a.getHead(), b.getHead());
}
