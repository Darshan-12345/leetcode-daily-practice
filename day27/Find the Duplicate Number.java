class Solution {
    public int findDuplicate(int[] nums) {
        int right =nums[0];
        int left =nums[0];
        do{
            left = nums[left];
            right = nums[nums[right]];
        }while(left != right);

        left = nums[0];

        while(left != right){
            left = nums[left];
            right = nums[right];

        }
        return right;
    }
}

/**Best soln 
 * 
 * class Solution {
    public int findDuplicate(int[] nums) {
        Set<Integer> st = new HashSet<>();
        for(int i=0;i<nums.length;i++){
            if(st.contains(nums[i])) return nums[i];
            else st.add(nums[i]);
        }
        return -1;
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
 */