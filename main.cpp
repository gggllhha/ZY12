#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define MAX 100
using namespace std;
int color[MAX];
int graph[MAX][MAX] = { 0 };
int n, m;
int cnt = 0;

/*判断连通两点是否同色*/
bool isDiffColor(int index) {
	for (int i = 0; i < n; i++) {
		if (graph[index][i] == 1 && color[index] == color[i]) {
			return false;
		}
	}
	return true;
}

void backTracking(int index) {

	if (index == n) {
		for (int i = 0; i < n; i++) {
			cout << color[i] << " ";
		}
		cnt++;
		cout << endl;
	}
	else {
		for (int j = 1; j <= m; j++) { //依次填上所有颜色看是否符合要求
			color[index] = j;
			if (isDiffColor(index)) {
				backTracking(index + 1);
			}
			color[index] = 0;
		}
	}
}
int main() {
	cout << "请输入顶点数和颜色数：";
	cin >> n >> m;
	cout << "请输入无向连通图：" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];
	cout << "Answer:" << endl;
	backTracking(0);
	if (cnt == 0) {
		cout << "No" << endl;
	}
	else {
		cout << "可能的着色方案有：" << cnt << "种" << endl;
	}
}