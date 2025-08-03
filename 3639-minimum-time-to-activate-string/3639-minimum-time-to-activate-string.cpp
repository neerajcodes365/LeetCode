class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n=s.size();
        vector<long long >totallength(n,0);
        int orsize=order.size();
        long long totaltillnow=0;
        long long left,right;
        set<int>starindex;
        starindex.insert(-1);
        starindex.insert(n);
        for(int i=0;i<orsize;i++){

                int num=order[i];

                auto it=starindex.lower_bound(num);
                it--;
                left=num - *it;
                auto iit=starindex.upper_bound(num);
                right=*iit - num;
                totaltillnow+=left*right;
                starindex.insert(num);
            if(totaltillnow>=k) return i;
        }
        return -1;
    }
};