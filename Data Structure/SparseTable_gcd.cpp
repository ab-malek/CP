const int N  = 2e5+5;

int t[N][18], a[N];
void build(int n) {
  for(int i = 1; i <= n; ++i) t[i][0] = a[i];
  for(int k = 1; k < 18; ++k) {
    for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
      t[i][k] = __gcd(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int query(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  return __gcd(t[l][k], t[r - (1 << k) + 1][k]);
}
