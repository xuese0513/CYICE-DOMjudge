# include <iostream>
using namespace std;

int main(){
    long long N,num,sum;

    cin>>N;
    sum = N*(N+1)/2;
    while(--N){
        cin >> num;
        sum -= num;
    }
    cout<<sum;
}
