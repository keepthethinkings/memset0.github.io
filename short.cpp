#include <bits/stdc++.h> 
using namespace std;
struct File{
	char title[1001], file_input[1001], file_output[1001], theme[1001];
} file[10001];
int n = 0;
int main() {
	freopen("short.txt", "r", stdin);
	while (scanf("%s%s%s%s", file[n].title, file[n].file_input, file[n].file_output, file[n].theme) != EOF) n++;
	fclose(stdin);
	for (int i = 0; i < n; i++) {
		freopen(file[i].file_output, "w", stdout);
		if (file[i].theme[0] == 's') {
			freopen("head.short", "r", stdin);
			char temp[10000];
			while (scanf("%s", temp) != EOF) {
				printf("%s ", temp);
				if(temp[strlen(temp) - 1] == '>') puts("");
			}
			puts("");
			fclose(stdin); 
		}
		
		freopen(file[i].file_input, "r", stdin);
		char temp[10000];
		while (scanf("%s", temp) != EOF) {
			printf("%s ", temp);
			if(temp[strlen(temp) - 1] == '>') puts("");
		}
		puts("");
		fclose(stdin); 
		
		if (file[i].theme[0] == 's') {
			freopen("footer.short", "r", stdin);
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

