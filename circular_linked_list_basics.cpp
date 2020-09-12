/*Created by Mangesh Aher*/
#include <bits/stdc++.h> 
using namespace std; 

class Node{
public:
	int data;
	Node* next;
};

void append(Node** last,int value){
	Node* node = new Node();
	node->data = value;
	if(*last==NULL){
		*last = node;
		(*last)->next=*last;
	}
	else{
		node->next=(*last)->next;
		(*last)->next = node;
		(*last) = node;
	}
}

void push(Node** last,int value){
	Node* node = new Node();
	node->data = value;
	if((*last)!=NULL){
		node->next=(*last)->next;
		(*last)->next = node;
	}
	*last = node;
}

void insertAfter(Node** last,int data,int value){
	int flag = 0;
	Node* node = new Node();
	node->data = value;
	if((*last)==NULL){
		cout<<"Empty list -- no node to search and insert after\n";
	}
	else{
		Node* temp = (*last)->next;
		while(temp!=(*last)){
			if(temp->data==data){
				node -> next = temp->next;
				temp->next = node;
				flag = 1;
				break;
			}
			temp = temp -> next;
		}	
		if((*last)->data == data){
			node -> next = (*last)->next;
			(*last)->next = node;
			*last = node;
			flag = 1;
		}
		if(flag==0){
			cout<<"No Node found with searched data value\n";
		}
	}
}

void deleteAtStart(Node** last){
	if(*last == NULL){
		cout<<"Nothing to delete at start \n";
	}
	else{
		Node* start = (*last)->next;
		(*last) -> next = start -> next;
		free(start);
	}
}

void deleteAtEnd(Node** last){
	if(*last == NULL){
		cout<<"Nothing to delete at end \n";
	}
	else{
		Node* temp = (*last)->next;
		while(temp->next!=*last){
			temp=temp->next;
		}
		temp->next = (*last)->next;
		free(*last);
		*last = temp;
	}
}

void deleteAfter(Node** last,int data,int value){
	if(*last == NULL){
		cout<<"Nothing to delete \n";
	}
	else{
		int flag = 0;
		Node* temp = (*last)->next;
		while(temp!=(*last)){
			if(temp->data==data){
				Node* toDelete = temp->next;
				temp->next = toDelete -> next;
				free(toDelete);
				flag = 1;
				break;
			}
			temp = temp -> next;
		}	
		if(temp->data == data){
			Node* toDelete = temp->next;
			temp->next = toDelete -> next;
			free(toDelete);
			flag = 1;
		}
		if(flag==0){
			cout<<"No Node found with searched data value\n";
		}
	}
}

void printList(Node* last){
	if(last!=NULL){
		Node* temp = last;
		while(temp->next!=last){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<temp->data<<"---loop---\n";
	}
	else{
		cout<<"Nothing to print as last is NULL\n";
	}
}

// Driver program 
int main() 
{
	int n;
	cin>>n;
	Node* last = NULL;
	for(int i=0;i<n;i++){
		append(&last,i);
	}
	insertAfter(&last,20,8);
	push(&last,9);
	printList(last);
	deleteAtStart(&last);
	deleteAtEnd(&last);
	deleteAfter(&last,2,8);
	printList(last);
}