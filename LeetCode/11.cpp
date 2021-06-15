/* ------------------------------*/
/* Created by LinX on 2021/6/2.*/
/* ------------------------------*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int pos1 = 0;
        int pos2 = len-1;
        int ans = 0;
        ans = max((pos2-pos1)*min(height[pos1], height[pos2]), ans);
        while(pos2>pos1){
            if(height[pos1]<height[pos2]){
                pos1++;
            }
            else{
                pos2--;
            }
            ans = max((pos2-pos1)*min(height[pos1], height[pos2]), ans);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k=7;
    Solution s = Solution();
    vector<int> nums = {1,2,1};
    int ans = s.maxArea(nums);
    cout<<ans<<endl;
    return 0;
}

