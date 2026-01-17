class Solution {
    public boolean isValidSudoku(char[][] board) {
        HashSet<String> seen = new HashSet<>();

        for(int row =0; row<9;row++){
            for(int col =0 ;col<9 ;col++ ){
                char current = board[row][col];
                if(current == '.'){
                    continue;
                }
                String rowkey = current +" in row " + row;
                String colkey = current +" in col " + col;
                String boxkey = current + "in box " + (row/3) + "-"+(col/3);

                if(!seen.add(rowkey) || !seen.add(colkey) || !seen.add(boxkey)){
                    return false;
                }
            }

        }
        return true;
    }
}
/**Best Solution 
 * class Solution {
    static {
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            try (java.io.FileWriter fw = new java.io.FileWriter("display_runtime.txt")) {
                fw.write("0");
            } catch (Exception e) {
            }
        }));
    }
    public boolean isValidSudoku(char[][] board) {
        int row[] = new int[9];
        int col[] = new int[9];
        int box[] = new int[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c = board[i][j];
                if(c != '.'){
                    int bit = 1 << (c - '0');
                    int boxN = (i / 3) * 3 + (j / 3);
                    if((row[i] & bit) != 0 || (col[j] & bit) != 0 || (box[boxN] & bit) !=0)return false;
                    row[i] |= bit;
                    col[j] |=bit;
                    box[boxN] |= bit;
                }
                
            }
        }
        System.gc();
        return true;
    }
}

 */