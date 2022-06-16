vector <int> get_z(string s) {
    int n = sz(s);
    vector <int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while (z[i] + i < n && s[z[i]] == s[z[i] + i]) {
            z[i]++;
        }
        if (z[i] + i > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
