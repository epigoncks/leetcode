class Solution {
public:
    int lcs(string a, string b, int n){
        int t[n+1][n+1];

        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < n + 1; j++){
                if(i == 0 || j == 0){
                    t[i][j] = 0;
                }
            }
        }

        for(int i = 1; i <n+1; i++){
            for(int j = 1; j < n + 1; j++){
                if(a[i-1] == b[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }
            }
        }

        return n - t[n][n];
    }
    int minInsertions(string s) {
        string t = s;
        int n = s.length();
        reverse(t.begin(), t.end());

        return lcs(s, t, n);
    }
};