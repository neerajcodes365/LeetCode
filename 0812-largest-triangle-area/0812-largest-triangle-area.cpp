class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        double maxi=0;
        int n=p.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int x1=p[i][0],y1=p[i][1];
                    int x2=p[j][0],y2=p[j][1];
                    int x3=p[k][0],y3=p[k][1];
                    double area = 0.5 * abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
                    maxi=max(area,maxi);
                }
            }
        }
        return maxi;
    }
};