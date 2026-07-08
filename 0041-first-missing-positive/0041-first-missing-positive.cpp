class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        vector<bool> present(n+1, false);

        for(int x : nums){
            if(x >=1 && x <= n){
                present[x] = true;
            }           
        }
        for(int i = 1; i <= n; i++){
            if(!present[i]){
                return i;
            }
        }
        return n + 1;
    }
};