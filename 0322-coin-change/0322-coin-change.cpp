class Solution {
public:
    int cc(vector<int>& arr, int n, int sum){
        int t[n+1][sum+1];

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <=sum; j++){
                if(i == 0){
                    t[i][j] = INT_MAX - 1;
                }
                if(j == 0){
                    t[i][j] = 0;
                }
            }
        }

        for(int i = 1; i < sum + 1; i++){
            if(i % arr[0] == 0){
                t[1][i] = i / arr[0];
            }
            else{
                t[1][i] = INT_MAX - 1;
            }
        }

        for(int i = 2; i < n + 1; i++){
            for(int j = 1; j <= sum; j++){
                if(arr[i-1] <= j){
                    t[i][j] = min(1 + t[i][j-arr[i-1]], t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }

        if(t[n][sum] == INT_MAX - 1){
            return -1;
        }

        return t[n][sum];
    }

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();

        return cc(coins, n, amount);

    }
};