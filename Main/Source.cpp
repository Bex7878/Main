#include <iostream>
#include <limits.h>

using namespace std;

void task1() {
	int n, a[100], minn = INT_MAX;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		if (minn > a[i]) {
			minn = a[i];
		}
	}
	cout << minn;
}

// end of task1 ------------------------------------

void task2() {
	int n, a[100];
	double s = 0, res;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		s += a[i];
	}
	res = s / n;
	cout << res;
}

// end of task2 ------------------------------------

void task3() {
	int n, x = 0;
	cin >> n;
	if (n == 1) {
		cout << "composite";
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (n % i == 0) {
				x++;
			}
		}

		if (x < 2) {
			cout << "prime";
		}
		else
			cout << "composite";
	}
}

// end of task3 ------------------------------------

int factorial(int n) {
	if (n == 0 or n == 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
		
}

void task4() {
	int n;
	cin >> n;
	cout << factorial(n);
}

// end of task4 ------------------------------------

int fib(int n) {
	if (n == 0 or n == 1) {
		return n;
	}
	else {
		return fib(n - 2) + fib(n - 1);
	}
}

void task5() {
	int n;
	cin >> n;
	cout << fib(n);
}

// end of task5 ------------------------------------

int pow(int a, int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return a * pow(a, n - 1);
	}
}

void task6() {
	int a, n;
	cin >> a >> n;
	cout << pow(a, n);
}

// end of task6 ------------------------------------

void permutation(string a, int i, int j) {
	if (i == j) {
		cout << a << endl;
	}
	else {
		for (int k = i; k <= j; k++) {
			char temp = a[i];
			a[i] = a[k];
			a[k] = temp;
			permutation(a, i + 1, j);
			char temp1 = a[i];
			a[i] = a[k];
			a[k] = temp1;
		}
	}
}

void task7() {
	string a;
	cin >> a;
	permutation(a, 0, a.length() - 1);
}

// end of task7 ------------------------------------

bool checker(string s, int i) {
	if (i == s.length()) {
		return true;
	}

	if (!isdigit(s[i])) {
		return false;
	}
	return checker(s, i + 1);
}

void task8() {
	string s;
	cin >> s;
	if (checker(s, 0)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}

// end of task8 ------------------------------------

int bincoef(int n, int k) {
	if (k == 0 or k == n) {
		return 1;
	}
	return bincoef(n - 1, k - 1) + bincoef(n - 1, k);
}

void task9() {
	int n, k;
	cin >> n >> k;
	cout << bincoef(n, k);
}

// end of task9 ------------------------------------

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

void task10() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b);
}

// end of task10 ------------------------------------

int main() {
	task10();
}
