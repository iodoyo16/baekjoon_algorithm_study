#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

using namespace std;

int dp_seq[100010][2];
int seq[100010];


int main() {
	int seq_len;
	scanf("%d", &seq_len);
	for (int i = 0; i < seq_len; i++) {
		scanf("%d", &seq[i]);
	}
	int max_sum = seq[0];
	dp_seq[0][0] = dp_seq[0][1] = seq[0];
	for (int i = 1; i < seq_len; i++) {
		dp_seq[i][0] = max(dp_seq[i - 1][0] + seq[i], seq[i]);
		dp_seq[i][1] = max(dp_seq[i - 1][1] + seq[i], dp_seq[i - 1][0]);
		int max_acc = max(dp_seq[i][0], dp_seq[i][1]);
		max_sum = max(max_sum, max_acc);
	}
	printf("%d\n", max_sum);
	return 0;
}