class Solution {
public:
    bool dfs(unordered_set<int>& path,int course,int s,vector<vector<int>>& p){
        if(path.find(course)!=path.end())return false;
        path.insert(course);
        for(int i=0;i<s;i++){
            if(p[i][0]==course) if(!dfs(path,p[i][1],s,p)) return false;
        }
        path.erase(course);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> path;
        if(prerequisites.size()==0)return true;
        for(int i=0;i<numCourses;i++){
            if (!(dfs(path,i,prerequisites.size(),prerequisites))) return false;
        }
        return true;
    }
};
