/* ------------------------------*/
/* Created by LinX on 2021/05/31.*/
/* ------------------------------*/
/*
 * 寻找两个正序数组的中位数
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int pos1 = 0,pos2 = 0;
        double ans = 0;
        int mid = (nums1.size()+nums2.size()+1)/2;
        printf("%d\n", mid);
        while(mid--){
            if(pos1==nums1.size()){
                pos2++;
            }
            else if(pos2==nums2.size()){
                pos1++;
            }
            else{
                if(nums1[pos1]>=nums2[pos2]){
                    pos2++;
                }
                else{
                    pos1++;
                }
            }
        }
        if((nums1.size()+nums2.size())%2==0){
            ans = (nums1[pos1]+nums2[pos2])/2.0;
        }
        else{
            ans = max(nums1[pos1],nums2[pos2]);
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
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    double ans = s.findMedianSortedArrays(nums1, nums2);
    cout<<ans<<endl;
    return 0;
}