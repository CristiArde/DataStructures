#include <iostream>
#include <algorithm>
using namespace std;



int* quickSort(int arr[], int start, int end) {
	if (start < end) {
		int partitionIndex = partition(arr, start, end);
		quickSort(arr, start, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, end);
	}
}
int partition(int arr[], int start, int end) {

	int pIndex = start; 
	int pivot = arr[end];

	for (int i = start; i < end -1; i++) {
		if (arr[i] <= pivot) {
			swap(arr[i], arr[pIndex]); // swap if less that pivot
			pIndex++;
		}
	}
	swap(arr[pIndex], arr[end]); // swap end pivot so now  hes in middle 
	return pIndex;
}

void main() {
	int arr[] = { 1,5,7,9,2,4,20,13,6,21,8,10 };

}