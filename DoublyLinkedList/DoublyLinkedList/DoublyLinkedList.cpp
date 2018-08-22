#include "list.h"
#include <iostream>

using namespace std;

DoubleLinkedList::DoubleLinkedList() {
	head = nullptr;
	tail = nullptr;
}

void DoubleLinkedList::create(int val) {
	Node *new_node = new Node();
	new_node->data = val;
	new_node->next = nullptr;

	if (head == nullptr) {
		head = new_node;
		tail = new_node;
		new_node = nullptr;
	}else{
		Node *temp = new Node();
		temp = tail;
		tail->next = new_node;
		tail = new_node;
		tail->prev = temp;
	}
}

void DoubleLinkedList::print() {
	for (Node * current = head; current != nullptr; current = current->next) {
		cout << current->data << " | ";
	}
	system("pause");
}

void DoubleLinkedList::getHeader() {
	cout << "Current Head: " << head->data << endl;
}

void DoubleLinkedList::getTail() {
	cout << "Current Tail: " << tail->data << endl;
}

void DoubleLinkedList::insert_at_start(int val)
{
	Node *new_node = new Node();
	new_node->data = val;

	if (head != nullptr) {
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}else{
		head = new_node;
		tail = new_node;
		new_node = nullptr;
	}	
}

void DoubleLinkedList::insert_at_end(int val) {
	Node *new_node = new Node();
	new_node->data = val;

	if (head == nullptr) {
		head = new_node;
		tail = new_node;
		new_node = nullptr;
	}else{
		new_node->prev = tail;
		new_node->next = nullptr;
		tail->next = new_node;
		tail = new_node;
	}
}
void DoubleLinkedList::insert_at_position(int pos, int val) {
	Node *new_node = new Node();
	new_node->data = val;
	for (Node *i = head; i->next != nullptr; i = i->next){
		if (i->data == pos) {
			new_node->next = i->next;
			new_node->prev = i;
			i->next = new_node;
			break;
		}
	}
	
}
void DoubleLinkedList::delete_at_position(int pos) {
	for (Node *i = head; i->next != nullptr; i = i->next) {
		if (i->data == pos) {
			i->prev->next = i->next;
			i->next->prev = i->prev;
			delete i;
			break;
		}
	}
}
void DoubleLinkedList::delete_at_start() {
	Node *temp = new Node();
	temp = head;
	head = temp->next;
	head->prev = nullptr;
	delete temp;
}

void DoubleLinkedList::delete_at_end() {
	Node *temp = new Node();
	temp = tail;
	tail = temp->prev;
	tail->next = nullptr;
	delete temp;
}