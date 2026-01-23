class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        if(s.length()<p.length()){
            return res;
        }
        int [] pcount = new int[26];
        int [] scount = new int[26];

        for(char c:p.toCharArray()){
            pcount[c -'a']++;
        }
        int windowsize = p.length();
        for(int i=0;i<s.length();i++){
            scount[s.charAt(i) -'a']++;

            if(i >= windowsize){
                scount[s.charAt(i- windowsize)-'a']--;
            }

            if(Arrays.equals(pcount,scount)){
                res.add(i- windowsize +1);
            }
        }
        return res;
    
    }
}