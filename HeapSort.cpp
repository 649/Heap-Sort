#include <iostream>
using namespace std;

void Snapshot(int * A, int r) {
	for (int i = 0; i < r; i++)
		cout << A[i] << ";";
}

void exchange(int *A, int S, int E) {
	int temp = A[S];
	A[S] = A[E];
	A[E] = temp;
}
void MaxHeapify(int *A, int i, int HeapSize) {
	int largest = i;
	if (2*i <= HeapSize && A[2*i] > A[i])
		largest = 2*i;
	if (2*i+1 <= HeapSize && A[2*i+1] > A[largest])
		largest = 2*i+1;
	if (largest != i) {
		exchange(A, i, largest);
		MaxHeapify(A, largest, HeapSize);
	}
}
void HeapSort(int *A, int S) {
	for (int i = S / 2; i >= 0; i--)
		MaxHeapify(A, i, S);
	for (int i = S; i >= 1; i--) {
		exchange(A, 0, i);
		S--;
		MaxHeapify(A, 0, S);
	}
}

int main(int argc, char **argv) {
	int arraySize;

	cin >> arraySize;
	int* Sequence = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
		cin >> Sequence[i];

	HeapSort(Sequence, arraySize - 1);
	Snapshot(Sequence, arraySize); // for printing

	delete[] Sequence;
}