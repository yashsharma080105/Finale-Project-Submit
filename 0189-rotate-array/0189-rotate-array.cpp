class Solution {
public:
    void reversePart(int x,int y, vector<int>& v){
        while(x<=y){
            int temp = v[x];
            v[x] = v[y];
            v[y] = temp;
            x++;
            y--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n){
            k = k%n;
        }
        reversePart(0,n-k-1,nums);
        reversePart(n-k,n-1,nums);
        reversePart(0,n-1,nums);

        
    }
};