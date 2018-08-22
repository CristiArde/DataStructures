#pragma once
#include "HashNode.h"
template< typename K, typename V>

class HashMap
{
public:
	HashMap() {
		capacity = 20;
		size = 0;
		arr = new HashNode<K, V>*[capacity];

		for (int i = 0; i < capacity; i++)
			arr[i] = NULL;

		dummy = new HashNode<K, V>(-1, -1);
	}

	// retuns the index for the array
	int hashCode(K key) {
		return key % capacity;
	}

	int insertNode(K key, V value) {
		HashNode<K, V> *temp = new HashNode<K, V>(key, value);
		int hashIndex = hashCode(key);

		// put the hash combo in the next spot availalble if that spot is taken
		while (arr[hashIndex] =! NULL && arr[hashIndex]->key != key && arr[hashIndex]->key != -1)
		{
			hashIndex++;
			hashIndex %= capacity;
		}

		//check if there is no more space increase the size
		if (arr[hashIndex] == NULL || arr[hashIndex] == -1)
			size++;
		
		//put the combo in the array
		arr[hashIndex] = temp;
	
	}
	

private:
	int capacity;
	int size;
	HashNode<K, V> *dummy;
	HashNode<K, V> **arr;

};

