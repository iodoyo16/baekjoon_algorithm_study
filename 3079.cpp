#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
using namespace std;
long long time[100100];
int main() {
	int immigration_gate_num;
	long long passenger_num;
	scanf("%d %lld", &immigration_gate_num, &passenger_num);
	for (int i = 0; i < immigration_gate_num; i++)
		scanf("%lld", &time[i]);
	sort(time, time + immigration_gate_num);
	long long min_time = 0, max_time = time[immigration_gate_num - 1] * passenger_num;
	while (min_time < max_time) {
		long long mid_time = (min_time + max_time) / 2;
		long long pass_sum = 0;
		for (int i = 0; i < immigration_gate_num; i++) {
			long long pass_num_per_gate= mid_time / time[i];
			pass_sum += pass_num_per_gate;
			if (pass_sum >= passenger_num)break;
		}
		if (pass_sum >= passenger_num)
			max_time = mid_time;
		else {
			if (min_time == mid_time)break;
			min_time = mid_time;
		}
	}
	printf("%lld", max_time);
}