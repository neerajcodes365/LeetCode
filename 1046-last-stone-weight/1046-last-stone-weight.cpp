class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        // priority_queue<
        // int,
        // vector<int>,
        // greater<int>
        // >pq;
        priority_queue<int>pq;
        pq.push(0);
        for(auto it:s){
            pq.push(it);
        }
        // if(pq.size()==2){

        // }
        while(pq.size()!=1){
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            // cout<<x<<" "<<y;
            if(x!=y){
                pq.push(y-x);
                // cout<<"pushing"<<y-x;
            }
            // cout<<" "<<endl;
        }
        return pq.top();
    }
};