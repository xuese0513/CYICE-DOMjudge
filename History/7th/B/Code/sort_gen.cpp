# include <bits/stdc++.h>
using namespace std;

struct Node{
    int val, depth;
    Node *left, *right;

    Node(int v, int h){
        val = v, depth = h;
        left = right = nullptr;
    }
};

bool stric_tree(Node *node){
    if(node == nullptr || (node->left == nullptr && node->right == nullptr))
        return true;

    if(node->left == nullptr || node->right == nullptr)
        return false;

    return stric_tree(node->left) && stric_tree(node->right);
}

void DFS(Node *node){
    if(node == nullptr)
        return;

    DFS(node->left);
    cout<<node->val<<' ';
    DFS(node->right);
}

int main(){

    fstream input, output;
    input.open("3.in", ios::out);
    output.open("3.out", ios::out);
    mt19937 generator(time(NULL));

    int N,n = 1000;
    Node *root, *cur;
    int height = 1;

    cin>>N;
    input<<N<<'\n'<<n--;
    root = new Node(n,1);


    while(--N){
        input<<' '<<n--;
        cur = root;

        while(true){

            if(n > cur->val){
                if (cur->right == nullptr){
                    cur->right = new Node(n,cur->depth+1);
                    height = max(height,cur->depth+1);
                    break;
                }
                cur = cur->right;
            }
            else{
                if(cur->left == nullptr){
                    cur->left = new Node(n,cur->depth+1);
                    height = max(height,cur->depth+1);
                    break;
                }
                cur = cur->left;
            }
        }
    }
    output<<(stric_tree(root) ? "True" : "False")<<' '<<height<<'\n';
}
