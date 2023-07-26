#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n > 0)
    {
        int a = n % 3;
        n = n / 3;
        if(a == 0){
            n -= 1;    
        }
        answer = "412"[a] + answer;
    }
    
    
    /*
    while(n > 0)
    {
        int num = n % 3;
        if(num == 0){
            answer = "4" + answer;
            n = n / 3 - 1;
        }
        else{
            answer = to_string(num) + answer;
            n = n / 3;
        }
    }
    */
    
    return answer;
}