class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = INT_MAX;
        int m = cardPoints.size();
        int n = m - k;
        int temp = 0;
        int sum = 0;

        for(int i : cardPoints){
            sum += i;
        }

        for(int i = 0; i < n; i++){
            temp += cardPoints[i];
        }
        ans = temp;

        for(int i = n; i < m; i++){
            temp -= cardPoints[i-n];
            temp += cardPoints[i];
            ans = min(temp, ans);
        }

        return sum - ans;
    }
};