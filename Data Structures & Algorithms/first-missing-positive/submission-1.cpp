class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool flag=false;
        for(auto it : nums)
        if(it==1)
        flag=true;
        if(!flag)
        return 1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0)
            nums[i]=1;
            else if(nums[i]>n)
            nums[i]=1;
        }
        for(int i=0;i<nums.size();i++){
            int k=abs(nums[i]);
            if(nums[k-1]>0){
                nums[k-1]=-1*abs(nums[k-1]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
            return i+1;
        }

        return n+1;
    }
};