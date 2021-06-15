/* ------------------------------*/
/* Created by LinX on 2021/5/28.*/
/* ------------------------------*/
/*
 * 无重复字符的最长子串
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是"wke"，所以其长度为 3。请注意，
 *      你的答案必须是 子串 的长度，"pwke"是一个子序列，不是子串。
 */

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>check;
        check.clear();
        int ans = 0;
        int sum=0;
        int pos = 0;
        int len = s.size();
        for(int i=0;i<len;i++) {
            if(check.count(s[i])==0){
                check.insert(s[i]);
                sum += 1;
            }
            else{
                ans = max(ans, sum);
                while(check.count(s[i])!=0){
                    check.erase(s[pos++]);
                    sum -= 1;
                }
                check.insert(s[i]);
                sum += 1;
            }
        }
        ans = max(ans, sum);
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string t="";
    Solution s = Solution();
    getline(cin,t);
    int ans = s.lengthOfLongestSubstring(t);
    cout<<ans<<endl;
    return 0;
}