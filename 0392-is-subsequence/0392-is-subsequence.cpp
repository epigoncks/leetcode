class Solution {
public:
    bool sub(string a, string b, int n, int m){
        int t[n+1][m+1];

        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < m + 1; j++){
                if(i == 0 || j == 0){
                    t[i][j] = 0;
                }
            }
        }

        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < m +1; j++){
                if(a[i-1] == b[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }
            }
        }
        if(t[n][m] == n){
            return true;
        }
        else{
            return false;
        }
    }
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        return sub(s, t, n, m);
    }
};