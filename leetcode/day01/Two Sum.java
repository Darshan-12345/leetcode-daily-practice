import java.util.HashMap;
import java.util.Map;
class Solution {
    public int[] twoSum(int[] nums, int target) {
        // int sum =0;
        // int [] c = new int[2];
        // int index=0;
        // for(int i=0; i<nums.length-1;i++){
        //     for(int j=i+1;j<nums.length;j++){
        //         sum = nums[i]+nums[j];
        //         if(sum == target){
        //             c[index] = i;
        //             index++;
        //             c[index] =j;
        //             break;
        //         }
        //     }
            
        // } return c;

        Map<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<nums.length;i++){
            int c =0;
            c = target - nums[i];
            if(map.containsKey(c)){
                return new int[]{map.get(c),i};
            }
            map.put(nums[i],i);
        }
        return new int[]{};
    } 
}