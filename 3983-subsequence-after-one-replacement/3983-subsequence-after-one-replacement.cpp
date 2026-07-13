class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int m = s.size(), n = t.size();

        vector<int> pre(m, -1), suf(m, -1);

        int j = 0;
        for (int i = 0; i < m; i++) {
            while (j < n && t[j] != s[i]) j++;
            if (j == n) break;
            pre[i] = j;
            j++;
        }

        if (m == 0 || pre[m - 1] != -1) return true;

        j = n - 1;
        for (int i = m - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i]) j--;
            if (j < 0) break;
            suf[i] = j;
            j--;
        }

        for (int i = 0; i < m; i++) {
            if (i > 0 && pre[i - 1] == -1) continue;
            if (i + 1 < m && suf[i + 1] == -1) continue;

            int L = (i == 0 ? -1 : pre[i - 1]);
            int R = (i == m - 1 ? n : suf[i + 1]);

            if (L + 1 < R) return true;
        }

        return false;
    }
};