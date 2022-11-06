#include <iostream>
using namespace std;

int n;

void show(int arr[]) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int partition(int arr[] , int left , int right) {
	int dumi[n];
	int t = left , j = right  ;
	int val = arr[right];

	for (int i = left; i < right + 1; ++i)
	{
		if (arr[i] <= val) {
			dumi[t] = arr[i];
			t++;
		}
		else {
			dumi[j] = arr[i];
			j--;
		}
	}

	for (int i = left; i < right + 1; ++i)
		arr[i] = dumi[i];

	return t - 1;
}

void qiuck_sort(int arr[] , int left  , int right) {
	if (right > left) {
		int p = partition(arr , left , right);
		qiuck_sort(arr , left , p - 1);
		qiuck_sort(arr , p + 1 , right);
	}
}


void qiuck_sort_non_recursive(int arr[] , int s , int r) {

	int stack[n + 1];
	int top = -1;

	stack[++top] = s;
	stack[++top] = r;

	while (top >= 0) {

		r = stack[top--];
		s = stack[top--];

		int p = partition(arr , s , r);

		if (p - 1 > s) {
			stack[++top] = s;
			stack[++top] = p - 1;
		}

		if (p + 1 < r) {
			stack[++top] = p + 1;
			stack[++top] = r;
		}


	}

}



int main() {

	cout << "Enter size of array :";
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int ans;

	do
	{
		cout << "1. Recursive \n2. Non-recursive \n0. Exit\n\n";
		cin >> ans;

		int dumi[n];

		for (int i = 0; i < n; ++i) dumi[i] = arr[i];

		if (ans == 1)  {cout << "Recursive :  ";  qiuck_sort(dumi , 0 , n - 1); show(dumi);}

		if (ans == 2) {cout << "Non-recursive : "; qiuck_sort_non_recursive(dumi , 0 , n - 1); show(dumi);}


		/* code */
	} while (ans != 0);


	return 0;
}