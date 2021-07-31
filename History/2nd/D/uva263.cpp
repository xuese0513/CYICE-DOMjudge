# include <iostream>
# include <algorithm>
# include <set>
# include <vector>
using namespace std;

int digit[9];

int digit_to_int(int l){
    int result = 0;

    for(int x = 0 ; x<l ; x++){
        result *= 10;
        result += digit[x];
    }

    return result;
}

int digit_len(int n){
    int result = 1;

    while(n/=10)
        result++;

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n,asc,des,l,x;
    bool first = true, leave;

    while(cin>>n && n!=0){

        asc = des = 0;
        leave = false;
        vector<int> chain;


        cout<<"Original number was "<<n<<'\n';

        while(!leave){
            l = digit_len(n);

            for(x = 0 ; x<l ; x++){
                digit[x] = n%10;
                n/=10;
            }

            sort(digit,digit+l);    // with ascending sort, but it should be seem as descending .
            des = digit_to_int(l);
            reverse(digit,digit+l);
            asc = digit_to_int(l);

            cout<<asc<<" - "<<des<<" = "<<(asc-des)<<'\n';
            n = asc-des;

            l = chain.size();
            for(x = 0 ; x<l && !leave ; x++)
                if(n == chain[x])
                    leave = true;

            chain.push_back(asc-des);
        }

        cout<<"Chain length "<<chain.size()<<"\n\n";
    }
}
