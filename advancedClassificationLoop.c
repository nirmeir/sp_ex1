// #include <stdio.h>
// #include "NumClass.h"
// #include <math.h>

// int isPalindrome(int num)
// {
//     int temp1 = 0;
//     int temp2 = 0;
//     int num2 = num;
//     while (num != 0)
//     {
//         temp1 = (num % 10);
//         temp2 = temp2 * 10 + temp1;
//         num = num / 10;
//     }
//     if (temp2 == num2)
//     {
//         return 1;
//     }  
//     return 0;
// }

// int isArmstrong(int num){

// int counter =0;
// int temp1 =num;
// int temp2 =num;

// int sum =0;

// while (temp1 != 0){
// counter++;
// temp1 = temp1/10;
// }

// temp1 = num;

// while (temp2 !=0) {
// temp1 = temp2%10;
// sum+= pow(temp1,counter);
// temp2 = temp2/10;

// }
// if (sum == num ){
//     return 1;
// }
// return 0;
// }
#include <stdio.h>
#include "NumClass.h"
#include <math.h>

int isPalindrome(int num)
{
    int temp = num;
    int word = 0;
    while (temp > 0)
    {
        word *= 10;
        word += temp % 10;
        temp /= 10;
    }
    if (word == num){
        return 1;
    }
    else
        return 0;
}

int isArmstrong(int num)
{
    int save = num;
    int counter = 0;
    while (num != 0)
    {
        counter++;
        num /= 10;
    }
    num = save;
    int sum = 0;
    while (num != 0)
    {
        int digit = num % 10;
        sum += pow(digit, counter);
        num /= 10;
    }
    if (save == sum)
    {
        return 1;
    }
    return 0;
}
