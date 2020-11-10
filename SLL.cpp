//Singly Linked List

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};



void insert(Node** head, int data, int pos){
	Node* newNode = new Node();
	newNode -> data = data;
	newNode -> next = NULL;
	
	if(pos==0){
		newNode -> next = *head;
		*head = newNode;
		cout<<"Success!";
		return;
	}
	else if(pos==-1){
		Node *last = *head;
		
		if(*head == NULL)
		{
			*head = newNode;
			return;
		}
		
		while(last -> next != NULL)
		{
			last = last -> next;
		}
		last -> next = newNode;
		cout<<"Success!";
		return;
	}
	else{
		Node *temp = *head;
		int len = -1;
		
		while(temp -> next != NULL){
			len++;
			if(pos == len){
				newNode -> next = temp -> next;
				temp -> next = newNode;
				cout<<"Success!";
				return;
			}
			temp = temp -> next;
		}
		
		if(pos == len+1){
			insert(&head, data, -1);
			return;
		}
		else if(pos > len){
			cout<<"Invalid position!";
		}
	}
}

int main()
{
	
}

