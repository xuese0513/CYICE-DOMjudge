# include <bits/stdc++.h>
using namespace std;

int main(){
    fstream input, output;

    int T;
    string s;
    int x,l;
    int left;

    input.open("sample.in", ios::out);
    output.open("sample.out", ios::out);

    mt19937 generator( time(NULL) );
    uniform_int_distribution<int> bin(0, 1);
    uniform_int_distribution<int> unif(1, 15);

    cin>>T;
    input<<T<<'\n';
    while(T--){
        l = unif(generator);
        s.resize(l);
        left = 0;
        for(x = 0 ; x<l ; x++)
            s[x] = bin(generator) + '(';

        for(x = 0 ; x<l && left>=0; x++){
            if(s[x] == '(')
                left++;
            else
                left--;
        }

        input<<s<<'\n';
        if(left == 0 && !s.empty())
            cout<<s<<'\n';
        output<<(left == 0 ? "Yes\n" : "No\n");
    }
}
