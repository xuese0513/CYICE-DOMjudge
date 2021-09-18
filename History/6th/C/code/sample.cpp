# include <bits/stdc++.h>
using namespace std;

int arr[30];
int N;
/*
string to_string(int n){
	string s;
	while(n)
		s += '0'+n%10;
	return s;
}*/

void f(int t, string s){
	if(t == 0){
		//s = s.substr(s.size()-1);
		s.pop_back();
		cout<<s<<") ";
	}
	else if(t<0)
		return;

	for(int n = 0 ; n<N ; n++)
		f(t-arr[n], s + to_string(arr[n]) + "," );	// f(t-a, "(s,a,");
}

int main(){
	int n,t;
	cin>>N>>t;
	for(n = 0 ; n<N ; n++)
		cin>>arr[n];
	sort(arr,arr+N);
	f(t,"(");
}
