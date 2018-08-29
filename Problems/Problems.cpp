#include <iostream>
#include <string>
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

void swap(int *a, int *b) {
	int * temp;
	temp = a;
	a = b;
	b = temp;
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

void arrangePositiveAndNegativeInArray(int arr[], int size) {
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] < 0) {
			swap(arr[i], arr[j]);
				j++;
		}
	}
	cout << "New sorted array negative left positive right : ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << "; ";

	cout << endl;
}
// repeats the same int until reacheas 0 ex -> 3 = 333222111 332211 321
void printPat(int n) {
	int j = n;
	int k = n;
	LOOP:while (n>0) {
		for (int i = j; i > 0; i--) {
			cout << n <<" ";
		}
		n--;
	}
	n = k;
	j--;
	if (j == 0) {
		cout << "$";
		return;
	}
	cout << "$";
	goto LOOP;
		 
		 
}

int printPal(int arr[], int size) {
	string pal;
	bool isPal = true;
	int j, k;
	for (int i = 0; i < size; i++) {
		pal = to_string(arr[i]);
		k = 0;
		j = pal.length()-1;
		while (j != k) {
			if (pal.at(k) == pal.at(j)) {
				j--;
				k++;
			} else {
				isPal = false;
				break;
			}
		}
	}
	if (isPal)
		return 1;
	else 
		return 0;

}
void merge(int *arr, int *leftArr, int sizeLeft, int *rightArr, int sizeRight) {
	int i, j, k;//i-counter for leftArr, j-counter for rightArr, k counter for original arr
	i = 0; j = 0; k = 0;

	while (i < sizeLeft && j < sizeRight) {
		if (leftArr[i] < rightArr[j]){
			arr[k] = leftArr[i];
			k++; i++;
		} else
			arr[k++] = rightArr[j++];
	}
	//fill original with remaining ones
	while (i < sizeLeft)
		arr[k++] = leftArr[i++];
	while (j < sizeRight)
		arr[k++] = rightArr[j++];
}

//merges two sorted arrays in a recursive order
void mergeSort(int *arr, int size) {
	int i, mid;
	mid = size / 2;
	int *leftArr = new int[mid];
	int *rightArr = new int[size - mid];

	//check if original is big enough
	if (size < 2) return;

	//populate left and right array
	for (i = 0; i < mid; i++)
		leftArr[i] = arr[i];

	for (i = mid; i < size; i++)//start from mid position
		rightArr[i-mid] = arr[i];

	mergeSort(leftArr, mid);//split the left array
	mergeSort(rightArr, size - mid);//spit the right array
	merge(arr, leftArr, mid, rightArr, size - mid);//merge two sorted arrays

}

void ThridLargest(int arr[], int size) {
	mergeSort(arr, size);
	cout << arr[2];
}

bool isBinary(string str) {
	// Your code here
	int i = 0;
	while (i < str.length()) {
		if (str.at(i) == '1' || str.at(i) == '0')
			i++;
		else
			break;
	}
	if (i == str.length())
		return 1;
	else
		return 0;

}


void main() {
/*	int arr1[] = { 9, 4, 9, 6, 7, 4 };
	int negandposArr[] = { -2,-6,2,5,-5,10,-1 };
	int sizeNegPos = sizeof(negandposArr) / sizeof(negandposArr[0]);
	int sorted_arr1[] = { 1,2,3,4,5 };
	int sorted_arr2[] = { 4,5,6,7,8 };
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int sorted_arr_size1 = sizeof(sorted_arr1) / sizeof(sorted_arr1[0]);
	int sorted_arr_size2 = sizeof(sorted_arr2) / sizeof(sorted_arr2[0]);
	insertionSort(arr1, size1);
	
	cout << "First non repeat with 2 foor loops : " << firstNonRepeat(arr1, size1) << endl;
	
	firstNonRepeatWithHash(arr1, size1);
	
	mergeTwoSortedArrays(sorted_arr1, sorted_arr2, sorted_arr_size1, sorted_arr_size2);
	cout << endl;
	arrangePositiveAndNegativeInArray(negandposArr, sizeNegPos);
	printPat(3);

	int ar[4] = {  222,311, 333,441 };
	cout << printPal(ar, 4);

	int A[] = { 6,2,1,3,9,10,15,13,12,17 };
	int numberOfElements = sizeof(A) / sizeof(A[0]);
	ThridLargest(A, numberOfElements);
	//printing all elements in the array once its sorted.
*/
	cout << isBinary("123");
	cout << isBinary("109");
	system("pause");

}