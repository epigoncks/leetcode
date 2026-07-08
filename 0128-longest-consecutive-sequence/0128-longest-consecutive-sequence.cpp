class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int ans = 1;
        int count = 1;
        for(int i = 0; i<nums.size()-1; i++){
            // int count = 0;
            if(nums[i+1] == nums[i]){
                continue;
            }
            else if(nums[i+1]-nums[i] == 1){
                count++;
            }
            else{
                ans = max(count, ans);
                count = 1;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};