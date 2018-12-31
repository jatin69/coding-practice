#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll s, ll x, ll r, ll *A, ll *B, ll C[][1006]) {
  if (s > x) {
    return 0;
  }
  if (r == 0) {
    return 0;
  }
  if (C[s][r] != -1) {
    return C[s][r];
  }

  ll t1, t2;
  if (r + B[s] > 1005) {
    t2 = 1005;
  } else {
    t2 = r + B[s];
  }
  C[s][r] = max(A[s] + solve(s + 1, x, r - 1, A, B, C),
                solve(s + 1, x, t2 - 1, A, B, C));
  return C[s][r];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    ll s, r;
    cin >> s >> r;
    ll A[s + 1], B[s + 1];
    for (int i = 1; i <= s; i++) {
      cin >> B[i];
    }
    for (int i = 1; i <= s; i++) {
      cin >> A[i];
    }
    ll C[1006][1006];
    for (int i = 0; i < 1006; i++) {
      for (int j = 0; j < 1006; j++) {
        C[i][j] = -1;
      }
    }
    if (r > 1005) {
      r = 1005;
    }
    ll ans = solve(1, s, r, A, B, C);
    cout << ans << endl;
  }
  return 0;
}
