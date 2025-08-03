class Solution {
public:
    int rev(int n){
        int r =0;
        while(n>0){
            r = r*10;
            r = r+(n%10);
            n /= 10;
        }
        return r;
    }
   
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            nums[i] -= rev(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(m.find(nums[i])!=m.end()){  //exist
                count = count%1000000007;
                count += m[nums[i]];   //add existing frequency in count
                m[nums[i]]++;  
            }
            else m[nums[i]]++;
        }
        return count%1000000007;;
    }
};