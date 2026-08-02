class Solution {
public:
    int subsetsum(vector<int>& arr, int n, int target){
        vector<vector<int>> t(n + 1, vector<int>(target + 1));

        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < target + 1; j++){
                if(i == 0){
                    t[i][j] = 0;
                }
                if(j == 0){
                    t[i][j] = 1;
                }
            }
        }

        for(int i = 1; i < n+1; i++){
            for(int j = 0; j < target + 1; j++){
                if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][target];
    }
    int findTargetSumWays(vector<int>& nums, int diff) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        
        if(abs(diff) > sum){
            return 0;
        }

        if((sum + diff) % 2 != 0){
            return 0;
        }

        int target = (sum + diff)/2;

        

        int n = nums.size();

        return subsetsum(nums, n, target);

    }
};