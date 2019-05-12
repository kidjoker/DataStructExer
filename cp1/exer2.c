//计算多项式的值
#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAXK 1e8

clock_t start,stop;
double duration;

double f1(int n, double a[], double x){
    int i;
    double p = a[0];
    for(i = 1; i <= n; i++) {
        p += (a[i]  * pow(x,i));
    }
    return p;
}

double f2(int n, double a[], double x) {
    int i;
    double p = a[n];
    for(int i = n; i > 0; i--) {
        p = a[i-1] + x*p;
    }
    return p;
}

int main(void) {
    int i;
    start = clock(); //开始计时
    
    double arr[] = {2,4,5,6};
    double result;
    for(i = 0; i < MAXK; i++) {
        result = f2(3,arr,1.5);
    }
    stop = clock(); //结束计时

    printf("%6.2f\n",result);
    duration = ((double)(stop-start))/CLOCKS_PER_SEC;
    printf("%6.2f\n", duration);
    return 0;
}