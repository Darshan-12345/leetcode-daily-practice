class Solution {
    public int removeDuplicates(int[] nums) {
        int i=0;
        int count =1;
        int j=1;
        int n = nums.length;
        while(j<n){
            if(nums[j] == nums[j-1]){
                j++;
                continue;
            }
            nums[i+1] = nums[j];
            i++;
            count++;
            j++;


        }
        return count;
    }
}


/**Best Soln
 * 
 * class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;

        int i = 1; 

        for (int j = 1; j < nums.length; j++) {
            if (nums[j] != nums[j - 1]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
}
 */