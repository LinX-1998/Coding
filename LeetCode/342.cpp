/* ------------------------------*/
/* Created by LinX on 2021/05/31.*/
/* ------------------------------*/
/*
 * 4的幂
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0){
            return false;
        }
        while(n>1){
            if(n%4!=0){
                return false;
            }
            n=n>>2;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    Solution s = Solution();
    while(cin>>t){
        bool ans = s.isPowerOfFour(t);
        cout<<ans<<endl;
    }
    return 0;
}


