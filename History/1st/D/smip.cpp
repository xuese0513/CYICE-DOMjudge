#include <bits/stdc++.h>
#define _for(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define _rep(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
using namespace std;

int gcd(int x,int y){
	for (;;)
	{
		int c= x%y;
		if (c == 0)	return y;
		else {
			x=y;
			y=c;
		}
	}
}

int solve(int n){
		//if (n ==0) break;
		int g=0;
		_for(i,1,n){
			_rep(j,i+1,n){
				g += gcd(i,j);
			}
		}
		//printf("%d\n",g);
        return g;
}

int main(){
    srand(time(NULL));
    fstream input, output;
    input.open("5.in",ios::out);
    output.open("5.out",ios::out);
    int n{rand()%100+1};
    //int n{99};
    for (int i{};i<n;i++){
        int t{rand()%500+2};
        input<<t << '\n';
        output<<solve(t) << '\n';
    }    
}
