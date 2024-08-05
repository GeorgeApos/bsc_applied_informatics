#include <genlib.h>
#include "simpio.h"
#include "stdio.h"
#include "math.h"
#define a 1000


double rightside(int x);

int main(){
printf("Pi = %g\n\n", rightside(a));
system("PAUSE");
return 0;

}

double rightside(int x){
double pi;
int i;
i=2;
pi = 2;
for (i=2; i<=x; i+=2)
    pi *= pow(i, 2) / (double)((i-1)*(i+1));
return pi;
}
