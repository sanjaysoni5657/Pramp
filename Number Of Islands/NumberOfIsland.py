"""
Each traversal: BFS, DFS
matrix to marked the cell is visited
  
binaryMatrix: n rows, m columns
Time complexity: O(n*m)
Space complexity: O(n*m)

"""
from collections import deque

def get_number_of_islands(binaryMatrix):
  directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
  n_islands = 0
  n_rows = len(binaryMatrix)
  n_columns = len(binaryMatrix[0])
  for x in range(n_rows):
    for y in range(n_columns):
      if binaryMatrix[x][y] == 1:
        n_islands += 1
        queue = deque([(x, y)])
        binaryMatrix[x][y] = 0
        while queue:
          top_x, top_y = queue.popleft()
          for d_x, d_y in directions:
            if 0 <= top_x + d_x < n_rows and 0 <= top_y + d_y < n_columns \
            and binaryMatrix[top_x + d_x][top_y + d_y] == 1:
              queue.append((top_x + d_x, top_y + d_y))
              binaryMatrix[top_x + d_x][top_y + d_y] = 0
  
  return n_islands

binaryMatrix = [ [0,    1,    0,    1,    0],
                 [0,    0,    1,    1,    1],
                 [1,    0,    0,    1,    0],
                 [0,    1,    1,    0,    0],
                 [1,    0,    1,    0,    1] ]

print(get_number_of_islands(binaryMatrix))
