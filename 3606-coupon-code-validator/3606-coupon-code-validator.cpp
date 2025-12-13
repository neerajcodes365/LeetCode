class Solution {
public:
    bool checkcode(string &s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!(isalnum(c) || c == '_'))
                return false;
        }
        return true;
    }

    bool checkbus(string &s) {
        return (s == "electronics" ||
                s == "grocery" ||
                s == "pharmacy" ||
                s == "restaurant");
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& busi, vector<bool>& isActive) {

        vector<pair<string,string>>helpforsort;
        int n=code.size();
        for(int i=0;i<n;i++){
            if( checkcode(code[i]) && checkbus(busi[i]) && isActive[i]){
                helpforsort.push_back({busi[i],code[i]});
            }
        }
        sort(helpforsort.begin(),helpforsort.end());
        vector<string>ans;
        for(int i=0;i<helpforsort.size();i++){
            string b=helpforsort[i].second;
            ans.push_back(b);
        }
        return ans;
    }
};