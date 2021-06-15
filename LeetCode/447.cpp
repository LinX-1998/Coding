/* ------------------------------*/
/* Created by LinX on 2021/05/28.*/
/* ------------------------------*/
/*
 * 汉明距离总和
 */
#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int len = nums.size();
        int binary[len][40];
        memset(binary, 0, sizeof(binary));
        for(int i=0;i<len;i++){
            int number = nums[i];
            int pos = 0;
            while(number){
                binary[i][pos++] = number%2;
                number = number>>1;
            }
        }
        int sum = 0;
        for(int i=0;i<40;i++){
            int num_0 = 0;
            int num_1 = 0;
            for(int j=0;j<len;j++){
                if(binary[j][i]){
                    num_1 += 1;
                }
                else {
                    num_0 += 1;
                }
            }
            sum += num_0*num_1;
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int>n;
    n.clear();
    int t;
    Solution s = Solution();
    while(cin>>t) {
        n.push_back(t);
        if(cin.get()=='\n')
            break;
    }
    int ans = s.totalHammingDistance(n);
    cout<<ans<<endl;
    return 0;
}
