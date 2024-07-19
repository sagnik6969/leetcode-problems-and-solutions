class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> rowMin = new ArrayList<Integer>();

        
        for(int i = 0 ; i < matrix.length ; i++){
        int mn = Integer.MAX_VALUE;

        for(int j = 0 ; j < matrix[i].length ; j++){
            mn = Math.min(mn,matrix[i][j]);
        }

        rowMin.add(mn);
        }

        List<Integer> colMax = new ArrayList<Integer>();

        for(int j = 0 ; j < matrix[0].length ; j++){
        int mx = Integer.MIN_VALUE;
        
        for(int i = 0 ; i < matrix.length ; i++){

            mx = Math.max(mx,matrix[i][j]);

        }

        colMax.add(mx);
        }

        List<Integer> ans = new ArrayList<>();

        for(int i = 0 ; i < matrix.length ; i++){
          for(int j = 0 ; j < matrix[i].length ; j++){
            if(matrix[i][j] == rowMin.get(i) && matrix[i][j] == colMax.get(j))
            ans.add(matrix[i][j]);
          }

       
        }
        
       // System.out.println(rowMin);
       // System.out.println(colMax);
        return ans;
    }
}