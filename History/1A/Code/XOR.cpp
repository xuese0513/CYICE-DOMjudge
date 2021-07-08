# include <iostream>
using namespace std;

int main(){
    int N,n,ans = 0;
    cin>>N;

    for(n = 1 ; n<=N ; n++)
        ans ^= n;

    while(--N){
        cin>>n;
        ans ^= n;
    }
    cout<<ans;
}
