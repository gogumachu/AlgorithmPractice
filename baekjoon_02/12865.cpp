#include <iostream>
//#include <ut>
//����� �賶
using namespace std;
// using typedef ���� ���ĸ� ���� �ٸ��� ���� ���
//using�� temlate�� ������
//���� �迭 -> �����迭 ������ 	2380kb	4ms �� �پ��
// �Է¹����鼭 ���� dp ����Ҽ��� ����
using wv = pair<int, unsigned short int>;
int dp[100001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; //1~100
	int K;  // 100, 000
	int w;//100, 000
	unsigned short int v;//  1, 000
	wv wvs[101];
	
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> w >> v;
		wvs[i].first = w;
		wvs[i].second = v;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = K; j >=wvs[i].first; j--) { //w ���� ����� ��� �ڱ� �ڽ��� �� ���ع����� �ȵ�
			if (wvs[i].second + dp[j - wvs[i].first] > dp[j])
				dp[j] = wvs[i].second + dp[j - wvs[i].first];
		}
	}
	cout << dp[K] << endl;
}