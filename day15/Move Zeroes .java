class Solution {
    public void moveZeroes(int[] nums) {
        int index =0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=0){
                nums[index] = nums[i];
                index++;

            }
        }
        while(index<nums.length){
            nums[index]=0;
            index++;
        }
        
    }
}

/**best soln
 * 
 * class Solution {
    public void moveZeroes(int[] n) {
      int count=0;
    
        for(int i=0;i<n.length;i++)
        {
           if(n[i]!=0)
           {
             n[count++]=n[i];
          
           }
        }
        for(int i=count;i<n.length;i++ )
        {
            n[i]=0;
        }
       System.out.println(Arrays.toString(n)); 
    }
    static {
        Runtime.getRuntime().gc();
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            try (FileWriter f = new FileWriter("display_runtime.txt")) {
                f.write("0");
            } catch (Exception e) {

            }
        }));
    }
}
 */