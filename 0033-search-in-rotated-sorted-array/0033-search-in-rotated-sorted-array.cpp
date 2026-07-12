class Solution {
public:
    int search(vector<int>& nums, int target) {
        target;
        int found = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                found = i;
            }
        }
        return found;
    }
};