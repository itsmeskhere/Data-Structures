//Heterogenous Singly Linked List

#include<iostream>
using namespace std;

struct node {
	int idata;
	char cdata;
	node *next;
};

struct node {
    int type_indicator;
    union {
        float f;
        int i;
        double d;
        void *p;
        char c;
    }
    node *next;
};


class HSLL{
	private:
    		node *head; 
    		//node *tail;
    	public:
    		HSLL(){
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
		    			cout<<temp->cdata<<"  ";
		    		cout<<"\n";
		    		temp = temp->next;
		    	}
		}

		void insert(char cvalue, int ivalue, int pos){
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
		    			if(len < pos){
		    				prev = prev->next;
		    			}
		    		}
		    		if(pos == len+1){
		    			insert(ivalue, cvalue, -1);
		    		}
		    		else if(pos < -1){
		    			insert(ivalue, cvalue, len+pos+2);
		    		}
		    		else if(pos > len){
		    			cout<<"\nInvalid Position!";
		    			display();
		    		}
		    	}
		}
};

int main(){
	HSLL l;
	l.insert(0,0);
	l.insert('a',1);
	l.insert('b',2,2);
	l.insert(3,-1);
	l.insert('c',4,-1);
	l.insert(5,-2);
	return 0;
}
