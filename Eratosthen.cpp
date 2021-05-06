// The sieve of Eratosthenes

#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void sieve() {
	int n;
	cin >> n;
	vector <int> a;
	for (int i = 0; i < n + 1; i++) {
		a.push_back(i);
	}
	for (int i = 2; i < n + 1; i++) {
		if (a[i] != 0) {
			cout << a[i] << ' ';
			for (int j = i * i; j < n + 1; j += i) {
				a[j] = 0;
			}
		}
	}
}

int main() {
	sieve();
}