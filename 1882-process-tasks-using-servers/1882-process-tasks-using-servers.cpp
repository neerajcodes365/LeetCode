class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        >available;

        priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
        >notavailable;

 int n = servers.size();
        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }
        vector<int>ans;
// int t=0;
        for(int i=0;i<tasks.size();i++){

            while(!notavailable.empty()){
                auto [endtime,weight,index]=notavailable.top();
                if(endtime<=i){
                    available.push({weight,index});
                    notavailable.pop();
                }else{
                    break;
                }
            }

            if(available.empty()){
                auto [endtime,weight,index]=notavailable.top();
                ans.push_back(index);
                notavailable.pop();
                notavailable.push({endtime + tasks[i],weight,index});
            }else{
                auto [wt,inx]=available.top();
                ans.push_back(inx);
                notavailable.push({i+tasks[i],wt,inx});
                available.pop();
            }
        }

        return ans;
    }
};