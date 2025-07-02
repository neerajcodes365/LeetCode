class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n=height.size();
        vector<int>front(n),back(n);
        int mini=INT_MAX;
        int index=0;
      
      /* this is wrong caz am making the smallest min till that index but we actually want the next small one from both side ,for this we use monotonic stack */ 
      
        // for(int i=0;i<n;i++){  
            
        //     // mini=min(mini,height[i]);
        //     if(height[i]<mini){
        //         index=i;
        //         mini=height[i];
        //     }
        //     back[i]=index;
        // }
        // mini=INT_MAX;
        // index=n-1;
        // for(int i=n-1;i>=0;i--){
        //    if(height[i]<mini){
        //         index=i;
        //         mini=height[i];
        //     }
        //     back[i]=index;
        // }
        // ft.push(height[0]);
        // backi.push(height[n-1]);



        stack<int>backi;
        for(int i=0;i<n;i++){
            while(!backi.empty() && height[backi.top()]>=height[i]){
                backi.pop();
            }
            if(backi.empty()){
                // back.push_back(-1);
                back[i]=-1;
            }else{
                int num=backi.top();
                // back.push_back(num);
                back[i]=num;
            }
            backi.push(i);
            
        }

        while(!backi.empty()) backi.pop();

        for(int i=n-1;i>=0;i--){
            while(!backi.empty() && height[backi.top()]>=height[i]){
                backi.pop();
            }
            if(backi.empty()){
                // front.push_back(-1);
                front[i]=n;//no one shorter than the element ,so for calculation
            }else{
                int num=backi.top();
                // front.push_back(num);
                front[i]=num;
            }
            backi.push(i);
        }

int ans=0;
    for(int i=0;i<n;i++){
        int area=height[i]*(front[i]-back[i]-1);
        ans=max(ans,area);
    }
return ans;
    }
};