class Solution {
public:

    vector<list<int>> graph;

    vector<int> topoBFS(int v){
        vector<int> ans;
        vector<int> indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto neighbour : graph[i]){
                indegree[neighbour]++;
            }
        }
        queue<int> qu;
        unordered_set<int> vis;
        for(int i=0;i<v;i++){
            if(indegree[i] == 0){
                qu.push(i);
                vis.insert(i);
            }
        }
        while(not qu.empty()){
            int node = qu.front();
            ans.push_back(node);
            qu.pop();
            for(auto neighbour: graph[node]){
                if(not vis.count(neighbour)){
                    indegree[neighbour]--;
                    if(indegree[neighbour] == 0){
                        qu.push(neighbour);
                        vis.insert(neighbour);
                    }
                }
            }
        }
        if(vis.size() == v) return ans;
        else return {};

    }
    vector<int> findOrder(int num, vector<vector<int>>& prerequisites) {
        graph.resize(num);
        for(auto ans : prerequisites){
            graph[ans[1]].push_back(ans[0]);

        }

        return topoBFS(num);


        
    }
};