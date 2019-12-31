#include <iostream>

#define MATRIX_SIZE 5

using namespace std;

class Array {
private:
	double values[MATRIX_SIZE];
public:
	friend void SetArray(Array array[]);

	friend void GetArray(Array array[]);

	friend void MergeSort(Array array[]);

	friend void CalculateProductColumsAndArithmeticMean(Array array[]);
};

void SetArray(Array array[]) {
	for (int i = 0; i < MATRIX_SIZE; ++i)
		for (int j = 0; j < MATRIX_SIZE; ++j) {
			cout << "[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> array[i].values[j];
		}
}

void GetArray(Array array[]) {
	for (int i = 0; i < MATRIX_SIZE; ++i) {
		for (int j = 0; j < MATRIX_SIZE; ++j) {
			cout << array[i].values[j] << "\t";
		}
		cout << endl;
	}
}

void MergeSort(Array array[]) {
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int block_size_iterator = 1; block_size_iterator < MATRIX_SIZE; block_size_iterator *= 2) {
			for (int block_iterator = 0; block_iterator < MATRIX_SIZE - block_size_iterator; block_iterator += 2 * block_size_iterator) {
				int leftBlockIterator = 0;
				int rightBlockIterator = 0;
				int leftBorder = block_iterator;
				int midBorder = block_iterator + block_size_iterator;
				int rightBorder = block_iterator + 2 * block_size_iterator;
				rightBorder = (rightBorder < MATRIX_SIZE) ? rightBorder : MATRIX_SIZE;
				int* SortedBlock = new int[rightBorder - leftBorder];

				while (leftBorder + leftBlockIterator < midBorder && midBorder + rightBlockIterator < rightBorder) {
					if (array[i].values[leftBorder + leftBlockIterator] > array[i].values[midBorder + rightBlockIterator]) {
						SortedBlock[leftBlockIterator + rightBlockIterator] = array[i].values[leftBorder +
							leftBlockIterator];
						leftBlockIterator++;
					}
					else {
						SortedBlock[leftBlockIterator + rightBlockIterator] = array[i].values[midBorder +
							rightBlockIterator];
						rightBlockIterator++;
					}
				}
				while (leftBorder + leftBlockIterator < midBorder) {
					SortedBlock[leftBlockIterator + rightBlockIterator] = array[i].values[leftBorder + leftBlockIterator];
					leftBlockIterator++;
				}
				while (midBorder + rightBlockIterator < rightBorder) {
					SortedBlock[leftBlockIterator + rightBlockIterator] = array[i].values[midBorder + rightBlockIterator];
					rightBlockIterator++;
				}

				for (int MergeIterator = 0; MergeIterator < leftBlockIterator + rightBlockIterator; MergeIterator++) {
					array[i].values[leftBorder + MergeIterator] = SortedBlock[MergeIterator];
				}
				delete SortedBlock;

			}

		}
	}
}

void CalculateProductColumsAndArithmeticMean(Array array[]) {
	double arithmeticMean = 0.0;
	for (int i = 0; i < MATRIX_SIZE - 1; i++) {
		int productElementsColumn = 1;
		for (int j = 0; j < MATRIX_SIZE; j++) {
			if (i < j) {
				productElementsColumn = array[j].values[i] * productElementsColumn;
			}
		}
		arithmeticMean += productElementsColumn;
		cout << "the product of the elements column under the main diagonal of the matrix(" << i << ") = " << productElementsColumn << "\n";
	}
	double N = MATRIX_SIZE;
	cout << "\n" << "arithmetic mean = " << arithmeticMean / 5 << "\n";
}

int main() {
	Array Array[MATRIX_SIZE];
	cout << "Input elements:\n" << endl;
	SetArray(Array);
	cout << "\nOld matrix:\n" << endl;
	GetArray(Array);
	MergeSort(Array);
	cout << "\nNew matrix:\n" << endl;
	GetArray(Array);
	cout << "\nthe product of the elements column under the main diagonal of the matrix and arithmetic mean:\n" << endl;
	CalculateProductColumsAndArithmeticMean(Array);
}