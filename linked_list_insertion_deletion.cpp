/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

class Node{
public:
	int data;
	Node* next;
};

class DNode{
public:
	int data;
	Node* next;
	Node* prev;
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

void deleteAtStart(Node** head){
	if(*head == NULL){
		cout<<"Nothing to delete at start \n";
	}
	else{
		Node* start = *head;
		*head = start-> next;
		free(start);
	}
}

void deleteAtEnd(Node** head){
	if(*head == NULL){
		cout<<"Nothing to delete as head is NULL\n";
	}
	else if((*head)->next == NULL){
		Node* firstLast = *head;
		free(firstLast);
		*head = NULL;
	}
	else{
		Node* prev = *head;
		Node* temp = prev->next;
		while(temp->next!=NULL){
			prev = prev->next;
			temp = temp->next;
		}
		Node* last = temp;
		free(last);
		prev->next=NULL;
	}	
}

void deleteKey(Node** head,int key){
	if(*head == NULL){
		cout<<"Nothing to delete as head is NULL\n";
	}
	else if((*head)->next == NULL){
		Node* firstLast = *head;
		if(firstLast->data == key){
			free(firstLast);
			*head = NULL;
		}
		else{
			cout<<"Key not found for deletion";
		}
	}
	else{
		Node* prev = *head;
		Node* temp = prev->next;
		while(temp->next!=NULL){
			if(temp->data == key){
				prev->next=temp->next;
				free(temp);
				break;
			}
			prev = prev->next;
			temp = temp->next;
		}
	}	
}

void printList(Node* head){
	if(head!=NULL){
		while(head->next!=NULL){
			cout<<head->data<<"->";
			head=head->next;
		}
		cout<<head->data<<"---)\n";
	}
	else{
		cout<<"Nothing to print as HEAD is NULL\n";
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
	deleteAtStart(&head);
	deleteAtEnd(&head);
	deleteKey(&head,8);
	printList(head);
} 

