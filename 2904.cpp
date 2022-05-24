#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<math.h>

using namespace std;

int card_num[110];
bool is_prime[1000010];
void init_is_prime(int max_val) {
	for (int i = 2; i <= max_val; i++)
		is_prime[i] = true;
	for (int i = 2; i*i <= max_val; i++) {
		if (!is_prime[i])
			continue;
		for (int j = i*2; j <= max_val; j += i) {
			is_prime[j] = false;
		}
	}
}
int main() {
	int num_of_cards;
	int max_val=0;
	int ans = 1;
	int op_cnt = 0;
	scanf("%d", &num_of_cards);
	for (int i = 0; i < num_of_cards; i++) {
		scanf("%d", &card_num[i]);
		max_val = max_val < card_num[i] ? card_num[i] : max_val;
	}
	init_is_prime(max_val);
	for (int prime_num = 2; prime_num <= max_val; prime_num++) {
		if (!is_prime[prime_num])
			continue;
		int total_pow_cnt=0;
		int cur_pow_arr[110] = { 0, };
		for (int j = 0; j < num_of_cards; j++) {
			int tmp = card_num[j];
			int cur_pow_cnt=0;
			while ((tmp%prime_num)==0) {
				tmp /= prime_num;
				cur_pow_cnt++;
			}
			//printf("num: %d prime_num: %d %d\n", card_num[j],prime_num, cur_pow_cnt);
			total_pow_cnt += cur_pow_cnt;
			cur_pow_arr[j] = cur_pow_cnt;
		}
		int avg_pow_cnt=total_pow_cnt / num_of_cards;
		ans *= pow(prime_num, avg_pow_cnt);
		for (int j = 0; j < num_of_cards; j++) {
			if (avg_pow_cnt > cur_pow_arr[j]) {
				op_cnt += avg_pow_cnt - cur_pow_arr[j];
			}
		}
	}
	printf("%d %d", ans, op_cnt);
	return 0;
}