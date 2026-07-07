class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int num : nums){
            freq[num]++;
        }

        using pii = pair<int,int>;
        priority_queue<
            pii,
            vector<pii>,
            greater<pii>
            > min_heap;

        for(auto &p : freq){
            min_heap.push({p.second, p.first});

            if(min_heap.size() > k){
                min_heap.pop();
            }
        }

        vector<int> ans;
        while(!min_heap.empty()){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }   

        return ans;


    }
};