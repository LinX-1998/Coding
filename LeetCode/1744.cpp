/* ------------------------------*/
/* Created by LinX on 2021/06/01.*/
/* ------------------------------*/
/*
 * 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
 */
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<bool>ans;
        int len = candiesCount.size();
        long long sum[len+10];
        memset(sum, 0, sizeof(sum));
        for(int i=0;i<len;i++){
            sum[i+1] = sum[i] + candiesCount[i];
        }
        int level = queries.size();
        for(int i=0;i<level;i++){
            int type = queries[i][0];
            long long day = queries[i][1];
            long long eat = queries[i][2];
            if(day+1>sum[type+1]){
                ans.push_back(false);
            }
            else if((day+1)*eat<=sum[type]){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    Solution s = Solution();
    vector<int> nums1 = {7,4,5,3,8};
    vector<vector<int>> nums2 = {{0,2,2}, {4,2,4}, {2,13,100000000}};
    vector<bool> ans = s.canEat(nums1, nums2);
    for(int j=0;j<ans.size();j++) {
        cout << ans[j] << endl;
    }
    return 0;
}