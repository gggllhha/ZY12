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

/*�ж���ͨ�����Ƿ�ͬɫ*/
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
		for (int j = 1; j <= m; j++) { //��������������ɫ���Ƿ����Ҫ��
			color[index] = j;
			if (isDiffColor(index)) {
				backTracking(index + 1);
			}
			color[index] = 0;
		}
	}
}
int main() {
	cout << "�����붥��������ɫ����";
	cin >> n >> m;
	cout << "������������ͨͼ��" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];
	cout << "Answer:" << endl;
	backTracking(0);
	if (cnt == 0) {
		cout << "No" << endl;
	}
	else {
		cout << "���ܵ���ɫ�����У�" << cnt << "��" << endl;
	}
}