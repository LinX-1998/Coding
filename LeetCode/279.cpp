/* ------------------------------*/
/* Created by LinX on 2021/06/11.*/
/* ------------------------------*/
/*
 * 完全平方数
 * 思路:
 *
 */
#include<iostream>
#include<cmath>
using namespace std;
#define N 100;

class Solution {
public:
    int dfs(int n, int pos){
        int ans = 10000;
        if(n<0){
            return 10000;
        }
        if(n==0){
            return pos;
        }
        for(int i=sqrt(n);i>=1;i--){
            ans = min(dfs(n-i*i, pos+1),ans);
        }
        return ans;
    }
    int numSquares(int n) {
        return dfs(n, 0);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution s = Solution();
    int ans = s.numSquares(12);
    cout<<ans<<endl;
    return 0;
}

