class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        
        unordered_map<int, set<int>> xaxis, yaxis;
        for(int i = 0; i < buildings.size(); i++) {
            int x = buildings[i][0];
            int y = buildings[i][1];
            xaxis[x].insert(y);
            yaxis[y].insert(x);
        }
        
        int ans = 0;
        for(int i = 0; i < buildings.size(); i++) {
            int x = buildings[i][0];
            int y = buildings[i][1];
            
            auto &s1 = xaxis[x];
            auto &s2 = yaxis[y];
            
            auto it_above = s1.lower_bound(y);
            bool hasAbove = (it_above != s1.begin());
            bool hasBelow = (++it_above != s1.end());
            
            auto it_left = s2.lower_bound(x);
            bool hasLeft = (it_left != s2.begin());
            bool hasRight = (++it_left != s2.end());
            
            if(hasAbove && hasBelow && hasLeft && hasRight) {
                ans++;
            }
        }
        return ans;
    }
};