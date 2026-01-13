class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()){
            return false;
        }
        char[] s1 = s.toCharArray();
        char[] t1 = t.toCharArray();

        Arrays.sort(s1);
        Arrays.sort(t1);

        return Arrays.equals(s1,t1);
    }
}


/*  best soln
class Solution {
    public boolean isAnagram(String s, String t) {
        char[] c1 = s.toCharArray();
		char[] c2 = t.toCharArray();
		Arrays.sort(c1);
		Arrays.sort(c2);
		StringBuilder sb1 = new StringBuilder();
		StringBuilder sb2 = new StringBuilder();
		for(char c : c1){
		    sb1.append(c);
		}
		for(char c : c2){
		    sb2.append(c);
		}
		if(sb1.toString().equals(sb2.toString())){
		    return true;
		}
        return false;
    }
    static{
    Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            try (java.io.FileWriter fw = new java.io.FileWriter("display_runtime.txt")) {
                fw.write("0");
            } catch (Exception e) {
            }
        }));
    }
} */