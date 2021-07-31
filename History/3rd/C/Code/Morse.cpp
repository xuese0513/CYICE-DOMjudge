# include <iostream>
# include <map>
# include <sstream>

using namespace std;

int main(){
    string morse_code[] = {".-", "-...", "-.-.", "-..", ".",
                           "..-.", "--.", "....", "..", ".---",
                           "-.-",".-..","--","-.","---",
                           ".--.","--.-",".-.","...","-",
                           "..-","...-",".--","-..-","-.--","--.."};

    map<string,char> morse;
    for( int x = 0 ; x<26; x++ )
        morse[morse_code[x]] = 'A'+x;

    int N;
    string s;

    cin>>N;
    getline(cin,s);
    while(N--){
        stringstream ss;
        getline(cin,s);
        ss<<s;

        while(ss>>s)
            cout<<morse[s];
        cout<<'\n';
    }
}
