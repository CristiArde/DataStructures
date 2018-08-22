#pragma once

const int SIZE = 10;
class Queue
{
public:
	Queue();
	void dequeue();
	void enqueue(int);
	int peek();
	int Rear();
	int sizez();
	bool isEmpty();
	bool isFull();
	void print();
	
private:
	int *arr;
	int size;
	int front;
	int rear;
	int count;
};
