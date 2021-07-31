# include <bits/stdc++.h>
using namespace std;

int main(){
    int T,l,x,y,maxx,maxy;
    string s;

    cin>>T;
    while(T--){
        cin>>s;
        l = s.size();

        maxx = 0, maxy = 1;

        for(x = 0 ; x<l ; x++){
            // odd
            for(y = 1 ; x-y>-1 && x+y<l && s[x-y] == s[x+y] ; y++);
            if(--y*2+1 > maxy){
                maxx = x-y;
                maxy = 2*y+1;
            }

            // even
            for(y = 1 ; x-y+1>-1 && x+y<l && s[x-y+1] == s[x+y] ; y++);
            if(--y*2 > maxy){
                maxx = x-y+1;
                maxy = 2*y;
            }
        }

        cout<<s.substr(maxx, maxy)<<'\n';
    }

}
