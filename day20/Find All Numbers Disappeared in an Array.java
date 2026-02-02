class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
      
        ArrayList<Integer> ar = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            int index = Math.abs(nums[i])-1;
            if(nums[index]>0){
                nums[index]=-nums[index];
            }

        }
        for(int i=0;i<nums.length;i++){
            if(nums[i]>0){
                ar.add(i+1);
            }
        }
        return ar;
        
    }
}

/**Best Soln
 * 
 * class Solution {
      static {
        Runtime.getRuntime().gc();
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            try (FileWriter writer = new FileWriter("display_runtime.txt")) {
                writer.write("0");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }));
    }
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new ArrayList<>();

        for(int i=0; i<nums.length; i++){
            int idx = Math.abs(nums[i])-1;
            if(nums[idx] > 0){
                nums[idx] = -nums[idx];
            }
        }
        for(int i=0; i<nums.length; i++){
            if(nums[i]>0){
                list.add(i+1);
            }
        }
        return list;
    }
}
 */