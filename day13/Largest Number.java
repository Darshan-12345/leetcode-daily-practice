class Solution {
    public String largestNumber(int[] nums) {
         String[] s = new String[nums.length];
         for(int i=0;i<nums.length ;i++){
            s[i] = String.valueOf(nums[i]);

         }
         Arrays.sort(s, (a,b)-> (b+a).compareTo(a+b));
         if(s[0].equals("0")){
            return "0";
        
         }
         StringBuilder sb =new StringBuilder();
         for(String a:s){
            sb.append(a);
         }
         return sb.toString();

        
        
    }
}

/**Best Soln
 * 
 * import java.util.*;

class Solution {
    public String largestNumber(int[] nums) {
        Integer[] arr = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            arr[i] = nums[i];
        }

        Arrays.sort(arr, (a, b) -> {
            String order1 = a + "" + b;
            String order2 = b + "" + a;
            return order2.compareTo(order1); 
        });

        StringBuilder sb = new StringBuilder();
        for (int num : arr) {
            sb.append(num);
        }

        if (sb.charAt(0) == '0') return "0";

        return sb.toString();
    }
            static {
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            try (java.io.FileWriter fw = new java.io.FileWriter("display_runtime.txt")) {
                fw.write("0");
            } catch (Exception e) {
                System.out.println("Time overwrite aborted");
            }
        }));
    }

}
 */