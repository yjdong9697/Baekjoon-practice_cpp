#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    fastio;
    for(int i = 0; i < 3; i++){
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        int start = a * 3600 + b * 60 + c;
        int end = d * 3600 + e * 60 + f;
        int side = end - start;

        int hour = side / 3600;
        int min = (side % 3600) / 60;
        int sec = (side % 3600) % 60;

        cout << hour << " " << min << " " << sec << "\n";
    }
    
    return 0;
}