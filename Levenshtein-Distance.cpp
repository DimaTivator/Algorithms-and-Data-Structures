	string s, t;
	cin >> s >> t;
	s = ' ' + s;
	t = ' ' + t;
	int n = s.size(), m = t.size();
	vector <vector <int> > dp(n + 1, vector <int>(m + 1, 0));
	for (int i = 1; i < n + 1; i++) {
		dp[i][0] = i;
	}
	for (int j = 1; j < m + 1; j++) {
		dp[0][j] = j;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (s[i] == t[j]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
			}
		}
	}
	cout << dp[n - 1][m - 1] << endl;
