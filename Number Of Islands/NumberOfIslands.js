function getNumberOfIslands(binaryMatrix) {
  // instantiate return variable
  let islandCount = 0;
  
  // iterate through the rows & columns
  for (let row = 0 ; row < binaryMatrix.length ; row++) {
    for (let col = 0 ; col < binaryMatrix[0].length ; col++) {
      
      const currentCell = binaryMatrix[row][col];
    
      // when we encounter a cell that represents land
      if (currentCell === 1) {
        // increment out island count
        islandCount++;
        // and then do a traversal using that cell as the root node
        depthFirstTraversal(binaryMatrix, row, col)
        // and mark all of the contiguous land as part of that same island
      }
    }
  }
  
  return islandCount;
}


const depthFirstTraversal = (grid, row, col) => {
  if (
    row < 0 ||
    row >= grid.length ||
    col < 0 ||
    col >= grid[0].length ||
    grid[row][col] === 0 ||
    grid[row][col] === "#"
  ) return;
  
  // mark the current cell as visited
  grid[row][col] = "#"
  
  // and continue the traversal through all of the neighbors
  depthFirstTraversal(grid, row - 1, col);
  depthFirstTraversal(grid, row + 1, col);
  depthFirstTraversal(grid, row, col - 1);
  depthFirstTraversal(grid, row, col + 1);
}






// 5x5, 5x4

/*
input:  binaryMatrix = [ [0,    #,    0,    1,    0],
                         [0,    0,    1,    1,    1],
                         [1,    0,    0,    1,    0],
                         [0,    1,    1,    0,    0],
                         [1,    0,    1,    0,    1] ]

output: 6 # since this is the number of islands in binaryMatrix.
          # See all 6 islands color-coded below.
*/

