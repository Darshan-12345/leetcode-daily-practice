class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
int n = nums.length;
int asume = nums[0]+nums[1]+nums[2];
        for(int i =0;i<n-2;i++){
        
        if(i>0 && nums[i] == nums[i-1]) continue;
        int l =i+1;
        int r= n-1;
        while(l<r){
            int sum = nums[i]+nums[l]+nums[r];
            if(Math.abs(sum-target) < Math.abs(asume-target)){
                asume = sum; 
                
            }
            if(sum < target){
                l++;
            }
            else if( sum > target){
                r--;
            }
            else return sum;
        }

        }
return asume;
        
    }
}