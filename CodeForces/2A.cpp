/* ------------------------------*/
/* Created by LinX on 2021/3/29.*/
/* ------------------------------*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<map>
#define maxn 1000
using namespace std;

int n, num, score[maxn];
string name[maxn];
string flag;
map<string, int>t;
int main() {
    while(cin>>n) {
        t.clear();
        num = -10000;
        for(int i=1;i<=n;i++) {
            cin>>name[i]>>score[i];
            if(t.count(name[i])>0) {
                t[name[i]] += score[i];
            }
            else {
                t[name[i]] = score[i];
            }
        }
        cout<<flag<<endl;
    }
    return 0;
}

