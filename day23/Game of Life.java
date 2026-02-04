class Solution {
    public void gameOfLife(int[][] board) {
        int m = board.length;
        int n = board[0].length;

        int[][] dir = {{-1,-1}, {-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

        for(int i= 0;i<m ;i++){
            for(int j=0; j<n ;j++){
                int liveneighbor =0;

                for(int[] d : dir){
                    int r = i+d[0];
                    int c = j+d[1];

                    if(r>=0 && r<m && c>=0 && c<n){
                        if(board[r][c] ==1 || board[r][c] == -1){
                            liveneighbor++;
                        }
                    }
                }
                if(board[i][j] == 1 ){
                    if(liveneighbor <2 || liveneighbor>3)
                    board[i][j]=-1;
                }
            
            else{
                if(liveneighbor ==3){
                    board[i][j] = 2;
                }
            }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
                if(board[i][j] == -1) board[i][j] =0;
                if(board[i][j] == 2) board[i][j] =1;

            }
        }
        
    }
}