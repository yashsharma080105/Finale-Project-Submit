class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        return parent[x] = (parent[x] == x) ? x: find(parent[x]);
    }

    void Union(int a,int b){
        a = find(a);
        b = find(b);
        if(a==b) return;
        if(rank[a]>rank[b]){
            rank[a]++;
            parent[b] =a;
  
        }
        else{
            rank[b]++;
            parent[a] = b;
        }
    }





    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        //  step 2 making componet
        for(auto&vec : edges){
            int u = vec[0];
            int v = vec[1];

            Union(u,v);
        }
        // step 3 maping for parent and size of component
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int papa = find(i);   // parent represent
            mp[papa]++;
        }

        // find result from map
        long long result = 0;
        long long remaining = n;
        for(auto& it : mp){
            long long size = it.second;
            result += (size)*(remaining-size);
            remaining -= size;
        } 
        return result;

        
    }
};