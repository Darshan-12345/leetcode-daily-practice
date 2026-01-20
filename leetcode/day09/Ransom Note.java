class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int [] count = new int[26];

        for(char c : magazine.toCharArray()){
            count[c -'a']++;
        }
        for (char c: ransomNote.toCharArray()){
            if(count[c - 'a'] ==0){
                return false;
            }
            count[c-'a']--;
        } 
        return true;

    }
}

/**Best soln
 * class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {

        Map<Character, Integer> map = new HashMap<>();

        // Count letters in magazine
        for (char c : magazine.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        // Use letters for ransomNote
        for (char c : ransomNote.toCharArray()) {
            if (!map.containsKey(c) || map.get(c) == 0) {
                return false;
            }
            map.put(c, map.get(c) - 1);
        }

        return true;
    }
     static {
        Runtime.getRuntime().gc();
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            try (FileWriter f = new FileWriter("display_runtime.txt")) {
                f.write("0");
            } catch (Exception e) {

            }
        }));
    }
}
 */