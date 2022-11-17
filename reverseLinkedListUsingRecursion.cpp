#include <stdlib.h>
#include <stdio.h>

//Linked List: Inserting a node at beginning
struct Node{
	int data;
	struct Node* next;
};

struct Node* head;

void Insert(int data, int n){
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
	temp1 -> data = data;
	temp1 ->next = NULL;
	if(n == 1){
		temp1 ->next = head;
		head = temp1;
		return;
	}
	Node* temp2 = head;
	for(int i=0;i<n-2;i++){
		temp2 = temp2->next;
	}	
	temp1 ->next = temp2->next;
	temp2 ->next = temp1;
}

void Print(struct Node* p){
	if (p == NULL){
		printf("\n");
		return;
	}
	printf("%d" ,p->data);
	Print(p->next);
}

void Reverse(struct Node* p){
	if (p->next == NULL){  //Exit condition
		head = p;
		return;
	}
	Reverse(p->next);
	struct Node* q = p->next;
	q->next = p;
	p->next = NULL;
}

int main(){
	Insert(2,1); //List 2
	Insert(3,2); //List 2,3
	Insert(4,1); //List 4,2,3
	Insert(5,2); //List 4,5,2,3
	Print(head);
	Reverse(head);
	Print(head);
}
