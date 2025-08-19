class Solution {
public:
    string oddString(vector<string>& w) {
        // map< pair<int,int>,vector<string> >hash;
        vector<int>a,b;

        string ai=w[0];
        for(int i=0;i<ai.length()-1;i++){
            a.push_back(w[0][i+1]-w[0][i]);
        }

        string bi=w[1];
        for(int i=0;i<bi.length()-1;i++){
            b.push_back(w[1][i+1]-w[1][i]);
        }
            string ans="";
            vector<int>help;
        if(a==b){
            for(int k=2;k<w.size();k++){
                help.clear();
                string dup=w[k];
                for(int i=0;i<dup.length()-1;i++){
                    help.push_back(w[k][i+1]-w[k][i]);
                }
                if(a!=help) return dup;
            }
        }else{
            string dup=w[2];
            int k=2;
            for(int i=0;i<dup.length()-1;i++){
                    help.push_back(w[k][i+1]-w[k][i]);
                }
            if(help==a) return w[1];
            else  return w[0];
        }



return "";
    }
};