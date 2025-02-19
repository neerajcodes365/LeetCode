class Solution {
public:
    void solve(vector<string>& result, string cur, int n) {
        if (cur.length() == n) {
            result.push_back(cur);
            return;
        } 
        for (char it = 'a'; it < 'd'; it++) {
            if (!cur.empty() && cur.back() == it) continue; // Check last character
            solve(result, cur + it, n); // Recurse with the new character
        }
    }

    string getHappyString(int n, int k) {
        vector<string> result;
        solve(result, "", n);
        if (k > result.size()) return "";
        return result[k - 1];
    }
};   