
package newtonraphson;

import static java.lang.Math.cos;
import static java.lang.Math.sin;

class Function{
    static final float epsilon = 0.001f;
    static float func(float x){
        return (float) (3 * x - cos(x) - 1);
    }
    
    static float differentiate(float x){
        return (float) (3 + sin(x));
    }
    
    static void newtonRaphson(float x){
        float h = func(x) / differentiate(x);
        
        while(Math.abs(h) >= epsilon){
            h = func(x) / differentiate(x);
            x = x - h;
        }
        System.out.println("The value of the root is "+Math.round(x * 100.0) / 100.0);
    }
}

public class NewtonRaphson {

    public static void main(String[] args) {
        
        float x = 0;
        Function.newtonRaphson(x);
    }
    
}
