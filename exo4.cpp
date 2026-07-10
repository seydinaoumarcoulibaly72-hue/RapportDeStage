#include <iostream>
#include <vector>
 
using namespace std;
 
int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    if(!(cin >> n >> q)) return 0;
    
    vector<long long> diff(n+2, 0);
    
    for (int i = 0; i < q; ++i) {
        int l, r;
        long long v;
        
        cin >> l >> r >> v;
        
        diff[l] += v;
        diff[r + 1] -= v;
    }
    
    long long current_value = 0;
    for (int i = 1; i <= n; ++i) {
        current_value += diff[i];
        
        cout << current_value << " ";
    }
    
    cout << endl;
    
    return 0;
}
