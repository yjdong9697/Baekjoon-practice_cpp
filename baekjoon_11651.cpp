#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

typedef struct{
    int x;
    int y;
}point;

bool compare(const point value1, const point value2){
    if (value1.y == value2.y){
        return value1.x < value2.x;
    }
    else{
        return value1.y < value2.y;
    }

}

int main(void){
    int n;
    cin >> n;

    vector<point> cor_store;
    for(int i = 0; i < n; i++){
        point temp;
        cin >> temp.x >> temp.y;
        cor_store.push_back(temp);
    }

    sort(cor_store.begin(), cor_store.end(), compare);

    for(int i = 0; i < n ; i++){
        cout << cor_store[i].x << " " << cor_store[i].y << "\n";
    }

    return 0;

}