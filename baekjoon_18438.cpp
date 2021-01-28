#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

string first, second;


void LCS_foward(int fl, int fr, int sl, int sr, vector<int> &data){
    data.resize(sr - sl + 1, 0); // 0으로 초기화

    for(int i = fl; i < fr ; i++){
        for(int j = sr - 1; j >= sl; j--){
            data[j - sl + 1] = max(data[j - sl + 1], data[j - sl] + (second[j] == first[i]));
        }
        for(int j = 1; j <= sr - sl; j++){
            data[j] = max(data[j - 1], data[j]);
        }
    }
    return;
}

void LCS_backward(int fl, int fr, int sl, int sr, vector<int> &data){
    data.resize(sr - sl + 1, 0);

    for(int i = fr - 1; i >= fl; i--){
        for(int j = sl; j <= sr - 1; j++){
            data[sr - j] = max(data[sr - j], data[sr - j - 1] + (second[j] == first[i]));
        }
        for(int j = 1; j <= sr - sl; j++){
            data[j] = max(data[j - 1], data[j]);
        }
    }
    return;
}

// l은 포함, r은 포함하지 않음
string Hirschberg(int fl, int fr, int sl, int sr){
    if(fl >= fr || sl >= sr) return ""; // 0칸이거나 그 미만인 경우

    if(fr == fl + 1){
        for(int i = sl; i < sr; i++){
            if(first[fl] == second[i]){
                return first.substr(fl, 1);            
            }
        }
        return "";
    }
    if(sr == sl + 1){
        for(int i = fl; i < fr; i++){
            if(first[i] == second[sl]){
                return first.substr(i, 1);
            }
        }
        return "";
    }
    
    vector<int> foward, backward;
    int fm = (fl + fr) / 2;
    LCS_foward(fl, fm, sl, sr,  foward);
    LCS_backward(fm, fr, sl, sr, backward);

    int index = -1;
    int sum = -1;

    for(int i = 0; i < sr - sl + 1; i++){
        if(sum < foward[i] + backward[sr - sl - i]){
            sum = foward[i] + backward[sr - sl - i];
            index = i;
        }
    }

    return Hirschberg(fl, fm, sl, sl + index) + Hirschberg(fm, fr, sl + index, sr);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> first >> second;

    string result = Hirschberg(0, first.size(), 0, second.size());

    cout << result.size() << "\n";
    cout << result << "\n";

    return 0;
}