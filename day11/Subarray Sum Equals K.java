import java.util.*;
class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> hs = new HashMap<>();

        hs.put(0,1);
        int sum =0;
        int count =0;
        for(int num:nums){
            sum =sum+ num;

            if(hs.containsKey(sum - k)){
                count = count + hs.get(sum-k);
            }
            hs.put(sum,hs.getOrDefault(sum,0)+1);
        }
        return count;
        
    }
}

