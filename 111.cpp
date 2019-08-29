#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
int main() { 
	srand(time(0));
	const int n = 10;
	int arr[n], ind_max;
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int cur_size = n; cur_size > 1; cur_size--) { 
		ind_max = 0;
		for (int ind = 0; ind < cur_size; ind++) { 
			if (arr[ind] > arr[ind_max])
				ind_max = ind;
		}
		if (ind_max == cur_size - 1)
			continue;
		for (int j = 0, i = ind_max; j < i; i--, j++) { 
			swap(arr[j], arr[i]); 

		}
		for (int i = 0, j = cur_size - 1; i < j; i++, j--) {  
			swap(arr[i], arr[j]);

		}
	}
	cout << endl;
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " ";

	cout << endl;
	system("pause");
	return 0;
}
