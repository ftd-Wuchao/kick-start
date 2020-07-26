#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int T;

int main() {
	cin >> T;
	int t = 1;
	while (t <= T) {
		int N, Budget;
		cin >> N >> Budget;
		vector<int> Cost(N);
		for (int i = 0; i < N; i++) {
			cin >> Cost[i];
		}
		sort(Cost.begin(), Cost.end());
		int ret = 0;
		for (int i = 0; i < N; i++) {
			Budget = Budget - Cost[i];
			if (Budget >= 0) ret++;
			else break;
		}
		cout << "Case #" << t << ": " << ret << endl;
		t++;
	}
	return 0;
}