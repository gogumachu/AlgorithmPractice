#include<iostream>
//구간합 구하기
using namespace std;
//그냥 풀면 시간초과 dp 이용해서 풀어야함
//그냥 풀 경우 o(n^2) dp : o(n)
//	2260kb	60ms
int main() {
    //전역으로 선언하니 메모리만 더 나왔음
    int n=0;//수의 개수 1~100,000
    int m=0;//합 구해야 하는 회수 1~100,000
    int arr[100001] ={0};
    scanf("%d %d",&n,&m);
   
    for(int i=1; i<=n; i++) {
        scanf("%d",&arr[i]);
        arr[i] += arr[i-1];
    }

    //최대 1000 * 100000 = 100,000,000  
    //int 범위 2^32/2= 2,147
    int j=0,k=0;
    for(int i=0; i<m; i++) {
        scanf("%d %d",&j,&k);
        printf("%d\n",arr[k] - arr[j-1]);
    }

}