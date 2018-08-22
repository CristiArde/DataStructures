#pragma once
const int SIZE = 10;

class Stack

{
public:
	Stack();
	void push(int);
	int pop();
	bool isEmpty();
	bool isFull();
	void print();
private:
	
	int array[SIZE];
	int top;
};

