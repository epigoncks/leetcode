class Solution {
public:
    int solve(vector<int>& cost, int n, vector<int>& t){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }

        if(t[n] != -1){
            return t[n];
        }

        t[n] = cost[n] + min(solve(cost,n-1, t), solve(cost,n-2, t));
        return t[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> t(n+1);

        for(int i = 0; i < n+1; i++){
            t[i] = -1;
        }

        return min(solve(cost, n-1, t), solve(cost, n-2, t));
    }
};