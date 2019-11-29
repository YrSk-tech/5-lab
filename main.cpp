#include <iostream>

#define n 5

using namespace std;

class Array {
private:
    double dArr[n];
public:
    friend void SetArray(Array Arr[]);

    friend void GetArray(Array Arr[]);

    friend void MergeSort(Array Arr[]);

    friend void CalculateValue(Array Arr[]);
};

void SetArray(Array Arr[]) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cout << "[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> Arr[i].dArr[j];
        }
}

void GetArray(Array Arr[]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << Arr[i].dArr[j] << "\t";
        }
        cout << endl;
    }
}

void MergeSort(Array Arr[]) {
    for (int i = 0; i < n; i++) {
        for (int BlockSizeIterator = 1; BlockSizeIterator < n; BlockSizeIterator *= 2) {
            for (int BlockIterator = 0; BlockIterator < n - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator) {
                int LeftBlockIterator = 0;
                int RightBlockIterator = 0;
                int LeftBorder = BlockIterator;
                int MidBorder = BlockIterator + BlockSizeIterator;
                int RightBorder = BlockIterator + 2 * BlockSizeIterator;
                RightBorder = (RightBorder < n) ? RightBorder : n;
                int *SortedBlock = new int[RightBorder - LeftBorder];

                while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder) {
                    if (Arr[i].dArr[LeftBorder + LeftBlockIterator] > Arr[i].dArr[MidBorder + RightBlockIterator]) {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = Arr[i].dArr[LeftBorder +
                                                                                          LeftBlockIterator];
                        LeftBlockIterator++;
                    } else {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = Arr[i].dArr[MidBorder +
                                                                                          RightBlockIterator];
                        RightBlockIterator++;
                    }
                }
                while (LeftBorder + LeftBlockIterator < MidBorder) {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = Arr[i].dArr[LeftBorder + LeftBlockIterator];
                    LeftBlockIterator++;
                }
                while (MidBorder + RightBlockIterator < RightBorder) {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = Arr[i].dArr[MidBorder + RightBlockIterator];
                    RightBlockIterator++;
                }

                for (int MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++) {
                    Arr[i].dArr[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
                }
                delete SortedBlock;

            }

        }
    }
}

void CalculateValue(Array Arr[]) {
    double Sum = 0.0;
    for (int i = 0; i < n-1; i++) {
        int product = 1;
        for (int j = 0; j < n; j++) {
            if (i < j) {
                product = Arr[j].dArr[i] * product;
            }
        }
        Sum += product;
        cout << "f(" << i << ") = " << product << "\n";
    }
    double N = n;
    cout << "\n" << "F = " << Sum / 5 << "\n";
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
    cout << "\nf and F:\n" << endl;
    CalculateValue(Array);
}