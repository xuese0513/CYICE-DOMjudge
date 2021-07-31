#include <bits/stdc++.h>
using namespace std;


char alp(int a){
    return a < 10 ? '0'+a : a < 36 ? 'a'+a-10 : 'A'+a-36;
}

// Driver code
int main() {

    mt19937 generator(time(NULL));
    uniform_int_distribution<int> alpha(0,61);    // 0~9, a~z, A~Z
    uniform_int_distribution<int> len(1,7);

    fstream input,output;
    input.open("2.in",ios::out);
    output.open("2.out",ios::out);

    int T,l,x;
    string s;

    cin>>T;
    input<<T<<'\n';
    getline(cin,s);

    while(T--) {
        /*
        bool used[62] = {0};
        l = len(generator);
        //l = 7;
        while(l--){
            while(used[x = alpha(generator)]);
            used[x] = true;
            s.push_back(alp(x));
        }
        */
        getline(cin,s);
        input<<s<<'\n';

        sort(s.begin(), s.end());
        do {
           output << s << endl;
        } while (next_permutation(s.begin(), s.end()));
    }
}
