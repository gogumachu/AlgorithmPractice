#include <iostream>
//#include <ut>
//평범한 배낭
using namespace std;
// using typedef 쓰는 형식만 조금 다르고 거의 비슷
//using은 temlate을 지원함
//이차 배열 -> 일차배열 줄이자 	2380kb	4ms 로 줄어듦
// 입력받으면서 동시 dp 계산할수도 있음
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
		for (int j = K; j >=wvs[i].first; j--) { //w 부터 기록할 경우 자기 자신을 또 더해버려서 안됨
			if (wvs[i].second + dp[j - wvs[i].first] > dp[j])
				dp[j] = wvs[i].second + dp[j - wvs[i].first];
		}
	}
	cout << dp[K] << endl;
}