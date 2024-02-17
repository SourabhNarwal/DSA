class Solution {
public:
    int search(vector<int>& nums, int target) {
     
        int size=nums.size();
     
        if(target<nums[0]&&target>nums[size-1])
            return -1;
        if(target==nums[0])
            return 0;
        if(target==nums[size-1])
            return size-1;
        
        int start=0;
        int end=size-1;
        int mid;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            
            if(target==nums[mid])
            { return mid;}
            
            if(target<nums[mid])
            {  
                 if(nums[mid]>=nums[0])
                 {
                     if(target>nums[0])
                         end=mid-1;
                     else
                         start=mid+1;
                 }
                 else
                     end=mid-1;
             
               
          }
            else
            {
              if(nums[start]<=target&&target<=nums[end])
                  start=mid+1;
              else if(nums[start]<=target&&target>nums[end])
                      end=end-1;
              else
                  start=mid+1;
               
            }
        }
        return -1;
    }
};