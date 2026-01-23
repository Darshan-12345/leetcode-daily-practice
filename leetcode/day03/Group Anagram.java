import java.util.*;
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();

        for(String words : strs){
        char[] chars = words.toCharArray();
        Arrays.sort(chars);
        String key = new String(chars);
        if(!map.containsKey(key)){
            map.put(key, new ArrayList<>());
        }
        map.get(key).add(words);
        }
        return new ArrayList<>(map.values());
    }
}

/* best Solution

class Solution {
    static {
    Runtime.getRuntime().addShutdownHook(new Thread(() -> {
        try (java.io.FileWriter writer = new java.io.FileWriter("display_runtime.txt")) {
            writer.write("0");
        } catch (java.io.IOException e) {
        
        }
    }));
}

    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();

        for (String word: strs) {
            char[] ch = word.toCharArray();
            Arrays.sort(ch);
            String key = new String(ch);
            if (map.containsKey(key)) {
                map.get(key).add(word);
            } else {
                List<String> list = new ArrayList<>();
                list.add(word);
                map.put(key, list);
            }
        }
        List<List<String>> finalList = new ArrayList<>(map.values());
        return finalList;
    }
} */