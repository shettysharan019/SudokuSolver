*Working of Sudoku Solver*

1) We start with the first empty cell
2) We check if a value is present in the cell or not 
3) We generate a list of possible valid values that can be filled in that cell if the cell is empty
4) We iterate over this list and start with the first value. This value is placed in the required cell.
5) We move on to the next cell. We again generate a list of possibilities. However, if no list can be generated, then this means that there is something wrong with the value of the previous cell. We then move back to the previous cell and place the next value on the generated list in the cell now. We repeat this step until the current cell has a valid value placed inside it.
6) We stop when we reach the 81st cell (the last cell in a Sudoku puzzle) and have placed a valid value.
7) The puzzle has now been solved.
