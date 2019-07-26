#include <stdio.h>
#include <math.h>

float fun(float x){
        return (3*x - cos(x)-1);
}
void bisection(float *c, float a, float b, int *itr){
        *c = (a+b)/2;
        ++(*itr);
        printf("iteration No. %d = %f\n", *itr, *c);
}

int main(){
        int itr = 0, maxitr = 0;
        float c = 0, a, b, allow_err, r = 0;
        printf("Enter the value of a, b, Allowed Error and maximum iteration : ");
        scanf("%f %f %f %d", &a, &b, &allow_err, &maxitr);
        bisection(&c, a, b, &itr);

        do {
                if(fun(a) * fun(c) < 0) {
                        b = c;
                }
                else{
                        a = c;
                }
                bisection(&r, a, b, &itr);
                if(fabs(r - c) < allow_err) {
                        printf("After %d th iteration, root = %f\n", itr, r);
                        return 0;
                }
                c = r;
        } while(itr < maxitr);

        printf("The solution does not converge or not sufficient");
        return 0;
}
