#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

using namespace std;
int acc_seq[15];
char op_seq[15];
int max_num;
void dfs(int cur_acc,int cur_val,int cur_seq) {
	if (max_num == cur_seq) {
		if (cur_acc == 0) {
			for (int i = 1; i < max_num; i++) {
				printf("%d",i);
				printf("%c", op_seq[i]);
			}
			printf("%d\n", max_num);
			return;
		}
		return;
	}
	
	if (cur_val < 0) {

	}
	else {
		op_seq[cur_seq] = '+';
		dfs(cur_acc,cur_val*10 - cur_seq, cur_seq + 1);
		op_seq[cur_seq] = '-';
		dfs(cur_acc - cur_seq, cur_seq + 1);
		op_seq[cur_seq] = ' ';
		dfs(cur_acc + (cur_seq - 1) * 10 + cur_seq, cur_seq + 1);
	}
}
int main(){
	int test_num;
	
	scanf("%d", &test_num);
	for (int i = 1; i < 10;i++) {
		acc_seq[i] = acc_seq[i - 1] + i;
	}
	while (test_num--) {	
		scanf("%d",&max_num);
		dfs(0, 1);
	}
}