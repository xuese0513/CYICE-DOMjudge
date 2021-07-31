#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long n;
    vector<long> pos;

    while (cin >> n && n){
        pos.clear();
        cout << "Original number was " << n << '\n';
        long num1,num2;
        long n1{0};
        num2=n;
        bool tes{true};

        while (tes){
            num1=n=0;
            int ans[10]{0};

            while (num2!=0){
                ans[num2%10]++;
                num2/=10;
            }

            for (int i=0;i<10;i++){
                for (long j=0 ; j<ans[i] ; j++)
                    num1=num1*10+i;

                for (long j=0 ; j<ans[9-i] ; j++)
                    n=n*10+(9-i);
            }

            num2=n-num1;
            pos.push_back(num2);
            n1++;
            cout << n << " - " << num1 << " = " << num2 << '\n';
            for (int i=0;i<pos.size()-1;i++) {
                if (pos[i] == num2) {tes=false; break;}
            }
        }
        cout << "Chain length " << pos.size() << "\n\n";
    }
}
