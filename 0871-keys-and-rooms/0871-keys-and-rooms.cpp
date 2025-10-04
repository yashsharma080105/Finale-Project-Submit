class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(0);
        visited.insert(0);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto neighbour : rooms[curr]){
                if(not visited.count(neighbour)){
                    visited.insert(neighbour);
                    q.push(neighbour);
                }
            }
        }
        return visited.size() == rooms.size();
        

        
    }
};