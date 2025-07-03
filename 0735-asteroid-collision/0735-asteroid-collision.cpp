class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ass) {
        int n=ass.size();
        stack<int>st;

        for(int i=0;i<n;i++){
            int num=ass[i];
            if(num>0){
                st.push(num);
            }else{

                bool exploded=false;
                
                while(!st.empty()&&st.top()>0){
                    if(st.top()<-num){
                        st.pop();
                        continue;
                    }else if(st.top()==-num){
                        st.pop();
                        exploded=true;
                        break;
                    }else{
                        exploded=true;
                        break;
                    }
                }

                if(!exploded&&(st.empty()||st.top()<0)){
                    st.push(num);
                }

            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
