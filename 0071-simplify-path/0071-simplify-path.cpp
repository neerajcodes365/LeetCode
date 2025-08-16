class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        stringstream ss(path);
        string token;
        while(getline(ss,token,'/')){
            if(token=="." || token=="") continue;
            if(token=="..") {
                if(!st.empty()) st.pop();
                }
            else st.push(token);
        }

        if(st.empty()) return "/";

       vector<string> dirs;
        while(!st.empty()){
            dirs.push_back(st.top());
            st.pop();
        }
        reverse(dirs.begin(), dirs.end());
        string ans="";
        for(auto &it:dirs){
            ans=ans+"/"+it;
        }

        return ans;
    }
};



/* class Solution {
public:
    string simplifyPath(string p) {
        string ans="";
        stack<string>st;
        int i=0;
        int n=p.size();
            string help="";

        while(i<n){
                char ch=p[i];
            if(ch=='/'){
                while(i<n&&ch=='/'){
                    i++;
                    ch=p[i];
                }
                st.push("/");
            }

            else if(ch=='.') {
                while(i<n&&ch=='.'){
                help.push_back(ch);
                i++;
                ch=p[i];
                }
                if(help.size()>2) st.push(help);
                else {
                    if( help.size()==2) st.pop();
                    else{
                        i++;
                    }
                }
                help="";
            }

            else{
                while( i<n&& ( (a<=ch && z>=ch) || (A<=ch && Z>=ch) ) ){
                    help.push_back(ch);
                    i++;
                    ch=p[i];
                }
                st.push(help);
                help="";
            }
        }
        if(st.top()=='/') st.pop();

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;


    }
}; */