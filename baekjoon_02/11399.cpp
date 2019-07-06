#include <iostream>
#include <algorithm>
/*
ATM
시간 복잡도 o(n^2)
최대 500,000,000 정도 나올 수 있음
int : ~ 2,147,438,647
unsigned int : ~4,294,967,295
printf 할 때 short int 출력하게 해서 틀렸음
 */
int main() {
    unsigned short int n;
    unsigned short int arr[1000];
    unsigned int sum {0};
    scanf("%hd",&n);

    for(auto i=0; i<n; i++) {
        scanf("%hd",&arr[i]);
    }
    std::sort(arr, arr+n);
  /* for(auto i=0; i<n; i++) {
        for(auto j=0; j<=i; j++) {
            sum += arr[j];
        }
    }*/
    for(auto i=0; i<n; i++) {
        sum += (n-i)*arr[i];
    }
    printf("%u\n",sum);
}