#include "../main.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct 
{
    int foot;
    double inch;
} Distance;

typedef struct 
{
    int real, imaginary;
} Complex;

Distance dist(int foot, double inch)
{
    Distance distance;
    distance.inch = inch;
    distance.foot = foot;

    return distance;
}

Distance add_dist(Distance a, Distance b)
{
    return dist(a.foot + b.foot, a.inch + b.inch);
}

Complex complex_num(int real, int imaginary)
{
    Complex complex;
    complex.real = real;
    complex.imaginary = imaginary;

    return complex;
}

Complex add(Complex a, Complex b)
{
    return complex_num(a.real + b.real, a.imaginary + b.imaginary);
}

void print_complex(Complex complex)
{
    printf("Complex: %d %s %di\n", complex.real, complex.imaginary < 0 ? "-" : "+", abs(complex.imaginary));
}

void run_struct()
{
    printf("\n\n/// STRUCT ///\n\n");

    Distance distance = dist(100, 8.3);
    printf("a: Inch: %f, Foot: %d\n", distance.inch, distance.foot);

    Distance distance2 = dist(200, 16.7);
    printf("b: Inch: %f, Foot: %d\n", distance2.inch, distance2.foot);

    Distance sum = add_dist(distance, distance2);
    printf("SUM : Inch: %f, Foot: %d\n", sum.inch, sum.foot);

    Complex a = complex_num(5, -2);
    print_complex(a);

    Complex b = complex_num(-2, 5);
    print_complex(b);

    printf("Addition:\n");
    print_complex(add(a, b));
    
}