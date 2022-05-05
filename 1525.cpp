#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<string>
#include<map>
using namespace std;

queue<string>q;
map<string,int> visit;
int puzzle_map[9];
int movx[4] = { 0, 1, 0, -1 };
int movy[4] = {-1,0, 1, 0};
int main() {
	string target_state="123456789";
	int tmp=0;
	for (int i = 0; i < 9; i++) {
		cin >> puzzle_map[i];
		tmp = tmp * 10 + puzzle_map[i];
		if (puzzle_map[i] == 0) {
			tmp += 9;
		}
	}
	string initial_state = to_string(tmp);
	q.push(initial_state);
	while (!q.empty()) {
		string cur_str = q.front();
		q.pop();
		if (cur_str.compare(target_state)==0) {
			cout << visit[target_state] << "\n";
			return 0;
		}
		int cur_idx = cur_str.find('9');
		for (int i = 0; i < 4; i++) {
			if ((cur_idx + 1) % 3 == 0 && i == 1)
				continue;
			if ((cur_idx + 1) % 3 == 1 && i == 3)
				continue;
			int next_idx = cur_idx + movx[i] + movy[i] * 3;
			if (next_idx < 0 || 9 <= next_idx)
				continue;
			string tmp_str= cur_str;
			char tmp = tmp_str[cur_idx];
			tmp_str[cur_idx] = tmp_str[next_idx];
			tmp_str[next_idx] = tmp;
			if (visit.count(tmp_str))
				continue;
			q.push(tmp_str);
			visit[tmp_str] = visit[cur_str] + 1;
		}
	}
	cout << "-1\n";
	return 0;
}