#include<iostream>
#include<vector>
using namespace std;
bool nomoves(vector<vector<char>>&board){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' '){
                return false;
            }
        }
    }
    return true;
}
int gameover(vector<vector<char>>&board){
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            if(board[i][0]=='X'){
                return 10;
            }
            if(board[i][0]=='O'){
                return -10;
            }
        }
    }
    for(int i=0;i<3;i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            if(board[0][i]=='X'){
                return 10;
            }
            if(board[0][i]=='O'){
                return -10;
            }
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        if(board[0][0]=='X'){
            return 10;
        }
        if(board[0][0]=='O'){
            return -10;
        }
    }
    if(board[2][0]==board[1][1] && board[1][1]==board[0][2]){
        if(board[2][0]=='X'){
            return 10;
        }
        if(board[2][0]=='O'){
            return -10;
        }
    }
    return 0;
}
int minimax(vector<vector<char>>&board,bool maxp,pair<int,int>&p,int depth){
    if(gameover(board)!=0){
        return gameover(board);
    }
    if(depth==0){
        return 0;
    }
    if(maxp){
        int mx=INT_MIN;
        pair<int,int>a;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==' '){
                    board[i][j]='X';
                    a=make_pair(i,j);
                    int k=minimax(board,false,a,depth-1);
                    board[i][j]=' ';
                    if(k>mx){
                        mx=k;
                        p=make_pair(i,j);
                    }
                }
            }
        }
        return mx;
    }
    else{
        int mn=INT_MAX;
        pair<int,int>a;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==' '){
                    board[i][j]='O';
                    a={i,j};
                    int k=minimax(board,true,a,depth-1);
                    board[i][j]=' ';
                    if(k<mn){
                        mn=k;
                        p=make_pair(i,j);
                    }
                }
            }
        }
        return mn;
    }
}
void print(vector<vector<char>>&board){
    printf("\n\n");
    printf("\t\t\t %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
    printf("\t\t\t-----------\n");
    printf("\t\t\t %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
    printf("\t\t\t-----------\n");
    printf("\t\t\t %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
    return;
}
pair<int,int> helper(vector<vector<char>>board,bool flag,int depth){
    pair<int,int>p;
    minimax(board,flag,p,depth);
    return p;

}
int main(){
    vector<vector<char>>board(3,vector<char>(3,' '));

    int i=0;
    print(board);
    while(!gameover(board) && !nomoves(board)){
        if(i%2==0){
            printf("Enter coordinates:");
            int x,y;
            cin>>x>>y;
            while(board[x-1][y-1]!=' '){
                cout<<"Enter Valid Coordinates!\n";
                cin>>x>>y;
            }
            board[x-1][y-1]='X';
        }
        else{
            pair<int,int>p=helper(board,false,9-i);
            board[p.first][p.second]='O';

        }
        print(board);
        i++;
    }
    if(nomoves(board)){
        printf("Game Drawn!!\n");
    }
    else if(i%2){
        printf("YOU WON!!\n");
    }
    else{
        printf("COMPUTER WON!!\n");
    }
    return 0;
}
