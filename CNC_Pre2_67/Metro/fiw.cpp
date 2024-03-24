#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main (){
	cin.tie(nullptr)->sync_with_stdio(0);

	int N, M;
	scanf("%d %d", &N, &M);

	// Say Laka
	unordered_map<int, vector<int>> now;
	pair<vector<int>, int> K[M];
	int x, y;
	for (int i=0; i<M; i++){
		scanf("%d %d", &x, &y);
		K[i].second = y;
		while (x--){
			scanf("%d", &y);
			K[i].first.emplace_back(y);
			now[y].emplace_back(i);
		}
	}

	int ans[N];
	bool visit[N];
	for (int i=0; i<N; i++){
		ans[i] = INF;
		visit[i] = false;
	}
	ans[0] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>Q;
    Q.emplace(make_pair(0, 0));

	while (!Q.empty()){
		int u = Q.top().first, v = Q.top().second;
		Q.pop();

		if (visit[v]){
			continue;
		}

		visit[v] = true;
		for (int i=0; i<now[v].size(); i++){
			for (int k=0; k<K[now[v][i]].first.size(); k++){
				if (v != K[now[v][i]].first[k]){
					int check = K[now[v][i]].first[k];
					if (ans[check] > u+K[now[v][i]].second){
						ans[check] = u+K[now[v][i]].second;
						Q.emplace(make_pair(ans[check], check));
					}
				}
			}
		}
	}

	if (ans[N-1] == INF){
		printf("-1");
	}else {
		printf("%d", ans[N-1]);
	}

	return 0;
}