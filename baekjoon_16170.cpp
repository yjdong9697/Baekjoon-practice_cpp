#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main(void){
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    cout << t -> tm_year + 1900 << "\n";
    cout << t -> tm_mon + 1 << "\n";
    cout << t -> tm_mday << "\n";
    return 0;
}