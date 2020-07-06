#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<pair<int, int>> v(n);
        int dmax = 0;
        for (int i = 0; i < n; i++) {
            int id, d, p;
            cin >> id >> d>>p;
            v[i] = {p, d};
            dmax = max(dmax, d);
        }
        sort(v.rbegin(), v.rend());
        vector<bool>slots(dmax, false); // 1 2 3 4...
        int k,sum = 0,c = 0;
        for(int i=0;i<n;i++){
            k = v[i].second;
            while(k>=1){
                k--;
                if(!slots[k]) {
                    slots[k] = true;
                    sum+= v[i].first;
                    c++;
                    break;
                }
            }
        }
        cout<<c<<" "<<sum<<"\n";

    }
    return 0;
}
