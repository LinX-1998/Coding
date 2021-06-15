/* ------------------------------*/
/* Created by LinX on 2021/05/30.*/
/* ------------------------------*/
/*
 * 2 的幂
 */

#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n>1){
            if(n%2!=0){
                return false;
            }
            n=n>>1;
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
        bool ans = s.isPowerOfTwo(t);
        cout<<ans<<endl;
    }
    return 0;
}