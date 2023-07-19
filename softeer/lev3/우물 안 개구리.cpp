#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, answer;

 int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  vector<bool> iambest(n+1, 1);
  vector<int> power(n+1, 0);

  for(int i = 1; i <= n; i++) cin >> power[i];

  while(m--){
    cin >> a >> b;
    if(power[a] < power[b]){
      iambest[a] = 0;
    }else if(power[a] > power[b]){
      iambest[b] = 0;
    }else{
      iambest[a] = 0;
      iambest[b] = 0;
    }
  }
  // 아직 1인 사람(최고라고 생각) 카운팅
   for(int i = 1; i <= n; i++) if (iambest[i] > 0) answer++;
   
  cout << answer;
  return 0;
}