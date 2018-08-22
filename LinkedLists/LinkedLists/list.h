#pragma once

class LinkedList {
private :
	struct Node
	{
		int data;
		Node *next;
	};
	Node *head, *tail;

public:
	LinkedList();
	void insert_at_start(int);
	void insert_at_end(int);
	void insert_at_position(int, int);
	void delete_at_start();
	void delete_at_end();
	void delete_at_position(int);
	int getHeader();
	int getTail();
	void create(int);
	void print();
};

