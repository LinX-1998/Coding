/* ------------------------------*/
/* Created by LinX on 2021/06/07.*/
/* ------------------------------*/
/*
 * 目标和
 */
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dfs(vector<int>&nums, int sum, int pos, int all){
        int ans = 0;
        if(sum==0){
            return 1;
        }
        if(sum<0||pos>=all){
            return 0;
        }
        ans += dfs(nums, sum-nums[pos], pos+1, all);
        ans += dfs(nums, sum, pos+1, all);
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        sort(nums.rbegin(), nums.rend());
        int sum = 0;
        int check = 0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==0){
                check++;
            }
            sum += nums[i];
        }
        sum -= target;
        if(sum<0||sum%2!=0){
            return 0;
        }
        sum /= 2;
        int ans=0;
        if(check!=0){
            ans += dfs(nums, sum, 0, nums.size()-check);
            for(int i=1;i<=check;i++) {
                ans = ans * 2;
            }
        }
        else {
            ans += dfs(nums, sum, 0, nums.size());
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution s = Solution();
    vector<int> nums = {0,0,0,0,0,0,0,0,1};
    int ans = s.findTargetSumWays(nums, 1);
    cout<<ans<<endl;
    return 0;
}