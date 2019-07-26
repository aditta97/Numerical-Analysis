#include <iostream>
using namespace std;

float fact(int n){
        return (n == 1 || n == 0) ? 1 : fact(n - 1) * n;
}

float npr(int n, int r){
        return fact(n) / fact(n - r);
}

float ncr(int n, int r){
        return npr(n, r) /fact(r);
}

int main(){
        int r, i, n, x;
        float y = 0.00, div = 0.0;

        cout<<"How many term do you have? ";
        cin>>n;

        float num[n];
        cout<<"Enter '0' for missing value"<<endl;
        for(i = 1; i <= n; i++) {
                cout<<"Y "<<i<<": ";
                cin>>num[i];
                cout<<endl;
        }
        x = n;
        n = n - 1;
        int sign = 0;
        while(x > 0) {
                r = x - 1;
                if(num[x] != 0) {
                        if(sign == 0) {
                                y = y + (ncr(n,r) * num[x]);
                        } else{
                                y = y - (ncr(n, r) * num[x]);
                        }
                } else{
                        div = (sign == 1) ? ncr(n,r) : -ncr(n,r);
                }
                sign = (sign == 0) ? 1 : 0;
                x--;
        } if(div != 0.00) {
                cout<< y / div;
        } else{
                cout<<'Not possible';
        }
}
