# include <bits/stdc++.h>
using namespace std;

int a[200000], b[200000];

string itos(int x){
    string s;
    while(x){
        s.push_back(x%10+'0');
        x/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    mt19937 generator(time(NULL));
    uniform_int_distribution<long long> ran(0, 200000);
    uniform_int_distribution<long long> unif(0, 1000000000);
    for(int t = 6 ; t<10 ; t++){
        fstream input,output;
        input.open(itos(t) + ".in",ios::out);
        output.open(itos(t) + ".out",ios::out);


        int N,M,k,n,m,ans = 0;
        //cin>>N>>M>>k;
        //cin>>N>>M;
        N = ran(generator);
        M = ran(generator);
        k = unif(generator)/10000;
        input<<N<<' '<<M<<' '<<k<<'\n';

        input<<(a[0] = unif(generator));
        for(n = 1 ; n<N ; n++)
            input<<' '<<(a[n] = unif(generator));

        input<<'\n'<<(b[0] = unif(generator));
        for(n = 1 ; n<M ; n++)
            input<<' '<<(b[n]=unif(generator));

        sort(a,a+N);
        sort(b,b+M);

        n = m = 0;
        while(n<N && m<M){
            if(abs(a[n]-b[m])<=k)
                ans++, m++, n++;
            else if(b[m] < a[n])
                m++;
            else
                n++;
        }

        output<<ans;
    }
}
