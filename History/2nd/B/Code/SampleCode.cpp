# include <iostream>
# include <stack>
using namespace std;

int main(){
    int T;
    string s;
    int l,x;
    bool ans;

    cin>>T;
    getline(cin,s);
    while(T--){
        getline(cin,s);
        stack<char> paren;
        ans = true;
        l = s.size();

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

        cout<<(ans && paren.empty() ? "Yes\n" : "No\n");
    }
}
