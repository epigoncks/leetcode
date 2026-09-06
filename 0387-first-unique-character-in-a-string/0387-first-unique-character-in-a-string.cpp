class Solution {
public:
    int firstUniqChar(string s) {
        if(s.length() == 1){
            return 0;
        }
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < s.length(); j++){
                if(i == j && i != s.length()-1){
                    continue;
                }
                if(s[i] != s[j] && j == s.length()-1 || s[i] == s[j] && i == s.length()-1 && j == s.length()-1){
                    return i;
                }
                else if(s[i] == s[j]){
                    break;
                }
                
            }
        }
        return -1;
    }
};