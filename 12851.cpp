#include<cstdio>
#include<queue>
using namespace std;
int check[100100] = { 0, };
int cur_dist = 0;
int path_num = 0;
int bfs(int start, int k)
{
	queue< pair < int, int> > q;
	q.push(make_pair(start, 0));
	check[start] = 1;
	if (start == k)
		return 0;
	while (!q.empty())
	{
		int now = q.front().first;
		int d = q.front().second;
		q.pop();
		if (now >= 1 && check[now - 1] == 0) {
			q.push(make_pair(now - 1, d + 1));
			check[now - 1] += 1;
		}
		if (now < 100000 && check[now + 1] == 0) {
			q.push(make_pair(now + 1, d + 1));
			check[now + 1] += 1;
		}
		if (2 * now <= 100000 && check[2 * now] == 0) {
			q.push(make_pair(2 * now, d + 1));
			check[2 * now] += 1;
		}
		if (cur_dist != d) {
			if (check[k] > 0) {
				return q.back().second;
			}
			cur_dist = d;
		}
	}
}
int main()
{
	int j, k;
	scanf("%d %d", &j, &k);
	printf("%d\n", bfs(j, k));
	return 0;
}