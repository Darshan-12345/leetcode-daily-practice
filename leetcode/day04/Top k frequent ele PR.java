import java.util.*;
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map <Integer, Integer> fmap = new HashMap<Integer, Integer>();
        for(int num:nums){
            fmap.put(num , fmap.getOrDefault(num, 0)+1);
        }

        List<Integer>[] con = new List[nums.length +1];

        for(int num :fmap.keySet()){
            int count = fmap.get(num);
            if(con[count] == null){
                con[count] = new ArrayList<>();
            }
            con[count].add(num);
        }

        int result[] = new int[k];

        int index=0;
        for(int i= con.length-1 ;i>=0 && index < k ;i--){
            if(con[i] != null){
                for(int num: con[i]){
                    result[index++] = num;
                    if(index == k){
                        break;
                    }
                }
            }
        }   
        return result;

    }
}

/** Best soln
 * class Solution {
      static {
    Runtime.getRuntime().addShutdownHook(new Thread(() -> {
      try (java.io.FileWriter fw = new java.io.FileWriter("display_runtime.txt")) {
        fw.write("0");
      } catch (Exception _) {
      }
    }));
  }
    public int[] topKFrequent(int[] nums, int k) {
        if(k == nums.length) return nums;

        if(nums.length == 0) return new int[] {};

        Map<Integer,Integer> map = new HashMap<>();

        // count frequency
        for(int num : nums){ 
            map.put(num,map.getOrDefault(num,0)+1);
        }   

            //PriorityQueue<Map.Entry<String,Integer>> pq = new PriorityQueue<>((a,b) -> b.getValue() - a.getValue()); // Desc order 

            Queue<Integer> pq = new PriorityQueue<>((a,b)->map.get(a)-map.get(b)); // ASC order

            for(int n : map.keySet()){
                pq.add(n);
                if(pq.size() > k){
                    pq.poll();
                }
            }
            int[] result = new int[k];
            for(int i = 0; i < k; i++){
                result[i] = pq.poll();
            }

            return result;
        
    }
}
 */