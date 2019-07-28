#include <iostream>
#include <vector>
#include <algorithm>
//float 4byte
//o(nm) 일 경우 : 3920kb	1784ms
// 기울기 비교와 이분탐색을 이용해서 풀음
// 각 방사능당 모든 레이저를 검사하지 않음
// 레이저를 정렬한다음, 중간 레이저부터 검사
// 중간 레이저가 해당 방사능보다 기울기가 작으면 그 아래에있는레이저들만 검사해서
// 검사 횟수 줄임
//o(mlog(m) + n*m/2) : 3920kb	68ms
using namespace std;
struct radio { //방사능
	float m1;
	float m2;
};
//double , float
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;//1~100,000
	int M;//1~100,000
	int a, b,c,d;
	vector<radio> radios;
	float lasers[100000];
	cin >> N;
	for (int i = 0; i<N; i++) {
		cin >> a >> b >> c >> d;
		radios.push_back({ static_cast<float>(b)/a,static_cast<float>(d)/c });
	}
	cin >> M;
	for (int i = 0; i<M; i++) {
		cin >> a >> b;
		lasers[i] = static_cast<double>(b)/ a;
	}
	int ans = N;
	sort(lasers,lasers+M); //default 오름차순 , 내림차순 하려면 functional 의 greater<float>() 사용
	for (int i = 0; i<N; i++) {
		double tmp;
		if (radios[i].m1>radios[i].m2) {
			tmp = radios[i].m1;
			radios[i].m1 = radios[i].m2;
			radios[i].m2 = tmp;
		}
		int left = 0, right = M - 1,mid =0;
		while (left <= right) {
			mid = (left + right) / 2;
			if (lasers[mid] < radios[i].m1) {
				left = mid+1;
			}
			else if (lasers[mid] > radios[i].m2) {
				right = mid-1;
			}
			else {
				ans--;
				break;
			}
		}
	}
	cout << ans << endl;

}