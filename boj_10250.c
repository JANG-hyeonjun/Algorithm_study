#include<stdio.h>

int test_case;
int quotient;
int divide;
int floor1;
int room;
int number;
int main()
{
    int X,Y;
    scanf("%d",&test_case);
    for(int i =0; i < test_case; i++)
    {
        scanf("%d %d %d",&floor1,&room,&number);
        quotient = number / floor1;
        divide = number % floor1;
       if(divide == 0) {
           Y = floor1 * 100;
           X = quotient;
       }
       else{
           Y = divide * 100;
           X = quotient + 1;
       }
        printf("%d\n",Y+X);
    }

    return 0;
}
