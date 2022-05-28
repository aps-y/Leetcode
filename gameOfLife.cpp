#include<bits/stdc++.h>

using namespace std;

int getNeighbours(vector<vector<int>>& board, int i, int j){
    int m = board.size(), n = board[0].size();
    int val = 0;
    if(i+1 != m){
        if(j!=0)
            val+=abs(board[i+1][j-1])==1 ? 1 : 0;
        val+=abs(board[i+1][j])==1 ? 1 : 0;
        if(j+1!=n)
            val+=abs(board[i+1][j+1])==1 ? 1 : 0;
    }
    if(i!=0){
        if(j!=0){
            val+=abs(board[i-1][j-1])==1 ? 1 : 0;
            
        }
        val+=abs(board[i-1][j])==1 ? 1 : 0;
        if(j+1!=n){
            val+=abs(board[i-1][j+1])==1 ? 1 : 0;
        }
    }
    if(j+1!=n)
    val+=abs(board[i][j+1]) == 1 ? 1 : 0;
    if(j!=0)
    val+=abs(board[i][j-1]) == 1 ? 1 : 0;
    return val;
}

void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = board[0].size();
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int val = getNeighbours(board, i, j);
            if(board[i][j]){
                if(val<2 || val>3)
                    board[i][j]=-1;
            }
            else{
                if(val==3)
                    board[i][j]=2;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]==-1)
            board[i][j]=0;
            else if(board[i][j]==2)
            board[i][j]=1;
        }
    }


}

int main() {
    int m,n;
    cin>>m>>n;

    vector<vector<int>> input(m, vector<int>(n,false));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>input[i][j];
        }
    }

    gameOfLife(input);

}