/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

class DNode{
public:
	int data;
	DNode* next;
	DNode* prev;
};

void append(DNode** head,int value){
	DNode* new_node = new DNode();
	new_node -> data = value;
	new_node->next = NULL;
	if(*head == NULL){
		new_node->prev = NULL;
		*head = new_node;
	}
	else{
		DNode* temp = *head;
		while(temp->next!=NULL){
			temp = temp ->next;
		}
		temp->next = new_node;
		new_node -> prev = temp;
	}
}

void push(DNode** head,int value){
	DNode* new_node = new DNode();
	new_node -> data = value;
	new_node->prev = NULL;
	new_node->next = *head;
	if(*head != NULL){
		(*head)->prev = new_node;
	}
	*head = new_node;	
}

void printList(DNode* head){
	if(head!=NULL){
		DNode* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"---)\n";
	}
	else{
		cout<<"Nothing to print as head is NULL\n";
	}
}

void insertAfter(DNode* node, int value){
	DNode* new_node = new DNode();
	new_node -> data = value;
	new_node -> prev = node;
	DNode* next_node = node -> next;
	new_node -> next = next_node;
	if(next_node!=NULL){
		next_node -> prev = new_node;
	}
}

void insertBefore(DNode** head, DNode* node, int value){
	DNode* new_node = new DNode();
	new_node -> data = value;
	new_node -> next = node;
	DNode* prev_node = node->prev;
	node -> prev = prev_node;
	if(prev_node == NULL){
		*head = node;
	}
	else{
		prev_node -> next = node;
	}
}

// Driver program 
int main() 
{ 
    int n;
	cin>>n;
	DNode* head = NULL;
	for(int i=0;i<n;i++){
		append(&head,i);
	}
	//insertAfter(&head,20,8);
	//push(&head,9);
	printList(head);
	//deleteAtStart(&head);
	//deleteAtEnd(&head);
	//deleteAfter(&head,2,8);
	//printList(head);
} 