# include <iostream>
using namespace std;

struct Str{
    char c;
    bool replaced;
};

int main(){
    Str s;
    string s,s1,s2;
    int N,x,y;
    bool used[30] = {0};
    bool match;

    cin>>s>>N;
    while(N--){
        cin>>s1>>s2;

        for(x = 0 ; x<s.size() ; x++){
            match = true;

            for(y = 0 ; match && y<s1.size() ; y++)
                if(x+y >= s.size() || s1[y] != s[x+y] || used[x+y])
                    match = false;

            if(match){
                for(y = 0 ; y<s2.size() ; y++){
                    s[x+y] = s2[y];
                    used[x+y] = true;
                }
                break;
            }
        }
    }
    cout<<s;
}
