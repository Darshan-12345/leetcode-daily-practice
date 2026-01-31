class Solution {
    public int firstMissingPositive(int[] nums) {
        int n= nums.length;
        for(int i=0; i<n ;i++){
            while(
                nums[i] >0  &&
                nums[i] < n &&
                nums[nums[i]-1]!=nums[i]
            ){
                int correctIndex= nums[i]-1;
                int temp =nums[i];

                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return n+1;
        
    }
}
/**Best Soln
 * 
 * class Solution {
    public int firstMissingPositive(int[] nums) {
         int n = nums.length;
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
        
    }

    static {
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            try (FileWriter writer = new FileWriter("display_runtime.txt")) {
                writer.write("0");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }));
    }

}
 * 
 */