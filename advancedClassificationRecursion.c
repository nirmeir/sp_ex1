// #include <stdio.h>
// #include "NumClass.h"
// #include <math.h>
// int rev(int,int);
// int Rec(int,int,int);


// int rev(int n, int temp)
// {
//     if (n == 0)
//         return temp;
 
//     temp = (temp * 10) + (n % 10);
 
//     return rev(n / 10, temp);
// }
 

// int Rec (int num ,int counter , int sum){


// if (num >0 ){
// sum += pow(num%10,counter);
// return Rec((num/10),counter ,sum);

// }

// return sum;
// }



// int isArmstrong (int num){

// int temp = num;
// int counter=0;
// int sum = 0;

// while (temp!= 0){
// counter++;
// temp = temp/10;
// }

// if (num == Rec(num , counter , sum)){
//     return 1;
// }

// return 0;
// }


// int isPalindrome(int num){

//  int temp = 0;
//  int sum = 0;  

//  if (num < 0){
//      return 0;
//  }
//  else
//  sum = rev(num , temp);

// if (num == sum){
//     return 1;
// }
// return 0;
 
//  } 
 #include <stdio.h>
#include <math.h>
#include "NumClass.h"
int reverse(int,int);
int isArmstrongRec(int,int);

int isPalindrome(int num)
{
    int temp = reverse(num, 0);
    if (num == temp)
        return 1;
    else
        return 0;
}

int reverse(int num, int temp)
{
    if (num == 0)
        return temp;
    temp = (temp * 10) + (num % 10);
    return reverse(num / 10, temp);
}

int isArmstrong(int num)
{
    int sum = 0, count = 0, temp;
    temp = num;
    while (temp != 0)
    {
        count = count + 1;
        temp = temp / 10;
    }
    sum = isArmstrongRec(num, count);
    if (sum == num)
        return 1;
    else
        return 0;
}

int isArmstrongRec(int num, int count)
{
    int reminder, sum = 0;
    if (num > 0)
    {
        reminder = num % 10;
        sum = sum + pow(reminder, count);
        sum += isArmstrongRec(num / 10, count);
        return sum;
    }
    else
        return 0;
}

 

    
