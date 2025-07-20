class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi> pq;  //max heap (max size is k)
        for(int i=0;i<arr.size();i++){
            int ele = arr[i];
            int distance = abs(x-ele);
            pi p = {distance,ele};
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()>0){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;


    }
};