class Solution {
public:
    int find(vector<int>& p,int n){
        if(n==p[n]) return n;
        p[n]=find(p,p[n]);
        return p[n];
    }
    bool uni(vector<int>& p,vector<int>& r,int n1,int n2){
        int p1=find(p,n1);
        int p2=find(p,n2);
        if(p1==p2) return false;
        if(r[p1]>r[p2]) {
            p[p2]=p1;
            r[p1]+=r[p2];
        }
        else{
            p[p1]=p2;
            r[p2]+=r[p1];
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> par(n+1,0);
        vector<int> rank(n+1,1);
        for(int i=1;i<n+1;i++){
            par[i]=i;
        }
        for(auto x:edges){
            if(!uni(par,rank,x[0],x[1])) return x;
        }
        return {};
    }
};
