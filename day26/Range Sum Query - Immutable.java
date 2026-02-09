class NumArray {
    int [] prefix;

    public NumArray(int[] nums) {
        prefix = new int[nums.length +1];
        for(int i=0 ;i<nums.length;i++){
            prefix[i+1] = prefix[i] + nums[i];

        }
        
    }
    
    public int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
        
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */


/**Best soln
 * class NumArray {
     static {
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            try (FileWriter writer = new FileWriter("display_runtime.txt")) {
                writer.write("0");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }));
    }
    ArrayList<Integer> ar=new ArrayList<>();

    public NumArray(int[] nums) {
        
        for(int n: nums){
            ar.add(n);
        }

    }
    
    public int sumRange(int left, int right) {
        int sum =0; 
        while(left<=right){
            sum+=ar.get(left++);
        
        }
        return sum;        
    }
}
 */