#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int checker(int r, int c, int start_y, int start_x, long long length){
    int count = 0;

    // Base case

    if (length == 2){
        if(r == start_y){
            if(c != start_x) count += 1;
        }
        else{
            if(c != start_x) count += 3;
            else count += 2;
        }
        return count;
    }
    
    // 1사분면 or 2사분면
    if (start_y + length / 2 > r){
        // 2사분면
        if(start_x + length / 2 > c){
            count += checker(r, c, start_y, start_x, length / 2);
        }
        // 1사분면
        else{
            count += length * length / 4;
            count += checker(r, c, start_y, start_x + length / 2, length / 2);

        }

    }
    // 3사분면 or 4사분면
    else{
        // 3사분면
        if(start_x + length / 2 > c){
            count += length * length / 4 * 2;
            count += checker(r, c, start_y + length / 2, start_x, length / 2);

        }
        // 4사분면
        else{
            count += length * length / 4 * 3;
            count += checker(r, c, start_y + length / 2, start_x + length / 2, length / 2);
     
        }

    }

    return count;

}
int main(void){
    int n, r, c;
    cin >> n >> r >> c; // input data
    long long length = pow(2, n);
    cout << checker(r, c, 0, 0 , length) << "\n";

    return 0;
}