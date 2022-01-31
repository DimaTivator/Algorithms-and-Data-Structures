const int MOD = 1e9 + 7;
const int p = 47;


int sum(int a, int b) {
    a += b;
    return (a > MOD ? a - MOD : a);
}

int mul(int a, int b) {
    return a * b % MOD;
}

int sub(int a, int b) {
    return sum(a, MOD - b);
}

int pw[N];

vector <int> hash_str(string s) {
    int n = sz(s);
    vector <int> h(n);
    h[0] = 0;
    for (int i = 0; i < n; i++) {
        h[i + 1] = sum(mul(h[i], p), s[i] - 'a' + 1);
    }
    return h;
}

int get(int l, int r, vector <int> h) {
    return sub(h[r + 1], mul(h[l], pw[r - l + 1]));
}

void solve() {
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = mul(pw[i - 1], p);
    }
//    string s, t;
//    cin >> s >> t;
//    vector <int> hs = hash_str(s), ht = hash_str(t);
//    cout << (get(1, 4, hs) == get(3, 6, ht) ? "OK" : "NO") << endl;
}
