class Solution {
public:
  int longestMonotonicSubarray(vector<int>& a) {
    int n = (int) a.size();
    int inc = 1;
    int dec = 1;
    int max_len = 1;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] < a[i + 1]) {
        inc++;
        dec = 1;
      } else if (a[i] > a[i + 1]) {
        dec++;
        inc = 1;
      } else {
        inc = 1;
        dec = 1;
      }
      max_len = max({max_len, inc, dec});
    }
    return max_len;
  }
};
