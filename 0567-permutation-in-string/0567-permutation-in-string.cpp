class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }

        vector<int> need(26, 0);
        vector<int> window(26,0);

        int k = s1.size();

        for(char c : s1){
            need[c-'a']++;
        }

        for(int i = 0; i < s2.size(); i++){
            window[s2[i]-'a']++;

            if(i >= k){
                window[s2[i-k]-'a']--;
            }

            if(need == window){
                return true;
            }
        }
        return false;
    }
};