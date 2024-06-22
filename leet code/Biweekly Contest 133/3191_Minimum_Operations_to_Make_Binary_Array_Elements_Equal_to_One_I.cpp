// 3191. Minimum Operations to Make Binary Array Elements Equal to One I

class Solution {
public:
    bool checkAllOne(vector<int>&v,int j)
    {
        bool check = true;
        for(int i = j+1; i < v.size(); i++)
        {
            if(v[i] == 0)
            {
                check = false;
                break;
            }
        }
        return check;
    }
    int minOperations(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size()-2; i++)
        {
            if(nums[i] == 0)
            {
                count++;
                int j = i;
                nums[i] = !(nums[i]);
                nums[i+1] = !(nums[i+1]);
                nums[i+2] = !(nums[i+2]);
            }
            if(checkAllOne(nums,i))
            {
                return count;
            }
        }
        return -1;
    }
};