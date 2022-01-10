// finding min on [l;r] for O(sqrt(n))
int n, s, sz;
vector <int> a, d;

void build() {
    d.resize(sz / s);
    int j = 0, cur = 1, mn = INF;
    for (int i = 0; i < sz; i++) {
        mn = min(mn, a[i]);
        if (i + 1 == s * cur) {
            d[j] = mn;
            mn = INF;
            j++;
            cur++;
        }
    }
}

void update(int pos, int val) {
    int p = (pos % s ? pos / s + 1 : pos / s);
    a[pos - 1] = val;
    int mn = INF;
    for (int i = s * (p - 1); i < s * p; i++) {
        mn = min(a[i], mn);
    }
    d[p - 1] = mn;
}

int get(int l, int r) {
    int mn = INF;
    while (l < r) {
        if (l % s || l + s >= r) {
            mn = min(mn, a[l]);
            l++;
        }
        else {
            mn = min(mn, d[l / s]);
            l += s;
        }
    }
    return mn;
}

void solve() {
    cin >> n;
    s = ceil(sqrt(n));
    sz = (n % s ? s * (n / s + 1) : s);
    a.resize(sz);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n; i < sz; i++) a[i] = INF;
    build();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        // change element
        if (t == 1) {
            int pos, val;
            cin >> pos >> val;
            update(pos, val);
        }
        // get min
        else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << get(l, r) << endl;
        }
    }
}
