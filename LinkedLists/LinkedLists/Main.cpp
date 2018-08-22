#include <iostream>
#include "list.h"

using namespace std;

void main()
{
	LinkedList list_;
	
	list_.create(3);
	list_.insert_at_start(5);
	list_.insert_at_end(8);
	list_.insert_at_position(2, 11);
	list_.create(55);
	list_.delete_at_end();
	list_.delete_at_start();
	list_.delete_at_position(3);
	list_.print();
}