#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(p) p.begin(), p.end()
#define mid(s, e) (s + (e - s) / 2)
#define tcase()                                                                \
  ll t, n;                                                                     \
  cin >> t;                                                                    \
  n = t;                                                                       \
  while (t--)
#define iscn(num) scanf("%d", &num);
#define eb emplace_back
#define ull unsigned long long
#define KAMEHAMEHA ios_base::sync_with_stdio(0);
#define RASENGAN                                                               \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
using namespace std;
void strrev(string &s) {
  for (int i = 0; i < (s.length() / 2); i++) {
    swap(s[i], s[s.length() - i - 1]);
  }
}
int main() {
  KAMEHAMEHA
  //    #ifdef _soumik
  //        freopen("input.txt", "r", stdin);
  //    #endif
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    strrev(s1), strrev(s2);
    int pos, sz2 = s2.size(), sz1 = s1.size();
    for (int i = 0; i < sz2; i++) {
      if (s2[i] == '1') {
        pos = i;
        break;
      }
    }
    int ans = 0;
    // cout<<sz1<<" "<<sz2<<" "<<pos<<endl;
    for (int i = pos; i < sz1; i++) {
      // cout<<s1[i]<< " "<<i<<endl;
      if (s1[i] == '1') {
        ans = i - pos;
        break;
      }
      // ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
