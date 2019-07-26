package regularfalsi;

import static java.lang.Math.cos;

class Function {
    double func(double x) {
        return (3 * x - cos(x) - 1);
    }
}

public class RegularFalsi {

    public static void main(String[] args) {
        Function f = new Function();
        
        double a = 0, b = 1, c, allerr = 0.001;
        if (f.func(a) * f.func(b) <= 0) {
            while ((b - a) >= allerr) {
                c = ((a * f.func(b) - b * f.func(a)) / (f.func(b) - f.func(a)));
                if (f.func(c) == 0) {
                    System.out.printf("Root = %.2f\n", c);
                    break;
                } else if (f.func(a) * f.func(c) <= 0) {
                    System.out.printf("Root = %.2f\n", c);
                    b = c;
                } else {
                    System.out.printf("Root = %.2f\n", c);
                    a = c;
                }
            }
        } else {
            System.out.println("Invalid A & B selection");
        }
    }

}
