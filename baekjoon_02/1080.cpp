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
			//a �� b ��� ���� ������ true, �ƴϸ� false�� �ִ´�.
			b[i][j] = (temp != a[i][j]);
			if (b[i][j]) diff++;
		}
		cin.clear(); cin.get();
	}

	if (!diff) {
		cout << 0 << endl;
		return 0;
	}

	//n,m<3 /�� ����� ��� ���� ��쿡�� true;
	if (n < 3 || m < 3) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {
			//j= m-3 �� ���, �ش� ����� �� ������ �� �̻� �ٲ� ���� ����. �̶�, �ش� ��� ���� �� �ٸ��ٸ� Ž�������� �ʿ䰡 ����.
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
				//�������ش�.
				for (int x = i; x < i + 3; x++)
					for (int y = j; y < j + 3; y++)
						b[x][y] = !b[x][y];
				ans++;
			}
		}
	}//end for
	//�� ������ �� �� ������ Ȯ��
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