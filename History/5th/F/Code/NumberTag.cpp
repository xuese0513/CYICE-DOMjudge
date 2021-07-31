# include <iostream>
using namespace std;

int main(){
    string s,s1,s2;
    int N,x;

    cin>>s>>N;
    while(N--){
        cin>>s1>>s2;
        for(x = 0 ; x<s2.size() ; x++)
            s2[x] += 26;

        s.replace(s.find(s1),s1.size(),s2);
    }
    for(x = 0 ; x<s.size() ; x++)
        if(s[x]>90)
            s[x] -= 26;

    cout<<s;
}
