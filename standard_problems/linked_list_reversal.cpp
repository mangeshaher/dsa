/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

class Node{
public:
	int data;
	Node* next;
};

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
		cout<<head->data<<"---)\n";
	}
	else{
		cout<<"Nothing to print as HEAD is NULL\n";
	}
}


//current     mid     next
// 1      ->   2  ->   3   ->   4 -> NULL
Node* reverse(Node* head){
	Node* current = head;
	Node* mid = current->next;
	current->next = NULL;
	while(mid!=NULL){
		Node* next = mid->next;
		mid->next = current;
		current = mid;
		mid = next;
	}
	return current;
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
	printList(head);
	head = reverse(head);
	printList(head);
} 