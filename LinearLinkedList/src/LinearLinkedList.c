/*
 ============================================================================
 Name        : LinearLinkedList.c
 Author      : Shivam Palaskar
 Version     :
 Copyright   : Open source
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *nextPtr;
}NODE;

struct Node* createNode(int);
struct Node* getLastNode();
struct Node* get2ndLastNode();
void addNodeAtLast(int);
void addNodeAtFirst(int);
void addNodeAtGivenPos(int,int);
int isEmpty();
int getLength();
int verifyPos(int);
void delFirst();
void delLast();
void delAtPos(int);
void displayNodes();
int getData();

struct Node *head = NULL;

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int choice, num,pos;
	do {
		printf("\nChose operation to perform : ");
		printf("\n1) Add at First Position");
		printf("\n2) Add at Last Position");
		printf("\n3) Add at given Position");
		printf("\n4) Display");
		printf("\n5) Delete First");
		printf("\n6) Delete Last");
		printf("\n7) Delete at Given Position");
		printf("\n8) Delete All");
		printf("\n9) Length");
		printf("\n10)Exit");
		printf("\n Enter Choice : ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			num = getData();
			addNodeAtFirst(num);
			printf("\n Added Successfully");
			break;
		case 2:
			num = getData();
			addNodeAtLast(num);
			printf("\n Added Successfully");
			break;
		case 3:
			printf("\n Enter Position Number : ");
			scanf("%d",&pos);
			if (verifyPos(pos)) {
				num = getData();
				addNodeAtGivenPos(num,pos);
				printf("\n Added Successfully at %d Position", pos);
			}else
				printf("\n Invalid Position");
			break;
		case 4:
			if(isEmpty())
				printf("\nLinked List is Empty");
			else
				displayNodes();
			break;
		case 5:
			if (isEmpty())
				printf("\nLinked List is Empty");
			else {
				delFirst();
				printf("\n Successfully Deleted");
			}
			break;
		case 6:
			if (isEmpty())
				printf("\nLinked List is Empty");
			else {
				delLast();
				printf("\n Successfully Deleted");
			}
			break;
		case 7:
			if (isEmpty())
				printf("\nLinked List is Empty");
			else {
				printf("\n Enter Position Number : ");
				scanf("%d", &pos);
				if (verifyPos(pos)) {
					delAtPos(pos);
					printf("\n Successfully Deleted");
				} else
					printf("\n Invalid Position");
			}
			break;
		case 8:
			if (isEmpty())
				printf("\nLinked List is Empty");
			else {
				head=NULL;
				printf("\n Successfully Deleted");
			}
			break;
		case 9:
			printf("\n Length : %d",getLength());
		}
	} while (choice != 10);
	return EXIT_SUCCESS;
}

void delFirst(){
	head = head->nextPtr;
}

void delLast(){
	if(getLength()==1)
		head=NULL;
	else {
		struct Node* sndLastNode;
		sndLastNode = get2ndLastNode();
		printf("\n last node data : %d",sndLastNode->data);
		sndLastNode->nextPtr = NULL;
	}
	/*printf("\n &lastNode : %u",&lastNode);
	printf("\n lastNode : %d",*lastNode);
	printf("\n lastNode->data : %d",lastNode->data);
	printf("\n lastNode->nextPtr : %u",lastNode->nextPtr);
	lastNode--;
	printf("\n &lastNode : %u",&lastNode);
	printf("\n lastNode : %d",*lastNode);
	printf("\n lastNode->data : %d",lastNode->data);
	printf("\n lastNode->nextPtr : %u",lastNode->nextPtr);*/
}

void delAtPos(int pos) {
	struct Node* tempPtr;
	tempPtr = head;
	if(pos==1){
		delFirst();
		return;
	} else {
		while ((--pos) > 1) {   // this will give (position-1)th index
			tempPtr = tempPtr->nextPtr;
		}
		if (pos == 1) {
			tempPtr->nextPtr = (tempPtr->nextPtr)->nextPtr;
		}
	}
}

int isEmpty(){
	if(head==NULL)
		return 1;
	else
		return 0;
}

int getData(){
	int num;
	printf("\n Enter Number : ");
	scanf("%d",&num);
	return num;
}

struct Node* createNode(int num){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = num;
	newNode->nextPtr=NULL;
	return newNode;
}

void addNodeAtFirst(int num) {
	struct Node* newNode;
	struct Node* tempPtr;
	newNode = createNode(num);
	if (head == NULL)
		head = newNode;
	else {
		tempPtr = head;
		head = newNode;
		newNode->nextPtr = tempPtr;
	}
}
void addNodeAtLast(int num){
	struct Node* newNode;
	struct Node* tempPtr;
	newNode = createNode(num);
	if(head == NULL)
		head = newNode;
	else{
		tempPtr = getLastNode();
		printf("\n last node data : %d",tempPtr->data);
		tempPtr->nextPtr = newNode;
	}
}

int verifyPos(int pos){
	if (pos > 0 && pos <= getLength())
		return 1;
	else
		return 0;
}

void addNodeAtGivenPos(int num,int pos){
	struct Node* newNode;
	struct Node* tempPtr;
	newNode=createNode(num);
	tempPtr = head;
		if (pos == 1) {
			addNodeAtFirst(num);
			return;
		}
		while ((--pos) > 1) {  // this will give (position-1)th index
			tempPtr = tempPtr->nextPtr;
		}
		if (pos == 1) {
			newNode->nextPtr = tempPtr->nextPtr;
			tempPtr->nextPtr = newNode;
		}
	return;
}

int getLength() {
	struct Node* tempPtr = head;
	int len=0;
	while (tempPtr != NULL) {
		len++;
		tempPtr = tempPtr->nextPtr;
	}
	return len;
}

struct Node* getLastNode(){
	struct Node* tempPtr;
	tempPtr=head;
	struct Node *lastNode;
	while(tempPtr!=NULL){
		lastNode = tempPtr;
		tempPtr = tempPtr->nextPtr;
	}
	return lastNode;
}

struct Node* get2ndLastNode(){
	struct Node* tempPtr=head;
	struct Node *sndLastNode=head;
		while ((tempPtr->nextPtr) != NULL) {
			sndLastNode = tempPtr;
			tempPtr = tempPtr->nextPtr;
		}
	return sndLastNode;
}

void displayNodes(){
	struct Node* tempPtr;
	tempPtr=head;
	while(tempPtr!=NULL){
		printf("%d ",tempPtr->data);
		tempPtr = tempPtr->nextPtr;
	}
}

/*
struct Node* createNode(int num){ // We can't create new node like this because new node will be created as local variable
	struct Node newNode;
	newNode.data = num;
	newNode.nextPtr = NULL;
	printf("\n &newNode : %u",&newNode);
	printf("\n newNode : %u",newNode);
	printf("\n &newNode.data : %u",&newNode.data);
	return &newNode;
}*/
