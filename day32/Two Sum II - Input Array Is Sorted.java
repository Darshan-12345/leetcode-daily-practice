class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] ans = new int[2];

        int l  = 0;
        int r = numbers.length - 1;
        
        while(l < r){
            int s = numbers[l]+ numbers[r];
        
            if(s == target){
                return new int[]{l+1,r+1};

            }
            else if(s < target){
                l++;
            }
            else if(s > target){
                r--;
            }
        }
        
        return new int[0];
        
    }
}