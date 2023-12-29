def find_busiest_period(data):
  res, max_people = None, 0
  i = 0
  curr_people = 0
  while i < len(data):
    curr_timestamp = data[i][0]
    if data[i][2] == 1:
      curr_people += data[i][1]
    else:
      curr_people -= data[i][1]
    while i+1 < len(data) and data[i+1][0] == data[i][0]:
      if data[i+1][2] == 1:
        curr_people += data[i+1][1]
      else:
        curr_people -= data[i+1][1]
      i += 1
    if curr_people > max_people:
      max_people = curr_people
      res = curr_timestamp
    i += 1
  
  return res


data = [ [1487799425, 14, 1], 
         [1487799425, 4,  0],
         [1487799425, 2,  0],
         [1487800378, 10, 1],
         [1487801478, 18, 0],
         [1487801478, 18, 1],
         [1487901013, 1,  0],
         [1487901211, 7,  1],
         [1487901211, 7,  0] ]

print(find_busiest_period(data))

'''
int findBusiestPeriod( const vector<vector<int> >& data ) 
{
  // your code goes here
  int gMax = 0;
  int max_so_far = 0;
  int lMax = 0;
  int n = data.size();
  
for(int i = 0; i < n; i++) {   
  
    if(data[i][2] == 1) {
        lMax += data[i][1];
      } else {
        lMax -= data[i][1];
      }
  
    if(i < n -1 && data[i][0] == data[i+1][0]) {
      continue;
    }

    if(lMax > gMax) {
      gMax = lMax;
      max_so_far = data[i][0];
    }
}
  return max_so_far;
}
'''


'''
Input:
 
[[1487799425,14,1],
 [1487799425,4,1],
 [1487799425,2,1],
 [1487800378,10,1],
 [1487801478,18,1],
 [1487901013,1,1],
 [1487901211,7,1],
 [1487901211,7,1]]
Expected:
 
1487901211
Actual:
 
1487799425
'''
