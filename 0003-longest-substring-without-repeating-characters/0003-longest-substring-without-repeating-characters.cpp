class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.size() == 0){
            return 0;
        }
        int l = 0;
        int maxf = 1;
        vector<int> freq(128,0);

        for(int r = 0; r < s.size(); r++){
            freq[s[r]]++;

            while(freq[s[r]] > 1){
                freq[s[l]]--;
                l++;
            }

            maxf = max(maxf, r - l + 1);
        }

        return maxf;
    }
};