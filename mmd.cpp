#include <bits/stdc++.h> 
using namespace std;
char file[10001][3][100] = {
	{"index.mmd", "index.html", "mmd"}, 
	{"404.mmd", "404.html", "mmd"}, 
	{"empty.mmd", "empty.html", "mmd"}, 
	{"article\\ruanjian.mmd", "article\\ruanjian.html", "mmd"}, 
	{"article\\gugusrkl.mmd", "article\\gugusrkl.html", "mmd"}, 
	{"article\\daodanlanjie.mmd", "article\\daodanlanjie.html", "mmd"},
	{"article\\daodanlanjie.mmd", "article\\daodanlanjie.html", "mmd"},
	{"article\\daodanlanjie.mmd", "article\\daodanlanjie.html", "mmd"},
	{"article\\daodanlanjie.mmd", "article\\daodanlanjie.html", "mmd"},
	{"article\\daodanlanjie.mmd", "article\\daodanlanjie.html", "mmd"},
	{"article\\daodanlanjie.mmd", "article\\daodanlanjie.html", "mmd"},
	{"article\\daodanlanjie.mmd", "article\\daodanlanjie.html", "mmd"},
	{"article\\daodanlanjie.mmd", "article\\daodanlanjie.html", "mmd"},
};
int n = 6;
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

