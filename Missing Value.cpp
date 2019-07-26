#include <iostream>
using namespace std;

float factorial(int n){
        return (n == 1 || n == 0) ? 1 : factorial (n-1) * n;
}

float npr(int n, int r){
        return factorial(n)/ factorial(n - r);
}

float ncr(int n, int r){
        return npr(n, r) / factorial(r);
}

int main(){
        int remove, loop, item, busket;
        float y = 0.00, div = 0.00;

        cout<<"How many term do you have? ";
        cin>>item;

        float number[item];
        cout<<"Enter '0' for missing value"<<endl;
        for(loop = 1; loop <= item; loop++) {
                cout<<"Index "<<loop<<": ";
                cin>>number[loop];
                cout<<endl;
        }
        busket = item;
        item = item - 1;
        int sign = 0;
        while(busket > 0) {
                remove = busket - 1;
                if(number[busket] != 0) {
                        if(sign == 0) {
                                y = y + (ncr(item, remove) * number[busket]);
                        } else if(sign != 0) {
                                y = y - (ncr(item, remove) * number[busket]);
                        }
                } else {
                        div = (sign == 1) ? ncr(item, remove) : -ncr(item, remove);
                }
                sign = (sign == 0) ? 1 : 0;
                busket--;
        } if(div != 0.00) {
                cout<< y / div;
        } else {
                cout<<"Invalid";
        }
}
