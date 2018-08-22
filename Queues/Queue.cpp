#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {
	arr = new int [SIZE];
	front = 0;
	rear = count - 1;
	count = 0;
	size = SIZE;
}

void Queue::enqueue(int i) {
	if (isFull()){
		cout << "Queue is full. OVERFLOW";
		system("pause");
		exit(EXIT_FAILURE);
	}
	rear = (rear + 1) % size;
	arr[rear] = i;
	count++;
}

void Queue::dequeue() {
	if (isEmpty()) {
		cout << "Queue is empty. UNDERFLOW";
		system("pause");
		exit(EXIT_FAILURE);
	}
	arr[front] = 0;
	front = (front + 1) % size;
	count--;
}

void Queue::print() {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " | ";
	}
	system("pause");
}

int Queue::peek() {
	return arr[front];
}

int Queue::Rear() {
	return arr[rear];
}

int Queue::sizez(){
	return count;
}
bool Queue::isEmpty() {
	return (sizez() == 0);
}

bool Queue::isFull() {
	return (sizez() == SIZE);
}

void main() {
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);
	q.enqueue(10);
	
	q.print();

	q.dequeue();
	q.print();
	q.dequeue();
	q.print();
	cout << endl;
	cout << "Front : " << q.peek() << endl;
	cout << "Rear : " << q.Rear() << endl;
	system("pause");
}