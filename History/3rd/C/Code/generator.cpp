# include <bits/stdc++.h>

using namespace std;

int main(){
    string morse_code[] = {".-", "-...", "-.-.", "-..", ".",
                           "..-.", "--.", "....", "..", ".---",
                           "-.-",".-..","--","-.","---",
                           ".--.","--.-",".-.","...","-",
                           "..-","...-",".--","-..-","-.--","--.."};

    map<char,string> to_morse;
    fstream input, output;

    input.open("3.in",ios::out);
    output.open("3.out",ios::out);
    mt19937 generator(time(NULL));
    uniform_int_distribution<long long> unif(1, 1000);
    uniform_int_distribution<long long> alpha(0, 25);


    for( int x = 0 ; x<26; x++ )
        to_morse['A'+x] = morse_code[x];


    int N,l,x;
    string s;

    cin>>N;
    input<<N<<'\n';
    while(N--){
        l = 1000;
        //l = unif(generator);
        x = alpha(generator);
        output<<(char)('A'+x);
        input<<to_morse['A'+x];

        while(--l){
            x = alpha(generator);
            output<<(char)('A'+x);
            input<<' '<<to_morse['A'+x];
        }

        output<<'\n';
        input<<'\n';

    }
}
