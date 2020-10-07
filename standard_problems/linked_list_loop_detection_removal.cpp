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

bool detectLoop(Node* head){
	Node* slow = head;
	Node* fast = head;
	bool flag = false;
	while(slow&&fast&&fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast){
			flag=true;
			break;
		}
	}
	return flag;
}

Node* removeLoop(Node* head){

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
	Node* last = head;
	while(last->next!=NULL){
		last=last->next;
	}
	last->next = head->next->next;
	cout<<detectLoop(head)<<endl;
	head = removeLoop(head);
} 