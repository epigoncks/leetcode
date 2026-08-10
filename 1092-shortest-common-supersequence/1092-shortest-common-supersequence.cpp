class Solution {
public:
    string scs(string a, string b, int n, int m) {
        int t[n + 1][m + 1];

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0) {
                    t[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (a[i - 1] == b[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        string ans;
        int i = n;
        int j = m;
        while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1]) {
                ans.push_back(a[i - 1]);
                i--;
                j--;
            } else {
                if (t[i - 1][j] > t[i][j - 1]) {
                    ans.push_back(a[i - 1]);
                    i--;
                } else {
                    ans.push_back(b[j - 1]);
                    j--;
                }
            }
        }
        while (i > 0) {
            ans.push_back(a[i - 1]);
            i--;
        }

        while (j > 0) {
            ans.push_back(b[j - 1]);
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        return scs(str1, str2, n, m);
    }
};