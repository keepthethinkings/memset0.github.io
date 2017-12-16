#include <bits/stdc++.h>
using namespace std;
char keys(int k) {
	if (0 <= k && k < 26) return 'a' + k;
	if (26 <= k && k < 52) return 'A' + k - 26;
	if (52 <= k && k < 62) return '0' + k - 52;
	if (62 <= k && k < 72) return '0' + k - 62;
}
int main() {
	int seed;
	cin >> seed;
	while (seed--) rand();
	for (int i = 1; i <= 9; i++) {
		putchar(keys(rand() % 72));
	}
	char c[10];
	while (1) gets(c);
	return 0;
}
