#include <iostream>

#define n 5

using namespace std;

class Array {
private:
	double blockArray[n];
public:
	friend void SetArray(Array Array[]);

	friend void GetArray(Array Array[]);

	friend void MergeSort(Array Array[]);

	friend void CalculateProductColumsAndArithmeticMean(Array Array[]);
};

void SetArray(Array Array[]) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cout << "[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> Array[i].blockArray[j];
		}
}

void GetArray(Array Array[]) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << Array[i].blockArray[j] << "\t";
		}
		cout << endl;
	}
}

void MergeSort(Array Array[]) {
	for (int i = 0; i < n; i++) {
		for (int block_size_iterator = 1; block_size_iterator < n; block_size_iterator *= 2) {
			for (int block_iterator = 0; block_iterator < n - block_size_iterator; block_iterator += 2 * block_size_iterator) {
				int LeftBlockIterator = 0;
				int RightBlockIterator = 0;
				int LeftBorder = block_iterator;
				int MidBorder = block_iterator + block_size_iterator;
				int RightBorder = block_iterator + 2 * block_size_iterator;
				RightBorder = (RightBorder < n) ? RightBorder : n;
				int* SortedBlock = new int[RightBorder - LeftBorder];

				while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder) {
					if (Array[i].blockArray[LeftBorder + LeftBlockIterator] > Array[i].blockArray[MidBorder + RightBlockIterator]) {
						SortedBlock[LeftBlockIterator + RightBlockIterator] = Array[i].blockArray[LeftBorder +
							LeftBlockIterator];
						LeftBlockIterator++;
					}
					else {
						SortedBlock[LeftBlockIterator + RightBlockIterator] = Array[i].blockArray[MidBorder +
							RightBlockIterator];
						RightBlockIterator++;
					}
				}
				while (LeftBorder + LeftBlockIterator < MidBorder) {
					SortedBlock[LeftBlockIterator + RightBlockIterator] = Array[i].blockArray[LeftBorder + LeftBlockIterator];
					LeftBlockIterator++;
				}
				while (MidBorder + RightBlockIterator < RightBorder) {
					SortedBlock[LeftBlockIterator + RightBlockIterator] = Array[i].blockArray[MidBorder + RightBlockIterator];
					RightBlockIterator++;
				}

				for (int MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++) {
					Array[i].blockArray[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
				}
				delete SortedBlock;

			}

		}
	}
}

void CalculateProductColumsAndArithmeticMean(Array Array[]) {
	double arithmeticMean = 0.0;
	for (int i = 0; i < n - 1; i++) {
		int productElementsColumn = 1;
		for (int j = 0; j < n; j++) {
			if (i < j) {
				productElementsColumn = Array[j].blockArray[i] * productElementsColumn;
			}
		}
		arithmeticMean += productElementsColumn;
		cout << "the product of the elements column under the main diagonal of the matrix(" << i << ") = " << productElementsColumn << "\n";
	}
	double N = n;
	cout << "\n" << "arithmetic mean = " << arithmeticMean / 5 << "\n";
}

int main() {
	Array Array[n];
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