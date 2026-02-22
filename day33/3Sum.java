class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List <Integer>> ar = new ArrayList<>();
        int i=0;
        Arrays.sort(nums);
        for(;i<nums.length-2;i++){
            int l =i+1;
        int r=nums.length-1;
        if(i>0 && nums[i] == nums[i-1])continue;


            int sum = -nums[i];
            while(l <r){
                int s = nums[l] + nums[r];
                if(s == sum){
                     ar.add(Arrays.asList(nums[i],nums[l],nums[r]));
                     l++;
                     r--;

                
                while(l < r && nums[l] == nums[l-1]){
                    l++;
                }
                while(l<r && nums[r] == nums[r+1]){
                    r--;
                }
                }
                else if(s < sum ) l++;
                else r--;

            }
        }
          
        return ar;
    }
}