#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

bool compare(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
    if(a.first.first == b.first.first) return a.first.second < b.first.second;
    else{
        return a.first.first > b.first.first;
    }
}

int main(void){
    fastio;
    int n, c;
    cin >> n >> c;
    map<int, int> first_occurence;
    map<int, int> num_occur;

    for(int i = 0; i < n; i++){
        int n;
        cin >> n;
        if(first_occurence.find(n) == first_occurence.end()){
            first_occurence[n] = i;
        }
        num_occur[n] += 1;
    }

    vector<pair<pair<int, int>, int> > v;

    for(map<int, int>::iterator it = num_occur.begin(); it != num_occur.end(); it++){
        v.push_back(make_pair(make_pair(it -> second, first_occurence[it -> first]), it -> first));
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].first.first; j++){
            cout << v[i].second << " ";
        }
    }
    cout << "\n";
    return 0;
}