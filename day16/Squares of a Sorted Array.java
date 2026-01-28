class Solution {
    public int[] sortedSquares(int[] nums) {
        // int index=0;
        // int[] sa = new int[nums.length];
        // for(int i=0;i<nums.length;i++){
        //     sa[index++] = nums[i]*nums[i];
        // }
        // Arrays.sort(sa);
        // return sa;

        int n =nums.length;
        int [] res = new int[n];

            int left =0;
            int right =n-1;
            int index =n-1;
        while(left <= right){
            int leftsq = nums[left]*nums[left];
            int rightsq =nums[right]*nums[right];
            if(leftsq>rightsq){
                res[index--] =leftsq;
                left++ ;

            }
            else {
                res[index--] = rightsq;
                right--;
            }
            }
            return res;
        
        
    }
}