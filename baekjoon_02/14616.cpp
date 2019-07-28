#include <iostream>
#include <vector>
#include <algorithm>
//float 4byte
//o(nm) �� ��� : 3920kb	1784ms
// ���� �񱳿� �̺�Ž���� �̿��ؼ� Ǯ��
// �� ���ɴ� ��� �������� �˻����� ����
// �������� �����Ѵ���, �߰� ���������� �˻�
// �߰� �������� �ش� ���ɺ��� ���Ⱑ ������ �� �Ʒ����ִ·������鸸 �˻��ؼ�
// �˻� Ƚ�� ����
//o(mlog(m) + n*m/2) : 3920kb	68ms
using namespace std;
struct radio { //����
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
	sort(lasers,lasers+M); //default �������� , �������� �Ϸ��� functional �� greater<float>() ���
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