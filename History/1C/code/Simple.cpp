# include <iostream>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);

    long long a[3][3];
    long long result;
    int T,x,y;

    cin>>T;
    while(T--){
        for(x = 0 ; x<3 ; x++)
            for(y = 0 ; y<3 ; y++)
                cin>>a[x][y];

        result = a[0][0] * (a[1][1]*a[2][2] - a[2][1]*a[1][2]) +
                 a[0][1] * (a[1][2]*a[2][0] - a[2][2]*a[1][0]) +
                 a[0][2] * (a[1][0]*a[2][1] - a[2][0]*a[1][1]);

        cout<<result<<'\n';
    }


}
