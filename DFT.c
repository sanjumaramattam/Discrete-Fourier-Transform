// Program to compute the DFT of a signal
#include<stdio.h>
#include<math.h>
#include<complex.h>
int main()
{   int i,x[100],N,L,k;
    char sign;
    double PI=acos(-1);
    double complex X[100];
    printf("Enter the size of the input signal  ");
    scanf("%d",&L);
//input the signal
    printf("Enter the input signal x(n)= ");
    for(i=0;i<L;i++)
        scanf("%d",&x[i]);
    printf("Enter the size of the DFT signal  ");
    scanf("%d",&N);
    if(L<N)
       for(i=L;i<N;i++)
            x[i]=0;
//Display the signal
    printf("x(n)=[ ");
    for(i=0;i<N;i++)
        printf("%d ",x[i]);
    printf("] \n");
//Compute the dft
    for(k=0;k<N;k++)
    {   X[k]=0;
        for(i=0;i<N;i++)
            X[k]+=x[i]*cexp(-I*2*PI*k*i/N);
    }
// Display the dft
    printf("X(k)=[ ");
    for(k=0;k<N;k++)
        {sign = cimag(X[k])<0? '-':'+';
        printf("%f %c %fi   ",creal(X[k]),sign,fabs(cimag(X[k])));
        }
    printf("] ");
return 0;
}
