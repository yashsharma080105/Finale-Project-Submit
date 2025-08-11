class Solution {
public:
    int addDigits(int nums) {
        
        int sum = 0;
        

        while(nums>0){
            int rem = nums%10;
            sum += rem;
            nums /= 10;

        }
        if(sum<10) return sum;
        else
            return addDigits(sum);

    

        
    }
};