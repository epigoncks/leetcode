class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> t;
        int n = temperatures.size();
        vector<int> ans(n);
        int i  = 1;
        
        t.push(0);

        while(i < n){
            while(!t.empty() && temperatures[i] > temperatures[t.top()]){
                ans[t.top()] = i - t.top();
                t.pop();
            }
            
            t.push(i);
            i++;

        }
        while(!t.empty()){
            ans[t.top()] = 0;
            t.pop();
        }

        return ans;
    }
};