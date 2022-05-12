#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

using namespace std;

int seq[55];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}
	if (n == 1) {
		printf("A\n");
	}
	else if (n == 2) {
		if (seq[0] == seq[1])
			printf("%d\n",seq[0]);
		else {
			printf("A\n");
		}
	}
	else {
		if (seq[1] == seq[0]) {
			for (int i = 2; i < n; i++) {
				if (seq[i] != seq[1]) {
					printf("B\n");
					return 0;
				}
			}
			printf("%d\n", seq[1]);
			return 0;
		}
		else {
			int a = (seq[2] - seq[1]) / (seq[1] - seq[0]);
			int b = seq[1] - a * seq[0];
			if ((seq[2] - seq[1]) % (seq[1] - seq[0]) != 0) {
				printf("B\n");
			}
			else {
				for (int i = 1; i < n; i++) {
					int next = a * seq[i - 1] + b;
					if (next != seq[i]) {
						printf("B\n");
						return 0;
					}
				}
				printf("%d\n", a * seq[n - 1] + b);
			}
		}
	}
	return 0;
	
}