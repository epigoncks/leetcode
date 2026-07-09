class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0;
        int b = INT_MAX;
        int s = INT_MIN;

        int n = prices.size();
        int i = 0;

        while(i < n){
            b = min(b, prices[i]);
            p = max(p, prices[i]-b);
            i++;
        }

        return p;
    }
};