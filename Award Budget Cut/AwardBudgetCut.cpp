  #include <iostream>
  #include <vector>

  using namespace std;

  double findGrantsCap( vector<int> grantsArray, int newBudget ) 
  {
    // your code goes here
    int n = grantsArray.size();
    if(n == 0) {
      return 0;
    }


    // [2,100,50,120,167], 400

    sort(grantsArray.begin(), grantsArray.end());

    //[2,50,100,120,167]

    // find range
    int sum = 0;
    double start = 0.0, end = 0.0;
    int pivot = 0;

    for(int i = 0; i < grantsArray.size(); i++) {
      // 167 * 1 - 272 = 88 < 400 - sum 
      if(sum + grantsArray[i]*(n-i) > newBudget) {
        end = grantsArray[i]; // 100
        break;
      }

      start = grantsArray[i]; // 50
      sum += grantsArray[i]; // 52 
      pivot++; // 2
    }

    cout << " start " << start << " end " << end; 

    // Binary Search
    double newBudget1 = (newBudget - sum); // 400 - 52 = 348

    while(start <= end) {
      double mid = start + (end - start) / 2.0; // 75

      if((mid * (n - pivot)) == newBudget1) { // 75 * 3 ==  348
        return mid;
      } else if ((mid * (n - pivot)) > newBudget1) {
        end = mid;
      } else {
        start = mid; // 76
      }
    }

    return 0;
  }

  int main() {


    return 0;
  }

  // maximum cap, minimum affected grant recipients

  // input:  grantsArray = [2, 100, 50, 120, 1000], newBudget = 190
  //  [2, 50, 100, 120, 1000]
  // new Arr ->    [2, 50, 100, 120, 190]
  // solution range [2, 50], mid = 26, 37, .. 47 
  // target = 190 - 2 = 188, 4 * x = 188
  // prefix sum -> [0, 2, 52, 152, 272]
  // output: 47

  // 1272 < 2000 => o/p 1000
