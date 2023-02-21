#include <iostream>
using namespace std;
 
int first, last, ans;
 
void init(){
    first = last = ans = 0;
}
    
void input(){
    cin >> first >> last;   
}
 
void solve(){
    int temp = first + last;
     
    ans = temp % 24;
}
 
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
     
    int tcCnt;
    cin >> tcCnt;
     
    for(int tc = 1; tc <= tcCnt; tc++){
        init();
        input();
        solve();
        cout << "#" << tc << " " << ans << "\n";
    }
     
}