/* ------------------------------*/
/* Created by LinX on 2021/06/11.*/
/* ------------------------------*/
/*
 * 最长回文子串
 * 思路:
 * 确定中心回文串后遍历模拟
 */
#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int ans[2];
        int len = s.size();
        for(int i=0;i<len;i++){
            int high=i;
            int low=i;
            while(high<len-1&&s[i]==s[high+1]){
                high++;
            }
            i = high;
            while(low-1>=0&&high+1<len&&s[low-1]==s[high+1]){
                high++;
                low--;
            }
            if(high-low>ans[1]-ans[0]){
                ans[0]=low;
                ans[1]=high;
            }
        }
        return s.substr(ans[0], ans[1]-ans[0]+1);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution s = Solution();
    string ans = s.longestPalindrome("babad");
    cout<<ans<<endl;
    return 0;
}

