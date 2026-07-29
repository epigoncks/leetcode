class Solution {
public:
int fibo(int n, vector<int>& t){
    if(n <=1){
        return n;
    }

    if(t[n] != -1){
        return t[n];
    }

    t[n] = fibo(n-1, t) + fibo(n-2, t);
    return t[n];
}
    int fib(int n) {
        vector<int> dp(n+1);

        for(int i = 0; i < n+1; i++){
            dp[i] = -1;
        }

        return fibo(n, dp);
        // return 0;
    }
};