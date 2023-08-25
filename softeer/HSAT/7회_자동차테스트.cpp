#include<iostream>
#include<algorithm>
using namespace std;

int N, Q;
int arr[50010];

void input(){
  cin >> N >> Q;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }
}

void solve(){
  if(N <= 2){
    cout << 0 << "\n";
    return;
  }
  sort(arr, arr + N);
  
  int tar;
  for(int i = 0; i < Q; i++)
  {
    cin >> tar;
    
    int ansFlag = 0;
    int mini = 0;
    int maxi = N;
    int pivot = N / 2;
    int tmp = -1;
    // 이분탐색
    while(1)
    {
      // 맞았다.
      if(tar == arr[pivot]) {
        ansFlag = 1;
        break;
      }
      // pivot보다 왼쪽이다.
      else if(tar < arr[pivot]){
        maxi = pivot;
        pivot = (mini + pivot) / 2;
      }
      // pivot보다 오른쪽이다.
      else if(tar > arr[pivot]){
        mini = pivot;
        pivot = (pivot + maxi) / 2;
      }
      // 없다.(이전과 pivot이 똑같다.)
      if(tmp == pivot) break;
      tmp = pivot;
    }
    
    if(ansFlag){
      cout << pivot * (N - pivot - 1) << "\n";
    }
    else cout << 0 << "\n";
  }
}

int main(int argc, char** argv)
{
  cin.tie(0); cout.tie(0);
  ios::sync_with_stdio(0);

  input();
  solve();
  
  return 0;
}