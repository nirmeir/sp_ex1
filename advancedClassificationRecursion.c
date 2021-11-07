#include <stdio.h>
#include "numClass.h"
#include <math.h>
int Rec (int,int,int);
int rev (int,int);

int Rec (int num ,int counter , int sum){


if (num >0 ){
sum += pow(num%10,counter);
return Rec((num/10),counter ,sum);

}

return sum;
}



int isArmstrong (int num){

int temp = num;
int counter=0;
int sum = 0;

while (temp!= 0){
counter++;
temp = temp/10;
}

if (num == Rec(num , counter , sum)){
    return 1;
}

return 0;
}



int rev(int n, int temp)
{
    if (n == 0)
        return temp;
 
    temp = (temp * 10) + (n % 10);
 
    return rev(n / 10, temp);
}
 
int isPalindrome(int num){

 int temp = 0;
 int sum = 0;  

 if (num < 0){
     return 0;
 }
 else
 sum = rev(num , temp);

if (num == sum){
    return 1;
}
return 0;
 
 } 
 
 

    
