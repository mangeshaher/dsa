/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

class Node{
public:
	int data;
	Node* next;
};

void push(Node** head,int value){
	Node* node = new Node();
	node->data = value;
	node->next=(*head);//even if it is null it will manage
	*head = node;
}

void insertAfter(Node* prev,int value){
	Node* node = new Node();
	node->data = value;
	if(prev!=NULL){
		node->next=prev->next;
		prev->next=node;
	}
	else{
		cout<<"Previous node not available";
	}
}

void append(Node** head,int value){
	Node* node = new Node();
	node->data = value;
	node->next = NULL;
	if(*head==NULL){
		*head = node;
	}
	else{
		Node* temp = *head;
		while(temp->next!=NULL){
			temp = temp -> next;
		}
		temp -> next = node;
	}
}

void printList(Node* head){
	if(head!=NULL){
		while(head->next!=NULL){
			cout<<head->data<<"->";
			head=head->next;
		}
		cout<<head->data<<"---)";
	}
}

// Driver program 
int main() 
{ 
	int n;
 	cin>>n;
 	Node* head = NULL;
 	for(int i=0;i<n;i++){
 		append(&head,i);
 	}
 	insertAfter(head->next,8);
 	push(&head,9);
 	printList(head);
} 

