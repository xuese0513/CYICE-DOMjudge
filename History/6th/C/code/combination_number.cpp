#include<bits/stdc++.h>

using namespace std;
vector<int> a;
bool first=true,f=true;
fstream input,output;
void find(int g,vector<int> &can,int p){
    if(!g){
        if(!first){
            cout << " ";
            output<<" ";
        }
        else
            first=false;
        cout<<"(" ;
        output<<"(" ;
        for(int i=0;i<a.size();++i){
            if(i!=a.size()-1){
                cout<<a[i]<<",";
                output<<a[i]<<",";
            }
            else{
                cout<<a[i]<<")";
                output<<a[i]<<")";
            }
        }
        return ;
    }

    for(int i=p;i<can.size();++i){
        if(g>=0){
            a.push_back(can[i]);
            find(g-can[i],can,i);
            a.pop_back();
        }
    }
}

int main(){
    vector<int> num;
    int n,in,target;
    input.open("2.in",ios::out);
    output.open("2.ans",ios::out);
    cin >> n >> target ;
    input<<n<<" "<<target<<endl;
    for(int i=0;i<n;++i){
        cin>>in;
        if(!f)
            input<<" ";
        else
            f=false;
        input<<in;
        num.push_back(in);
    }
    sort(num.begin(),num.end());

    find(target,num,0);
}
