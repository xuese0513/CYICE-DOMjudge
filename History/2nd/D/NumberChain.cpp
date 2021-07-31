# include <iostream>
# include <algorithm>
# include <set>
# include <string>
using namespace std;

int sstoi(string s){
    int r = 0;

    for(int x = 0 ; x<s.size() ; x++)
        r = r*10 + s[x]-'0';

    return r;
}

string itos(int i){
    string s;
    while(i){
        s.push_back('0' + i%10);
        i/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    int a,b,len;
    string str;
    set<string> chain;

    while(cin>>str && str != "0"){
        set<string> chain;
        len = 0;
        cout<<"Original number was "<<str<<'\n';

        do{
            len++;

            sort(str.begin(), str.end(), greater<char>());
            a = sstoi(str);
            sort(str.begin(), str.end(), less<char>());
            b = sstoi(str);

            cout<<a<<" - "<<b<<" = "<<a-b<<'\n';
            str = itos(a-b);
        } while(chain.insert(str).second);
        cout<<"Chain length "<<len<<"\n\n";
    }
}
