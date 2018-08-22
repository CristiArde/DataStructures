#pragma once

class DoubleLinkedList
{
private:
	struct Node
	{
		int data;
		Node *next;
		Node *prev;
	};
	Node *head, *tail;

public:
	DoubleLinkedList();
	void insert_at_start(int);
	void insert_at_end(int);
	void insert_at_position(int, int);
	void delete_at_start();
	void delete_at_end();
	void delete_at_position(int);
	void getHeader();
	void getTail();
	void create(int);
	void print();

};
