#include <bits/stdc++.h>
using namespace std;




int main() {

	cout << "Enter printer size : ";
	int size;
	cin >> size;

	int queue[size];

	int start = -1 , end = -1;

	int ans;

	do
	{
		cout << "\n\n1. job done \n2. New job \n3. Printer is free\n4. See no. of panding job\n0. Exit\n\nEnter ans :  ";
		cin >> ans;

		switch (ans) {

		case 1 :
			if (start > end || start == -1 ) cout << "Printer is already free \n";
			else {start++; cout << "Done \n";}
			break;

		case 2:
			if (end - start + 1 == size) cout << "Printer is Full\n";
			else {
				end++;
				if (start == -1) start = 0;
				cout << "Done\n";
			}

			break;

		case 3:
			if (start > end || start == -1) cout << "Yes , printer is free\n";
			else cout << "No , printer is not free\n";
			break;

		case 4:
			cout << end - start + 1 << endl;

		};


	} while (ans);



	return 0;
}