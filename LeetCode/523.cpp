/* ------------------------------*/
/* Created by LinX on 2021/06/02.*/
/* ------------------------------*/
/*
 * 注意潜在的两个条件 * * *
 * 连续的子数组和
 */
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int>check;
        check.clear();
        int len = nums.size();
        int sum[len+10];
        memset(sum, 0, sizeof(sum));
        for(int i=0;i<len;i++){
            sum[i+1] = sum[i] + nums[i];
        }
        for(int i = 0;i<=len;i++){
            int v = sum[i]%k;
            if(check.count(v)==0){
                check[v]=i;
            }
            else{
                if(i-check[v]>=2) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k=7;
    Solution s = Solution();
    vector<int> nums = {23,2,4,6,6};
    bool ans = s.checkSubarraySum(nums, k);
    cout<<ans<<endl;
    return 0;
}