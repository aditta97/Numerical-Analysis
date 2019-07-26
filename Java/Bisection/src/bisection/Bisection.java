
package bisection;

import static java.lang.Math.cos;

public class Bisection {

    static final float epsilon = 0.001f;
    static float func(float x) {
        return (float) (3 * x - cos(x) - 1);
    }

    static void bisection(float a, float b) {
        if (func(a) * func(b) > 0) {
            System.out.println("You have not assumed right A and B");
            return;
        }
        float c = a;
        while ((b - a) >= epsilon) {
            c = (a + b) / 2;
            if (func(c) == 0.0) {
                break;
            }
            if (func(a) * func(c) <= 0) {
                b = c;
            } else {
                a = c;
            }
            System.out.printf("The value of root is : %.2f\n", c);
        }
    }
    
    public static void main(String[] args) {
        float a = 0, b = 1;
        bisection(a, b);
    }
    
}
