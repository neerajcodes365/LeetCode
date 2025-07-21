class Solution {
public:
int n;
vector<int>dp;
    int help(vector<int>&days,vector<int>&cost,int index){
        if(index>=days.size()) return 0;
        // can pick 3 options;
        // return the minimum of three
        if(dp[index]!=-1)return dp[index];
        int day1=0;
        int currentdate=days[index];
        day1=cost[0]+help(days,cost,index+1);

        int day2=0;
        int end7=days[index]-1+7;
        int newidex=index;
        while(newidex < n && days[newidex] <= end7) {
            newidex++;
        }
        day2=cost[1]+help(days,cost,newidex);


        int day3=0;
        int end30=days[index]-1+30;
        int newidex30=index;
             while(newidex30 < n && days[newidex30] <= end30) {
            newidex30++;
        }
        day3=cost[2]+help(days,cost,newidex30);

        return dp[index]=min({day1,day2,day3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
    
        n=days.size();
        dp.resize(n+1,-1);
        return help(days,costs,0);
    }
};