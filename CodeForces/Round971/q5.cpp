#include <bits/stdc++.h>
using namespace std;

long long sum(long long n, long long a, long long d) {
    long long result = n * (2 * a + (n - 1) * d);
    result = result / 2;
    return result;
}

long long solve(long long n, long long k){
    long long l = k;
    long long r = k + n - 1;
    long long ind = 0;
    long long cnt = 0;

    while (l <= r) {
        cnt++;
        long long mid = (l + r) / 2;
        long long s1 = sum(mid - k + 1, k, 1);
        long long s2 = sum(k + n - 1 - mid, mid + 1, 1);

        if (s1 <= s2) {
            ind = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    long long dif = LLONG_MAX;
    long long result = ind;

    for(long long i=ind-10;i<=ind+10;i++) {
        if (i < k || i > k + n - 1) continue;

        long long s1 = sum(i - k + 1, k, 1);
        long long s2 = sum(k + n - 1 - i, i + 1, 1);
        long long cur = abs(s1 - s2);

        if(cur<dif) {
            dif = cur;
            result = i;
        }
    }
    return dif;
}

int main() {
    int t; cin>>t;
    for(int i = 0; i < t; ++i) {
        long long n, k; cin>>n>> k;
        cout<<solve(n,k)<<"\n";
    }

    return 0;
}
