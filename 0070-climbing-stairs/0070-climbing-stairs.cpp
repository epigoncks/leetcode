class Solution {
public:
    int solve(int n, int i, vector<int>& t){

        


        if(i == n){
            return 1;
        }
        if(i > n){
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }

        t[i] = solve(n, i+1, t) + solve(n, i+2, t); 
        return t[i];
    }
    int climbStairs(int n) {

        vector<int> t(n+1);
        for(int i = 0; i < n+1; i++){
            t[i] = -1;
        }
        
        return solve(n, 0, t);
    }
};