# include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int T;
    string s;
    int l,x;
    bool ans;
    fstream input, output;

    input.open("sample.in", ios::out);
    output.open("sample.out", ios::out);

    mt19937 generator( time(NULL) );
    uniform_int_distribution<int> bin(0, 3);
    uniform_int_distribution<int> unif(0, 15);

    char p[4] = {'(',')','[',']'};

    cin>>T;
    input<<T<<'\n';
    while(T--){
        stack<char> paren;
        ans = true;
        l = unif(generator);
        s.resize(l);

        for(x = 0 ; x<l ; x++)
            s[x] = p[bin(generator)];

        for(x = 0 ; x<l && ans ; x++){

            switch(s[x]){
            case '(':
                paren.push('(');
                break;

            case ')':
                if(paren.empty() || paren.top() != '(')
                    ans = false;
                else
                    paren.pop();
                break;

            case '[':
                paren.push('[');
                break;

            case ']':
                if(paren.empty() || paren.top() != '[')
                    ans = false;
                else
                    paren.pop();
                break;
            }
        }
        input<<s<<'\n';
        if(ans && paren.empty() && !s.empty())
            cout<<s<<' '<<(ans && paren.empty() ? "Yes\n" : "No\n");
        output<<(ans && paren.empty() ? "Yes\n" : "No\n");
    }
}
