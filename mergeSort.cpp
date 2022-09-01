#include <iostream>

using namespace std;

void merge(int* mas, size_t start, size_t end, size_t mid) {
	int* merged = new int[end - start + 1];
	size_t i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (mas[i] < mas[j]) {
			merged[k] = mas[i];
			++i;
		}
		else {
			merged[k] = mas[j];
			++j;
		}
		++k;
	}
	while (i <= mid) {
		merged[k] = mas[i];
		++k;
		++i;
	}
	while (j <= end) {
		merged[k] = mas[j];
		++k;
		++j;
	}
	for (size_t i = start, k = 0; i <= end; ++i, ++k)mas[i] = merged[k];
	delete[] merged;
}

void mergeSort(int* mas, size_t start, size_t end) {
	size_t mid = 0;
	if (start < end) {
		mid = (start + end) / 2;
		mergeSort(mas, start, mid);
		mergeSort(mas, mid+1, end);
		merge(mas, start, end, mid);
	}
}

int main()
{
	int a[11] = { 7,15,-95,45,4,0,34,-154,-7,-40,-456 };
	mergeSort(a, 0, 10);
	for (int i = 0; i < 11; i++)cout << a[i] <<' ';
}