#include <stdio.h>
#include "numClass.h"
#include <math.h>
int factorial (int);

int isPrime(int num3){

    if (num3 < 1)
    {
        return 0;

    if (num3 == 1){
        return 1;
    }

    }
    for (int i = 2; i <= sqrt(num3); i++)
    {
        if (num3 % i == 0)
        {
            return 0;
        }
    }
        return 1;
}

int factorial(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int isStrong(int num)
{
    if (num == 0) {
        return 0;
    }
    int temp = num;
    int temp2;
    int sum = 0;
    while (temp > 0)
    {
        temp2 = (temp % 10);
        sum += factorial(temp2);
        temp = (temp / 10);
    }
    if (sum == num)
    {
        return 1;
    }
    return 0;
}

