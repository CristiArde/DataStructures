#include <iostream>
#include "Stack.h"

using namespace std;


Stack::Stack() {
	top = -1;
	array[SIZE];
}

void Stack::push(int num) {
	if (Stack::isFull()) {
		cout << "Stack is Full";
		return;
	}
	top++;
	array[top] = num;
}

int Stack::pop() {
	if (Stack::isEmpty()){
		cout << "Stack is Empty";
		abort;
	}
	
	int x = array[top];
	array[top] = NULL;
	top--;
	return x;
}

bool Stack::isEmpty() {
	if (top == -1)
		return true;
	else
		return false;
}

bool Stack::isFull() {
	if (top == SIZE - 1)
		return true;
	else
		return false;
}

void Stack::print() {
	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i] << " | ";
	}
	system("pause");
}


void main() {
	Stack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	s.push(9);
	s.push(10);
	s.print();
	cout << endl;
	cout << s.pop() << " was popped" << endl;
	cout << s.pop() << " was popped" << endl;
	cout << s.isEmpty() << endl;
	cout << s.isFull() << endl;
	s.print();

}