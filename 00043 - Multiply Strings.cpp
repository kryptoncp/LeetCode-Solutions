class Solution {
private:
  string f(string num, char x, int times) {
    int carry = 0;
    string res(times, '0');
    for (int i = (int) num.size() - 1; i >= 0; i--) {
      int sum = (x - '0') * (num[i] - '0') + carry;
      res.push_back((sum % 10) + '0');
      carry = sum / 10;
    }
    while (carry) {
      res.push_back((carry % 10) + '0');
      carry /= 10;
    }
    return res;
  }
  string add(string ans, string str) {
    int i = 0;
    int j = 0;
    int carry = 0;
    int n = (int) ans.length();
    int m = (int) str.length();
    string temp = "";
    while (i < n || j < m || carry) {
      int sum = carry;
      if (i < n) sum += ans[i++] - '0';
      if (j < m) sum += str[j++] - '0';
      temp.push_back((sum % 10) + '0');
      carry = sum / 10;
    }
    return temp;
  }
public:
  string multiply(string num1, string num2) {
    if (num1[0] == '0' || num2[0] == '0') return "0";
    string ans = "";
    int times = 0;
    for (int x = (int) num2.length() - 1; x >= 0; x--) {
      string str = f(num1, num2[x], times);
      ans = add(ans, str);
      times++;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
