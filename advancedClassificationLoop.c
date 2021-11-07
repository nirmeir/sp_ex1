#include <stdio.h>
#include "NumClass.h"
#include <math.h>

int isPalindrome(int num)
{
    int temp1 = 0;
    int temp2 = 0;
    int num2 = num;
    while (num != 0)
    {
        temp1 = (num % 10);
        temp2 = temp2 * 10 + temp1;
        num = num / 10;
    }
    if (temp2 == num2)
    {
        return 1;
    }  
    return 0;
}

int isArmstrong(int num){

int counter =0;
int temp1 =num;
int temp2 =num;

int sum =0;

while (temp1 != 0){
counter++;
temp1 = temp1/10;
}

temp1 = num;

while (temp2 !=0) {
temp1 = temp2%10;
sum+= pow(temp1,counter);
temp2 = temp2/10;

}
if (sum == num ){
    return 1;
}
return 0;
}
