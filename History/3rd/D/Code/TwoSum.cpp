# include <iostream>
# include <set>
using namespace std;

int main(){
    freopen("out.txt","w",stdout);

    multiset<int> s;
    multiset<int>::iterator it;

    int N,M,n,i,ans = 0;

    cin>>N>>M;
    for(n = 0 ; n<N ; n++){
        cin>>i;
        it = s.find(M-i);

        if(it == s.end())
            s.insert(i);
        else{
            s.erase(it);
            ans++;
        }
    }

    cout<<ans<<'\n';

    for(it = s.begin() ; it != s.end() ; it++)
        cout<<*it<<' ';
}
