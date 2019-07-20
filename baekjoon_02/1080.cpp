#include<iostream>

using namespace std;
//for cin input
static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
int main() {
	int n, m; // 1~50
	char temp;
	int ans = 0;
	int diff = 0;
	char a[50][50];
	bool b[50][50];

	cin >> n >> m;
	cin.clear(); cin.get();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j<m; j++) {
			a[i][j] = cin.get();
		}
		cin.clear(); cin.get();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j<m; j++) {
			temp = cin.get();
			//a 와 b 행렬 값이 같으면 true, 아니면 false를 넣는다.
			b[i][j] = (temp != a[i][j]);
			if (b[i][j]) diff++;
		}
		cin.clear(); cin.get();
	}

	if (!diff) {
		cout << 0 << endl;
		return 0;
	}

	//n,m<3 /두 행렬이 모두 같은 경우에만 true;
	if (n < 3 || m < 3) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {
			//j= m-3 일 경우, 해당 행렬의 맨 윗행은 더 이상 바뀔 일이 없다. 이때, 해당 행들 값이 다 다르다면 탐색진행할 필요가 없다.
			if (j == m - 3 && !(b[i][j] == b[i][j + 1] && b[i][j + 1] == b[i][j + 2]))
			{
				cout << -1 << endl;
				return 0;
			}
			if (i == n - 3 && !(b[i][j] == b[i + 1][j] && b[i + 1][j] == b[i + 2][j]))
			{
				cout << -1 << endl;
				return 0;
			}
			if (b[i][j]) {
				//뒤집어준다.
				for (int x = i; x < i + 3; x++)
					for (int y = j; y < j + 3; y++)
						b[x][y] = !b[x][y];
				ans++;
			}
		}
	}//end for
	//맨 마지막 행 값 같은지 확인
	for (int i = n - 2; i < n; i++) {
		for (int j = m - 2; j < m; j++) {
			if (b[n - 3][m - 3] != b[i][j])
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;
}