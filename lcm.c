#include <stdio.h>
int lcm(int num1,int num2,int num3,int num4);
int lcm2(int num1,int num2);

//Test the lcm
int main()
{
    int num1, num2, num3, num4; 
    num1 = 4; 
    num2 = 6;
    num3 = 12;
    num4 = 3; 
    
    int result = lcm(num1,num2,num3,0);    
    printf("mm = %i",result);

    return 0;
}

/*
Finds the lowest common multiple of 4 integers. If you only want to 
find the LCM of 3 or 2 numbers then pass two parameters as 0 or 1.
Depends on having a function present that calculates the LCM of 2 numbers.
Returns the lowest integer that is a multiple of all input ints. 
*/
int lcm(int num1,int num2,int num3,int num4)
 {  
     if(num1 == 0) num1 = 1;
     if(num2 == 0) num2 = 1;
     if(num3 == 0) num3 = 1;
     if(num4 == 0) num4 = 1;
     
    int mm1 = lcm2(num1,num2);
        printf("mm1 = %i",mm1);
    int mm2 = lcm2(num3,num4);
        printf("mm2 = %i",mm2);
    return lcm2(mm1,mm2); 
}

/*
Finds the lowest common multiple of two numbers.
Requires that num1 and num2 are not 0.
Returns the lowest integer that is a multiple of both input ints. 
*/
int lcm2(int num1,int num2)
{  
    int mm = (num1>num2) ? num1 : num2; 
    
    while(mm%num1 != 0 || mm%num2 != 0){
        mm++; 
    }
    
    return mm; 
}

