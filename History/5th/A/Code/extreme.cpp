# include <bits/stdc++.h>
using namespace std;

int main(){

    mt19937 generator(time(NULL));
    uniform_int_distribution<long long> unif(0, 1000);
    uniform_int_distribution<long long> alpha(0, 25);

    fstream input,output;
    input.open("2.in",ios::out);
    output.open("2.out",ios::out);

    int T,l,x,y,maxx,maxy;

    cin>>T;
    input<<T<<'\n';
    while(T--){
        string s;

        l = 1000;
        for(x = 0 ; x<l ; x++)
            s.push_back('a');
        input<<s<<'\n';

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

        output<<s.substr(maxx, maxy)<<'\n';
    }

}
