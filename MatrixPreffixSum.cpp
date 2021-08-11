// преффиксные суммы на матрице n * m
int n, m;
	cin >> n >> m;
	vector <vector <ll> > a(n, vector <ll>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector <vector <ll> > p(n, vector <ll>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			p[i][j] = a[i][j];
			if (i) p[i][j] += p[i - 1][j];
			if (j) p[i][j] += p[i][j - 1];
			if (i && j) p[i][j] -= p[i - 1][j - 1];
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		x2--;
		y1--;
		y2--;
		ll ans = p[x2][y2];
		if (x1) ans -= p[x1 - 1][y2];
		if (y1) ans -= p[x2][y1 - 1];
		if (x1 && y2) ans += p[x1 - 1][y1 - 1];
		cout << ans << endl;
	}
