//Heterogenous Singly Linked List

#include<iostream>
using namespace std;

struct node {
	int idata;
	char cdata;
	node *next;
};

class list {
	private:
    		node *head; 
    		//node *tail;
    	public:
    		list(){
      			head = NULL;
      			//tail = NULL;
    		}

		void display(){
		    	node *temp = new node;
		    	temp = head;
		    	cout<<"\nList\n";
		   	while(temp != NULL){
		   		if(temp->idata != NULL)
		    			cout<<temp->idata<<"  ";
		    		if(temp->cdata != NULL)
		    			cout<<temp->idata<<"  ";
		    		cout<<"\n";
		    		temp = temp->next;
		    	}
		}

		void insert(int ivalue, char cvalue, int pos){
		    	node *temp = new node;
		    	temp->idata = ivalue;
		    	temp->cdata = cvalue;
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
		    			}
		    			prev = prev->next;
		    		}
		    		if(pos == len+1){
		    			insert(value, -1);
		    		}
		    		else if(pos < -1){
		    			insert(value, len+pos+2);
		    		}
		    		else if(pos > len){
		    			cout<<"\nInvalid Position!";
		    			display();
		    		}
		    	}
		}
};

int main(){
	list l;
	l.insert(0,0);
	l.insert(1,1);
	l.insert(-1,-1);
	l.insert(2,3);
	l.insert(3,4);
	l.insert(0,-4);
	return 0;
}
