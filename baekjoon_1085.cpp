#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int element_store[4];

    element_store[0] = x;
    element_store[1] = w - x;
    element_store[2] = y;
    element_store[3] = h - y;

    cout << * min_element(element_store, element_store + 4) << "\n";

    return 0;
}