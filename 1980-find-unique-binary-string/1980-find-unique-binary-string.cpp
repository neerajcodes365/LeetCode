class Solution {
public:
    void solve(const unordered_set<string>& numSet, int len, string& cur, string& result, bool& found) {
        if (cur.length() == len) {
            if (numSet.find(cur) == numSet.end()) {
                result = cur;
                found = true;
            }
            return;
        }
        
        for (char ch = '0'; ch <= '1'; ch++) {
            if (found) return; 
            cur.push_back(ch);
            solve(numSet, len, cur, result, found);
            cur.pop_back();
        }
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> numSet(nums.begin(), nums.end()); 
        int len = nums.size();
        string cur = "", result = "";
        bool found = false;
        
        solve(numSet, len, cur, result, found);
        return result;
    }
};
