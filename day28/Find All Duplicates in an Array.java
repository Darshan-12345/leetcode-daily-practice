class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for (int i=0 ; i<nums.length ;i++){
            int val  = Math.abs(nums[i]);
            int index = val -1 ;
            
            if(nums[index] < 0){
                list.add(val);
            }
            else{
                nums[index] = -nums[index];
            }

        }
return list;

    }
}

/** Best Soln
 * 
 * class Solution {
    static {
        Runtime.getRuntime().gc();
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            try (FileWriter f = new FileWriter("display_runtime.txt")) {
                f.write("0");
            } catch (Exception e) {

            }
        }));
    }
    public List<Integer> findDuplicates(int[] nums) {
        int i;
        List<Integer> s=new ArrayList<>();
        Arrays.sort(nums);
        for(i=0;i<nums.length-1;i++){
            if(nums[i]==nums[i+1])
            s.add(nums[i]);
        }
        return s;
    }
}
 */