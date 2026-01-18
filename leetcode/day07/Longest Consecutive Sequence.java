class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for(int num:nums){
            set.add(num);
        }

        int longest =0;

        for(int num :set){
            if(!set.contains(num-1) ){
                int currentnum= num;
                int count =1;
                while(set.contains(currentnum +1 )){
                    currentnum++;
                    count++;

                }
longest = Math.max(longest,count);
            }
        }
        return longest;
    }
}

/**Best Soln
 * class Solution {
    public int longestConsecutive(int[] nums) {
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            try (FileWriter writer = new FileWriter("display_runtime.txt")) {
                writer.write("0");
            } catch (IOException e) {
                System.err.println(e.getMessage());
            }
        }));
        
        int res = 0, rep = 0;
        if (nums.length == 0) {
            return 0;
        }
        TreeSet<Integer> set = new TreeSet<>();
        for (int num : nums) {
            set.add(num);
        }
        int j=0;
        for (Integer num : set) {
            nums[j++] = num;
        }

        for (int i=1 ; i < nums.length ; i++) {
            if (nums[i-1] == nums[i]-1) {
                rep++;
                if (res < rep) {
                    res = rep;
                }
            }
            else {
                rep = 0;
            }
        }
        return res+1;
    }
}
 */