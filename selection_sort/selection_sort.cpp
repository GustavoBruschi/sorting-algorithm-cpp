#include <iostream>
using namespace std;

template<typename T, size_t n>
void print_array(T const(&arr)[n])
{
	for(size_t i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	cout << "\n";
}

int minIndex(int a[], int i, int j)
{
	if(i == j)
		return i;
	int k = minIndex(a, i + 1, j);
	return (a[i] < a[k]) ? i : k;
}

void recurSelectionSort(int a[], int n, int index = 0)
{
	if(index == n)
		return;
	int k = minIndex(a, index, n - 1);
	if(k != index)
		swap(a[k], a[index]);
	recurSelectionSort(a, n, index + 1);
}

void iterSelectionSort(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		int min_index = i;
		int min_element = a[i];
		for (int j = i + 1; j < n; j++)
		{
			if(a[j] < min_element)
			{
				min_element = a[j];
				min_index = j;
			}
		}
		swap(a[i], a[min_index]);
	}
}

int main() {
	int recurArr[6] = {106,38,420,5,85,32};
	int iterArr[5] = {12,2,600,89,20};

	cout << "Selection sort recursivo" << "\n";
	print_array(recurArr);
	recurSelectionSort(recurArr, 6);
	print_array(recurArr);

	cout << "Selection sort iterativo" << "\n";
	print_array(iterArr);
	iterSelectionSort(iterArr, 5);
	print_array(iterArr);
}

