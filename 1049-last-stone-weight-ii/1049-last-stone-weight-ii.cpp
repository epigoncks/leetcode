class Solution {
public:
    void ssos(vector<int>& arr, int n, int sum, vector<int>& ans){
        bool t[n+1][sum+1];

        for(int i = 0;i < n + 1; i++){
            for(int j = 0; j < sum + 1; j++){
                if(i == 0){
                    t[i][j] = false;
                }
                if(j == 0){
                    t[i][j] = true;
                }
            }
        }

        for(int i = 1; i < n +1; i++){
            for(int j = 1; j < sum + 1; j++){
                if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }

        // vector<int>& ans;
        for(int i = 0; i <= sum/2; i++){
            if(t[n][i] == true){
                ans.push_back(i);
            }
        }

    }
    int lastStoneWeightII(vector<int>& stones) {
        
        int n = stones.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += stones[i];
        }

        

        vector<int> ans;

        ssos(stones, n, sum, ans);

        int k = ans.size();
        int mmm = ans[k-1];

        return sum - 2*mmm;
    }
};