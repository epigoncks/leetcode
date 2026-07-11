class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            int l = i;
            int r = i;
            while(l >= 0 && r < s.size()){
                if(s[l] == s[r]){
                    if(r-l+1 > max){
                        max = r-l+1;
                        ans = "";
                        for(int k = l; k <= r; k++){
                            ans += s[k];
                        }
                    }
                    l--;
                    r++;

                }
                else{
                    break;
                }
            }
        }
        for(int i = 0; i < s.size(); i++){
            int l = i;
            int r = i+1;
            while(l >=0 && r < s.size()){
                if(s[l] == s[r]){
                    if(r-l+1 > max){
                        max = r-l+1;
                        ans = "";
                        for(int k = l; k <= r; k++){
                            ans += s[k];
                        }
                    }
                    l--;
                    r++;
                }
                else{
                    break;
                }
            }
        }
            return ans;
        }
};