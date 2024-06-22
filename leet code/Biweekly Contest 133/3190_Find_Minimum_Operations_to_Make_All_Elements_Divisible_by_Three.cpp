// 3190. Find Minimum Operations to Make All Elements Divisible by Three
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int numOfOp = 0;
        
        for( int i = 0; i < nums.size(); ++i)
        {
            if( nums[i]%3 == 0 )
            {
                continue;
            }
            else if( (nums[i]-1)%3 == 0)
            {
                numOfOp++;
            }
            else if( (nums[i]+1)%3 == 0)
            {
                numOfOp++;
            }
        }
        return numOfOp;
    }
};