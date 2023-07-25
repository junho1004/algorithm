#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

char names[] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
char path[10];
bool used[10];
int cnt, N;
vector<string> v;

bool isVaild(){
    char op;
    int me, you, gap, people;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(path[j] == v[i][0]) me = j;
            else if(path[j] == v[i][2]) you = j;
        }
        
        op = v[i][3];
        gap = v[i][4] - '0';
        people = abs(me - you) - 1;
        
        //cout << me << " " << you << " " << op << " " << gap << "\n";
        if(op == '>'){
            if(people <= gap) return 0; // 사람수가 gap 이하이면 안돼
        }
        else if(op == '='){
            if(people != gap) return 0; // 사람수가 gap 이면 안돼
        }
        else if(op == '<'){
            if(people >= gap) return 0; // 사람수가 gap 이상이면 안돼
        }
    }
    
    return 1;
}


void dfs(int lev){
    if(lev == 8)
    {
        if(isVaild()) cnt++;
        return;
    }
    
    for(int i = 0; i < 8; i++){
        if(used[i]) continue;
        used[i] = 1;
        path[lev] = names[i];
        dfs(lev + 1);
        used[i] = 0;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    cnt = 0;
    N = n;
    v = data;
    int answer = 0;
    
    dfs(0);
    answer = cnt;
    return answer;
}