#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void solution() {
	int N, K, P;
	cin >> N >> K >> P;
	vector<vector<int>> value(N, vector<int>(K));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cin >> value[i][j];
		}
	}

	vector<vector<int>> sum(N + 1, vector<int>(K + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			sum[i][j] = sum[i][j - 1] + value[i - 1][j - 1];
		}
	}

	vector<vector<int>> dp(N + 1, vector<int>(P + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= P; j++) {
			for (int x = 0; x <= min(j, K); x++)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + sum[i][x]);
		}
	}

	cout << dp[N][P] << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solution();
	}
	return 0;
}