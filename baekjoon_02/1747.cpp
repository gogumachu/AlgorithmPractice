/* n 보다 큰 수중에 제일 작은 소수 & 펠린드롬인 수를 구해야 함
31 -> 101
에라스토테네스의 채 이용
각 인덱스가 숫자 해당 인덱스가 소수면 true, 아니면 false 
메모리 : 2848	 시간 : 8
*/

#include <iostream>

using namespace std;

int main() {
    int n=0; //1~1,000,000
    bool primes[1003002];
    //초기화 해주지 않으면 틀렸다고 나옴 꼭 초기화 해주어야 함
    fill(primes,primes+1003002,true);
    int ans=1;
    int arr[7];
    cin>>n;
    //1은 소수가 아님
    primes[1] = false;
    for(int i=2; i<=1003001; i++) {
        int j=2;
        int range = 1003001/i;
        if(primes[i]) { //소수인 경우에만 체크하면 됨 (이미 체크되어 있으면 그 배수도 다 체크되어있음)
            while (j<=range) {
                primes[i*j] = false; //false 일 경우에는 prime이 아님
                j++;
            }
        }
    
    }

    int temp=0, cnt=0;
    for(int i=n; i<=1003001; i++) {
        if(primes[i]) { //소수일경우만 확인
            temp = i;
            cnt=0;
            //펠린드롬 확인
            while(temp) {
                arr[cnt++] = temp%10;
                temp = temp/10;
            }
            int j=-1,k=cnt;
            while(j<k) {
                if(arr[++j] != arr[--k])
                    break;
            }
            if(j>=k)
            {
                ans = i;
                break;
            }
        }
    }
    cout <<ans;

}