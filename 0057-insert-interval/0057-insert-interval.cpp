class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newi) {

        vector<vector<int>>ans;
        int n=intervals.size();
        int first=newi[0];
        int second=newi[1];
        int i=0;
        while(i<n && intervals[i][1]<first){
            ans.push_back(intervals[i]);
            i++;
        }
            int n1=first;
            int n2=second;

        while(i<n&& n2>=intervals[i][0]){
             n1=min(n1,intervals[i][0]);
             n2=max(n2,intervals[i][1]);
            i++;
        }
            ans.push_back({n1,n2});
            while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};