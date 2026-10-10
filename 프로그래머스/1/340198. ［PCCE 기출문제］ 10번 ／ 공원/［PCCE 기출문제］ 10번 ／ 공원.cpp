#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int board[51][51];

bool check(int x,int y,int num){
    for (int i=x;i<x+num;i++){
        for (int j=y;j<y+num;j++){
            if (board[i][j]!=-1){
                return false;
            }
        }
    }
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    for (int i=0;i<park.size();i++){
        for (int j=0;j<park[0].size();j++){
            if (park[i][j]!="-1"){
                board[i][j]=park[i][j][0]-'A';
            }else{
                board[i][j]=-1;
            }
        }
    }
    int N= park.size();
    int M=park[0].size();
    
    sort(mats.begin(),mats.end(),greater<int>());
    
    for (int i=0;i<mats.size();i++){
        int now = mats[i];
        for (int j=0;j<N-now+1;j++){
            for (int k=0;k<M-now+1;k++){
                if (check(j,k,now)){
                    return now;
                }
            }
        }
    }
    
    return -1;
}