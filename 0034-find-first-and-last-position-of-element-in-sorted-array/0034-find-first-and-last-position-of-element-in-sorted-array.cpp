class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        int l = 0;
        int r = nums.size() - 1;
        int i = l + (r - l) / 2;
        int found = -1;

        while (l <= r) {
            if (nums[i] == target) {
                found = i;
                break;
            } else if (nums[i] < target) {
                l = i + 1;
                i = l + (r - l) / 2;
            } else {
                r = i - 1;
                i = l + (r - l) / 2;
            }
        }

        if(found == -1){
            return {-1, -1};
        }

        int s = i;
        while (s >= 0 && nums[s] == target)
            s--;

        int e = i;
        while (e < nums.size() && nums[e] == target)
            e++;

        return {s + 1, e - 1};
    }
};