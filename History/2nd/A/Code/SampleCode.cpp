# include <iostream>
using namespace std;

int main(){
    int T;
    string s;
    int x,l;
    int left;

    cin>>T;
    getline(cin,s);
    while(T--){
        getline(cin,s);
        left = 0;
        l = s.size();

        for(x = 0 ; x<l && left>=0; x++){
            if(s[x] == '(')
                left++;
            else if(s[x] == ')')
                left--;
        }

        cout<<(left == 0 ? "Yes\n" : "No\n");

    }
}
