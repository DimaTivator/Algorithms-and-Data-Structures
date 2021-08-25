// Нахождение длины наибольшей общей подпоследовательности двух строк
	string s, t;
	cin >> s >> t;
	s = ' ' + s;
	t = ' ' + t;
	int n = s.size(), m = t.size();
	vector <vector <int> > dp(n, vector <int>(m, 0));
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (s[i] == t[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	cout << dp[n - 1][m - 1] << endl;
