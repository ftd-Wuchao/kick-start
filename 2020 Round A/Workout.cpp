#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;

bool successful(vector<ll> diff,ll mid,ll K){
    ll k = 0;
    for(auto x:diff){
        k+= x/mid;
        if(x%mid==0) k--;
        if(k>K) return false;
    }
    return true;
}

void solution() {
	ll N, K;
	cin >> N >> K ;
    vector<ll> diff,M(N);

    ll dmax=INT_MIN;
    for(ll i=0; i<N; i++){
        cin>>M[i];
        if(i>0) {
            diff.push_back(M[i]-M[i-1]);
            if(dmax < diff.back()) dmax=diff.back();
        }
    }      
    ll left=1,right=dmax;
    while(left<=right){
        ll mid = left+(right-left)/2;
            
        if(successful(diff,mid,K)){
            right = mid-1;

        }else{
            left = mid+1;
        }
        
    }

	cout << left << endl;
}

int main() {
	ll T;
	cin >> T;
	for (ll i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solution();
	}
	return 0;
}