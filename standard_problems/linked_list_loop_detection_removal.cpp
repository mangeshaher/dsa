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

/*
Let there be a nodes before loop start
Let the two pointers meet after k steps after loop begins
Let the cycle be of n nodes
Distance travelled by slow be :- a + x*n + k
Distance travelled by fast be :- a + y*n + k
Distance travelled by fast is 2* dustance travelled by slow
a + y*n + k = 2 * (a + x*n + k)
(y-2*x)*n = a + k
So the point to highlight is a+k is multiple of n
If fast travels from meeting point and slow travels from head
after a steps of slow fast would have completed k+a steps from beginning of cycle
thus fast will complete cycle and slow will begin cycle 
and hence they will always meet at starting point of cycle
*/
Node* removeLoop(Node* head){
	Node* slow = head;
	Node* fast = head;
	Node* meetPoint;
	while(slow&&fast&&fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast){
			meetPoint = slow;
			break;
		}
	}
	slow = head;
	while(slow->next!=meetPoint->next){
		slow=slow->next;
		meetPoint=meetPoint->next;
	}
	meetPoint->next=NULL;
	return head;
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
	printList(head);
} 