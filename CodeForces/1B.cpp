/* ------------------------------*/
/* Created by LinX on 2021/03/25.*/
/* ------------------------------*/

#include<iostream>
#include<cstdio>
#include<cmath>
typedef long long ll;
using namespace std;

int n;
int row, col, flag;
string s,t;

void change(int r, int c, int f) {
    //cout<<r<<" "<<c<<endl;
    if(f == 1) {
        int tt = 0;
        while(c) {
            if(c%26==0) {
                tt += 1;
                t = char('Z') + t;
            }
            else {
                t = char(c%26 + 'A' - 1) + t;
            }
            c = c/26 - tt;
            tt = 0;
        }
        cout<<t<<r<<endl;
    }
    else {
        cout<<"R"<<r<<"C"<<c<<endl;
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n--) {
        row = col = 0;
        s = t = "";
        cin>>s;
        int len = s.size();
        int cnt=0;
        for(int i=1;i<len;i++) {
            if(isalpha(s[i-1])&&isdigit(s[i])) {
                cnt+=1;
            }
        }
        if(cnt==2) {
            for(int i=1;i<len;i++) {
                if(isdigit(s[i])) {
                    row = row * 10 + s[i] - '0';
                }
                else {
                    flag = i+1;
                    for(int j=flag;j<len;j++) {
                        col = col * 10 + s[j] - '0';
                    }
                    break;
                }
            }
            change(row, col, 1);
        }
        else {
            int num = 1, num2 = 1;
            for(int i=len-1;i>=0;i--) {
                if(isdigit(s[i])) {
                    row += (s[i] - '0') * num;
                    num = num * 10;
                }
                else {
                    flag = i;
                    for(int j=flag;j>=0;j--) {
                        col += (s[j] - 'A' + 1) * num2;
                        num2 = num2 * 26;
                    }
                    break;
                }
            }
            change(row, col, 0);
        }
    }
    return 0;
}
