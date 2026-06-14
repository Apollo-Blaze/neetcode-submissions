class Solution {
public:
    vector<vector<int>> graph;
    vector<int> state;  
    
    bool hasCycle(int course){
        if(state[course] == 1) return true;   
        if(state[course] == 2) return false;  
        
        state[course] = 1;  
        for(int prereq : graph[course]){
            if(hasCycle(prereq)) return true;
        }
        state[course] = 2; 
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses, vector<int>());
        state.assign(numCourses, 0);
        
        for(auto& p : prerequisites)
            graph[p[0]].push_back(p[1]);
        
        for(int i = 0; i < numCourses; i++){
            if(state[i] == 0 && hasCycle(i))
                return false;
        }
        return true;
    }
};