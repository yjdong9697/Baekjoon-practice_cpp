#include <bits/stdc++.h>
using namespace std;

int main(void){

    while(true){
        string t;
        getline(cin, t);
        if(t == ".") break;
        stack<char> s;
        bool flag = true;
        for(int j = 0; j < t.size(); j++){
            if(t[j] == '(' || t[j] == '['){
                s.push(t[j]);
            }
            else if(t[j] == ')'){
                if(s.empty() || s.top() != '('){
                    flag = false;
                    break;
                }
                else{
                    s.pop();
                }
                    
            }
            else if(t[j] == ']'){
                if(s.empty() || s.top() != '['){
                    flag = false;
                    break;
                }
                else{
                    s.pop();
                } 
            }
        }
        if(flag == false || s.size() > 0) cout << "no\n";
        else cout << "yes\n";
    }
    return 0;
}