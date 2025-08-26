class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int maxarea=0;
        int longdia=0;
        int n=d.size();
        for(int i=0;i<n;i++){
            // int dia
            int a=d[i][0];
            int b=d[i][1];
            int dia=sqrt(a*a+b*b);
            if(dia>=longdia){
                int area=a*b;
                maxarea=max(maxarea,area);
                longdia=dia;
            }
        }
        return maxarea;
    }
};