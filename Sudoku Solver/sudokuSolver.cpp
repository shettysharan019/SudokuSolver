#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size of the grid will be NxN  
#define N 9  

class Solution 
{
    public:

    bool isSafe(int grid[N][N], int row, int col, int number) {
        //column
        for(int i=0; i<N; i++) {
            if(grid[i][col] == number) {
               return false;
            }
        }
      
        //row
        for(int j=0; j<N; j++) {
            if(grid[row][j] == number) {
               return false;
            }
        }
      
        //grid
        // to get the position of the first element in that grid
        int sr = (row/3)*3; 
        int sc = (col/3)*3;
      
        for(int i=sr; i<sr+3; i++) {
            for(int j=sc; j<sc+3; j++) {
                if(grid[i][j] == number) {
                   return false;
                }
            }
        }
        return true;
    }   
    // travel the grid using recurssion
    bool helper(int grid[N][N], int row, int col) 
    {
        if(row == N) {
           return true;
        }
      
        int nrow = 0;
        int ncol = 0;
      
        if(col == N-1) 
        {
           nrow = row + 1;
           ncol = 0;
        } 
        else 
        {
           nrow = row;
           ncol = col + 1;
        }
      
        if(grid[row][col] != 0) 
        {
            if(helper(grid, nrow, ncol)) {
               return true;
            }
        } 
        else 
        {
            for(int i=1; i<=9; i++) {
                if(isSafe(grid, row, col, i)) {
                    grid[row][col] = i;
                    if(helper(grid, nrow, ncol))
                       return true;
                    else
                        grid[row][col] = 0;
                }
            }
        }       
        return false;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        helper(grid, 0, 0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        cout << endl;
        cout << "The Solution is : " << endl;
        for(int i=0;i<9;i++)
        {
            cout << endl;
            for(int j=0;j<9;j++)
		        cout << grid[i][j] << " ";
        }
    }
};

// main function 
int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin >> grid[i][j];
		        
		Solution ob;
		
		if(ob.SolveSudoku(grid) == true)  
            		ob.printGrid(grid);  
        	else
            		cout << "No solution exists";  
        
        	cout << endl;
	}
	return 0;
}
