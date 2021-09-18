# include <bits/stdc++.h>
using namespace std;

int m[102][102];

struct Fill{
    int x,y,t;
};

vector<Fill> v;

int main(){
    fstream input, output;

    input.open("5.in", ios::out);
    output.open("5.out", ios::out);

    int way[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int L,W,t,x,y,i = 0;

    cin>>L>>W>>t;
    input<<L<<' '<<W<<' '<<t<<'\n';
    // boundary
    for(x = 0 ; x<=L+1 ; x++)
        m[x][0] = m[x][W+1] = 1;
    for(x = 0 ; x<=W+1 ; x++)
        m[0][x] = m[L+1][x] = 1;
    // input
    for(x = 1 ; x<=L ; x++){
        for(y = 1 ; y<=W ; y++){
            m[x][y] = rd(g);
            if(y>1)
                input<<' ';
            m[x][y] = (m[x][y]>=10 ? 0 : m[x][y]>0 ? 1 : 2);
            input<<m[x][y];
            if(m[x][y] == 2)
                v.push_back({x,y,0});
        }
        input<<'\n';
    }
    // BFS
    while(i<v.size()){
        //cout<<v.size()<<' '<<v[i].x<<' '<<v[i].y<<'\n';
        for(x = 0 ; x<4 ; x++){
            if(v[i].t < t && !m[v[i].x+way[x][0]][v[i].y+way[x][1]]){
                v.push_back({v[i].x+way[x][0], v[i].y+way[x][1], v[i].t+1});
                m[v[i].x+way[x][0]][v[i].y+way[x][1]] = v[i].t+1;
            }
        }
        i++;
    }

    output<<v.size();
}
