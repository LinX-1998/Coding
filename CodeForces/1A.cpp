/* ------------------------------*/
/* Created by LinX on 2021/03/25.*/
/* ------------------------------*/

#include<iostream>
#include<cstdio>
typedef long long ll;
using namespace std;
int main() {
    ll n,m,a;
    ll ans;
    cin>>n>>m>>a;
    if(n%a != 0) {
        ans = n/a+1;
    }
    else {
        ans = n/a;
    }
    if(m%a != 0) {
        ans = ans * (m/a + 1);
    }
    else {
        ans = ans * (m/a);
    }
    cout<<ans<<endl;
    return 0;
}
