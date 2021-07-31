# include <bits/stdc++.h>
using namespace std;

int main(){
    fstream input, output;
    input.open("6.in",ios::out);
    output.open("6.out",ios::out);

    multiset<int> s;
    multiset<int>::iterator it;

    int N,M,n,i,ans = 0;

    cin>>N>>M;
    input<<N<<' '<<M<<'\n';

    mt19937 generator(time(NULL));
    uniform_int_distribution<long long> unif(1, M);

    i = unif(generator);
    input<<i;
    s.insert(i);

    for(n = 1 ; n<N ; n++){
        i = unif(generator);
        input<<' '<<i;
        it = s.find(M-i);

        if(it == s.end())
            s.insert(i);
        else{
            s.erase(it);
            ans++;
        }
    }

    output<<ans;
}
