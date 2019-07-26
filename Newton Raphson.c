#include <stdio.h>
#include <math.h>

float f(float x){
        return (3 * x - cos(x) - 1);
}

float df(float x){
        return (3 + sin(x));
}

int main(){
        int itr, maxitr;
        float h, x0, x1, allerr;

        printf("Enter the value of X0, Allowed error and Max iteration : ");
        scanf("%f %f %d", &x0, &allerr, &maxitr);

        for(itr = 1; itr <= maxitr; itr++) {
                h = f(x0) / df(x0);
                x1 = x0 - h;
                printf("At iteration No : %d, x = %f\n", itr, x1);

                if(fabs(h) < allerr) {
                        printf("At %d iteration, Root = %f\n", itr, x1);
                        return 0;
                }
                x0 = x1;
        }
        printf("The required solution needs more iteration to find the root.");
        return 1;
}
