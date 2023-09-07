#include<iostream>
#include<iomanip>

using namespace std;

// Observe: Commutative String
// 2: 10 unknowns => 2 ^ 10 = 1024, 1024 very less than 3 * 10^9
// 3: Probability is 0.5

int fact[] = {1, 1, 2, 6, 24, 120, 720, 720 * 7, 720 * 7 * 8, 720 * 7 * 8 * 9, 720 * 7 * 8 * 9 * 10};

int main() {
	int loc = 0;

	char c;
	while (cin.get(c)) {
		if (c == '\n') break;
		loc += 44 - c;
	}

	int start = 0;
	int unknown = 0;
	while (cin.get(c)) {
		if (c != '+' && c != '-' && c != '?') break;
		start += (44 - c) * (c != '?');
		unknown += (c == '?');
	}

	// i is hamming weight
	int ways = 0;
	for (int i = 0; i <= unknown; i++) {
		int end = start + 2 * i - unknown;
		if (end == loc) ways += fact[unknown] / (fact[unknown - i] * fact[i]);
	}

	double prob = ((double)ways) / ((double)(1 << unknown));
	cout << setprecision(15) << prob;
}
