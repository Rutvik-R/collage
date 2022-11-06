#include <iostream>
using namespace std;

#define ff first
#define ss second

int n;

pair<int, int> insertion(int arr[]) {
	pair<int , int> ans;
	ans.ff = 0;
	ans.ss = 0;
	int key;
	int j;

	for (int i = 1; i < n; ++i)
	{
		key = arr[i];
		j = i ;

		while (j > 0 && arr[j - 1] > key) {
			arr[j] = arr[j - 1];
			j--;
			ans.ss++;
			ans.ff++;
		}

		if (j > 0) ans.ff++;

		arr[j] = key;
	}


	return ans;
}

pair<int , int> bubble(int arr[]) {
	pair<int, int> ans;
	ans.ff = 0;
	ans.ss = 0;

	for (int i = 0; i < n; i++) {
		bool a = true;
		for (int j = 0; j < (n - i - 1); j++) {
			ans.ff++;
			if (arr[j] > arr[j + 1]) {
				a = false ;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				ans.ss++;
			}
		}
		if (a == true) break ;
	}



	return ans;
}

pair<int , int> selection(int arr[]) {
	pair<int, int> ans;


	for (int i = 0; i < n; ++i)
	{
		int mini = i ;

		for (int j = i + 1; j < n; ++j)
		{
			if (++ans.ff && arr[j] < arr[mini]) mini = j;
		}

		if ( mini != i) {
			int dumi = arr[mini];
			arr[mini] = arr[i];
			arr[i] = dumi;
			ans.ss++;
		}

	}


	return ans;

}

pair<int, int> linear(int arr[]) {
	pair<int , int> ans;
	ans.ff = 0;
	ans.ss = 0;
	int val;
	cout << "Enter number : ";
	cin >> val;

	for (int i = 0; i < n; ++i)
	{
		if (++(ans.ss) && arr[i] == val) return ans;

	}

	cout << "Not Found !!!\n";
	return ans;
}

pair<int, int> binary(int arr[]) {
	pair<int, int> ans ;
	int val;

	cout << "Enter val : ";
	cin >> val;

	int f = 0 , l = n - 1 , m;

	while (f <= l) {
		m = (f + l) / 2;

		if (++(ans.ss) && arr[m] < val) f = m + 1;
		else if (++(ans.ss) && arr[m]  > val) l = m - 1;

		else return ans ;

	}

	cout << "Not Found !!!\n";

	return ans;
}


void show(int arr[]) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main() {

	cout << "Enter size of array : ";
	cin >> n;

	int arr[n];
	cout << "Enter array : ";
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int ans;

	do
	{
		cout << "\n1. insertion sort\n2. bubble sort \n3. selection sort \n4.linear search \n5. binary search\n6. show array\n\nEnter your ans : ";
		cin >> ans;
		pair<int , int> p;

		int dumi[n];

		for (int i = 0 ; i < n ; i++) dumi[i] = arr[i];

		switch (ans) {
		case 1:
			p = insertion(dumi);
			cout << "\tComparisons :" << p.ff << "\n\tSwapping : " << p.ss << endl;
			break;

		case 2:
			p = bubble(dumi);
			cout << "\tComparisons :" << p.ff << "\n\tSwapping : " << p.ss << endl;
			break;

		case 3:
			p = selection(dumi);
			cout << "\tComparisons :" << p.ff << "\n\tSwapping : " << p.ss << endl;
			break;

		case 4:
			p = linear(dumi);
			cout << "\tComparisons :" << p.ss << "\n\tSwapping : " << p.ff << endl;
			break;

		case 5:
			selection(dumi);
			p = binary(dumi);
			cout << "\tComparisons :" << p.ss << "\n\tSwapping : " << p.ff << endl;
			break;

		case 6:
			show(arr);
			break;
		}


	} while (ans != 0);



	return 0;
}