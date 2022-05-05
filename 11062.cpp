#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

using namespace std;

int dp_card[1001][1001];
int card_arr[1010];
int cardScore(int head_idx,int tail_idx,int player_turn) {
	if (head_idx > tail_idx)
		return 0;
	if (dp_card[head_idx][tail_idx] != 0)
		return dp_card[head_idx][tail_idx];
	int exp_left = cardScore(head_idx + 1, tail_idx, player_turn + 1);
	int exp_right = cardScore(head_idx, tail_idx - 1, player_turn + 1);
	if (player_turn % 2 == 0) {
		return dp_card[head_idx][tail_idx]=max(card_arr[head_idx] + exp_left, card_arr[tail_idx] + exp_right);
	}
	else {
		return dp_card[head_idx][tail_idx]=min(exp_left, exp_right);
	}
}
int main() {
	int test_num;
	scanf("%d", &test_num);
	while (test_num--) {
		int card_num;
		scanf("%d", &card_num);
		for (int i = 0; i < card_num; i++) {
			scanf("%d", &card_arr[i]);
		}
		cardScore(0, card_num - 1,0);
		printf("%d\n", dp_card[0][card_num-1]);
		for (int i = 0; i < card_num; i++) {
			card_arr[i]=0;
			for (int j = 0; j < card_num; j++) {
				dp_card[i][j] = 0;
			}
		}
	}
	return 0;
}