#include <iostream>
#include <unordered_map>
using namespace std;

//Space O(1) time O(n^2)
void insertionSort(int arr[], int size) {
	int i, j, key;
	for (i = 0; i < size; i++) {
		key = arr[i];
		j = i - 1;
		while (j>= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}


//finds firts non repeating int in array O(n^2)
int firstNonRepeat(int arr[], int size) {

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++) {
			//check if repeat if yes get out of second for loop
			if (i!= j && arr[i] == arr[j])
				break;
			if (j == size)
				return arr[j];
		}
	}	
}

void firstNonRepeatWithHash(int arr[], int size) {
	unordered_map<int, int> mp;
	for (int i = 0; i < size; i++)
		mp[arr[i]]++;
	cout << "First non repeat with HashMap: ";
	for (auto x : mp)
		if (x.second == 1)
			cout << x.first << ", ";
	cout << endl;
	
}
void mergeTwoSortedArrays(int arr1[], int arr2[], int size1, int size2) {
	//initialize new array with total size of both
	int *newSortedArray = new int[size1 + size2];
	int i = 0, j = 0, k = 0;

	//go thro all elements in one of the arrays
	while (i < size1 && j < size2) {
		//if element in first array is smaller 
		//second array[0] add it to the new array 
		if (arr1[i] < arr2[j]) {
			newSortedArray[k] = arr1[i];
			i++; k++;
		//if its not put the second array element in new array and get the next element of second array to compare with all from first
		} else {
			newSortedArray[k] = arr2[j];
			j++; k++;
		}
	}
	//add all the remaining elements from first array if it didnt reach its max lenght
	while (i < size1)
		newSortedArray[k++] = arr1[i++];
	//add all the remaining elements from second array if it didnt reach its max lenght
	while (j < size2)
		newSortedArray[k++] = arr2[j++];
	cout << "Merged new sorted array form 2 separately sorted arrays Complexity O(n1+n2): ";
	for (int i = 0; i < size2 + size1; i++)
		cout << newSortedArray[i];
	cout << endl;
}


void main() {

	int arr1[] = { 9, 4, 9, 6, 7, 4 };
	int sorted_arr1[] = { 1,2,3,4,5 };
	int sorted_arr2[] = { 4,5,6,7,8 };
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int sorted_arr_size1 = sizeof(sorted_arr1) / sizeof(sorted_arr1[0]);
	int sorted_arr_size2 = sizeof(sorted_arr2) / sizeof(sorted_arr2[0]);
	insertionSort(arr1, size1);
	
	cout << "First non repeat with 2 foor loops : " << firstNonRepeat(arr1, size1) << endl;
	
	firstNonRepeatWithHash(arr1, size1);
	
	mergeTwoSortedArrays(sorted_arr1, sorted_arr2, sorted_arr_size1, sorted_arr_size2);

	system("pause");

}