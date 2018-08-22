#include <iostream>
#include "list.h"

using namespace std;


void main() {
	DoubleLinkedList doubly_list; 
	doubly_list.create(1);
	doubly_list.create(12);
	doubly_list.create(14);
	doubly_list.insert_at_start(3);
	doubly_list.insert_at_start(4);
	doubly_list.insert_at_end(101);
	doubly_list.insert_at_position(12, 13);

	doubly_list.delete_at_position(1);
	doubly_list.delete_at_start();
	doubly_list.delete_at_end();

	doubly_list.getHeader();
	doubly_list.getTail();
	doubly_list.print();
}