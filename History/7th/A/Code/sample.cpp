# include <bits/stdc++.h>
using namespace std;

void paren(int n, int l, string s){
    if(l<0 || n<0)
        return;
    if(n == 0 && l == 0){
        cout<<s<<'\n';
        return;
    }

    paren(n-1, l+1, s+'(');
    paren(n-1, l-1, s+')');
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n;
    while(cin>>n){
        paren(n*2,0,"");
        cout<<'\n';
    }
}
