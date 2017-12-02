#include <bits/stdc++.h> 
using namespace std;
char file[10001][3][100] = {
	{"index_.html", "index.html", "mmd"}, 
};
int n = 2;
int main() {
	for (int i = 0; i < n; i++) {
		freopen(file[i][1], "w", stdout);
		if (file[i][2][0] == 'm') {
			freopen("head.html.mmd", "r", stdin);
			char temp[10000];
			while (scanf("%s", temp) != EOF) {
				printf("%s ", temp);
				if(temp[strlen(temp) - 1] == '>') puts("");
			}
			puts("");
			fclose(stdin); 
		}
		
		freopen(file[i][0], "r", stdin);
		char temp[10000];
		while (scanf("%s", temp) != EOF) {
			printf("%s ", temp);
			if(temp[strlen(temp) - 1] == '>') puts("");
		}
		puts("");
		fclose(stdin); 
		
		if (file[i][2][0] == 'm') {
			freopen("footer.html.mmd", "r", stdin);
			char temp[10000];
			while (scanf("%s", temp) != EOF) {
				printf("%s ", temp);
				if(temp[strlen(temp) - 1] == '>') puts("");
			}
			puts("");
			fclose(stdin); 
		}
		fclose(stdout);
	}
	return 0;
}
