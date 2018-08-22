#include <iostream>
#include "list.h"

using namespace std;

LinkedList::LinkedList(){
	head = NULL;
	tail = NULL;
}

//new node will be added to end of the linked list
//if the linked list is empty the HEAD AND TAIL are equal to the NEW NODE
void LinkedList::create(int val){
	Node *new_node = new Node();
	new_node->data = val;
	new_node->next = NULL;
	if (head == NULL){
		head = new_node;
		tail = new_node;
		new_node = NULL;
	}else{
		tail->next = new_node;
		tail = new_node;
	}
}

int LinkedList::getTail(){
	return tail->data;
}

int LinkedList::getHeader() {
	return head->data;
}

void LinkedList::print() {
	for (Node * current = head; current != nullptr; current = current->next){
		cout << current->data << " | ";
	}
	system("pause");
}

void LinkedList::insert_at_start(int val) {
	Node * new_node = new Node();
	new_node->next = head;
	new_node->data = val;
	head = new_node;
}

void LinkedList::insert_at_end(int val) {
	Node *new_node = new Node();
	new_node->data = val;
	tail->next = new_node;
	tail = new_node;
}

void LinkedList::insert_at_position(int pos, int val) {
	Node *new_node = new Node();
	Node *current_node = new Node();
	Node *previous_node = new Node();
	current_node = head;

	for (int i = 0; i < pos; i++)
	{
		previous_node = current_node;
		current_node = current_node->next;
	}
	new_node->data = val;
	new_node->next = current_node;
	previous_node->next = new_node;
}

void LinkedList::delete_at_start(){
	if (head == nullptr){
		cout << "Nothing to delete";
	}else{
		Node *temp = new Node();
		temp = head;
		head = head->next;
		delete temp;
	}
}

void LinkedList::delete_at_end() {
	if (head == tail)
	{
		delete head;
		delete tail;
	}else{
		Node *end_node = new Node();
		Node *secondLast_node = new Node();
		end_node = head;
		while (end_node != nullptr){
			secondLast_node = end_node;
			end_node = end_node->next;
		}
		tail = secondLast_node;
		secondLast_node->next = nullptr;
		delete end_node;
	}
}

void LinkedList::delete_at_position(int pos){
	Node *current_node = new Node();
	Node *previous_node = new Node();
	Node *temp = new Node();
	current_node = head;

	for (int i = 0; i < pos; i++)
	{
		previous_node = current_node;
		current_node = current_node->next;
		temp = current_node;
	}
	previous_node->next = current_node->next;
	delete temp;
}
