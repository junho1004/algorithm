#include<string>
#include<stack>
#include <iostream>

using namespace std;
stack<char> st;

bool solution(string s)
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    bool answer = true;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == ')'){
            if(st.empty()) return false;
            else st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    
    if(st.empty()) answer = true;
    else answer = false;
    

    return answer;
}