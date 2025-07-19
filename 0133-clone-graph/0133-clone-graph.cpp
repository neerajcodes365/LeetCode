/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

public:
typedef Node node;
    void help(node *n,map<node*,node*>&mp){
        // mp[]
        if(n==nullptr)return ;

        node * a=new node(n->val);
        mp[n]=a;
        for(auto ngh:n->neighbors){
            if(mp.count(ngh)==0) help(ngh,mp);
            a->neighbors.push_back(mp[ngh]);
        }

    }
    Node* cloneGraph(Node* n) {
        if(n==nullptr)return n;
        map<node*,node*>mp;//old,new
        help(n,mp);
        return mp[n];
    }
};