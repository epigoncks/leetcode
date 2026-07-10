class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int ans = INT_MIN;

        while(l < r){
            int h = min(height[l], height[r]);
            int area = h * (r-l);
            ans = max(ans, area);
            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};