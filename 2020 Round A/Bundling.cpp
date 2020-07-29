#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

class Trie {
private:
	ll num;
	vector<Trie*> next;

public:
    Trie() {
		num = 0;
		next.resize(26, NULL);
	}
	void insert(string word) {
		Trie* node = this;
		for (char c : word) {
			if (node->next[c - 'A'] == NULL) node->next[c - 'A'] = new Trie();
			node = node->next[c - 'A'];
			node->num++;
		}
	}

	ll get_result(ll K) {
		ll result = 0;
		queue<Trie *> q;
		q.push(this);
		while (!q.empty()) {
			Trie *cur = q.front();
			q.pop();
			for (int i = 0; i < 26; i++) {

				if (cur->next[i] == NULL || cur->next[i]->num < K) continue;
				result += cur->next[i]->num / K;
				q.push(cur->next[i]);
			}
		}
		return result;
	}
};

void solution() {
	ll N, K;
	cin >> N >> K;

	vector<string> data(N);
	for (ll i = 0; i < N; i++) {
		cin >> data[i];
	}

	Trie *tree = new Trie();
	for (ll i = 0; i < N; i++) {
		tree->insert(data[i]);
	}

	cout << tree->get_result(K) << endl;

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