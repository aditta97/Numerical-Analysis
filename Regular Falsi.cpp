#include <bits/stdc++.h>

using namespace std;
float func(float x){
        return (3*x - cos(x) - 1);
}

int main(){
        float a = 0, b = 1, c, allerr = 0.001;

        if(func(a) * func(b) >= 0) {
                cout<<"Invalid a and b selection"<<endl;

                while((b-a) >= allerr) {
                        c = (a * func(b) - b * func(a)) / func(b) - func(c);
                        if(func(c) == 0) {
                                printf("Root = %f\n", c);
                                break;
                        }
                        else if(func(a) * func(c) < 0) {
                                printf("Root = %f\n", c);
                                b = c;
                        }
                        else{
                                printf("Root = %f\n", c);
                                a = c;
                        }
                }
        }
}
