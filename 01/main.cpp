#include <stdio.h>
#include <math.h>

double func(double x);
double find(double infinum, double supremum, double epsilon);

double func(double x)
{
    return 10 - x;
}
 
int iters = 0, ok = 0, MAX_ITERS = 10000;
double find(double infinum, double supremum, double epsilon)
{
    ok = 0;
    if(func(supremum) * func(infinum) > 0){
        printf("NO ROOT %f %f %f", infinum, supremum, func(supremum) * func(infinum));
        return 0;
    }
    if(supremum < infinum){
        double t = infinum;
        infinum = supremum;
        supremum = t;
    }
    while (fabs(supremum - infinum) > epsilon)
    {
        iters++;
        infinum = supremum - (supremum - infinum) * func(supremum) / (func(
                supremum) - func(infinum));
        supremum = infinum - (infinum - supremum) * func(infinum) / (func(
                infinum) - func(supremum));
        if(iters > MAX_ITERS){
            printf("MAX ITERS");
            return 0;
        }
    }
    ok = 1;
    return supremum;
}
 
int main()
{
double a, b, eps;
if (scanf("%lf %lf %lf", &a, &b, &eps) == 3){
double res = find(a, b, eps);
if(ok){
    printf("%lf", res);
}
}

    return 0;
}