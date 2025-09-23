class Router {
public:
    int maxsize;
    deque<tuple<int,int,int>>q;//s,d,t
    set<tuple<int,int,int>>s;
    map<int,vector<int>>get;///destination, timestamps um 

    Router(int memoryLimit) {
       this->maxsize=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        
        tuple<int,int,int> a={source,destination,timestamp};
        if(s.count(a)) return false;        
        if(q.size()==maxsize) {
            s.erase(q.front());
            auto [aa,bb,cc]=q.front();
            q.pop_front();
            auto it = find(get[bb].begin(), get[bb].end(), cc); 
                if (it != get[bb].end()) {
                    get[bb].erase(it);  
                }
            }
        
        s.insert(a);
        get[destination].push_back(timestamp);
        q.push_back(a);
        return true;

    }
    
    vector<int> forwardPacket() {
        vector<int>ans;
        if(q.size()==0)return ans;

       auto [a,b,c]=q.front();
            s.erase(q.front());
       q.pop_front();
        // get[b].erase(get[b].begin());
        auto it = find(get[b].begin(), get[b].end(), c); 
    if (it != get[b].end()) {
        get[b].erase(it);  
    }
        

       ans.push_back(a);
       ans.push_back(b);
       ans.push_back(c);
       return ans;
    }
    
    int getCount(int destination, int startTime, int endTime) {

        int count =0;
        auto itl=lower_bound(get[destination].begin(),get[destination].end(),startTime);
        auto itr=upper_bound(get[destination].begin(),get[destination].end(),endTime);


        count=(itr-itl);

return count;

    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */