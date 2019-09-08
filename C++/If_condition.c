#include<stdio.h>
#include<stdlib.h>

int main(){

    int age = 0, a = 0;
    int count = 5;

    while(a < count){

        printf("Please enter the age: ");
        scanf("%d", &age);    //address of value
                          //store input value into memory address of var age
        if(age > 18){
            printf("The age is greater than 18");
        }
        if(age == 18){
            printf("The age is equal to 18");
        }
        else if(age < 18) printf("The age is less than 18");

        printf("\n");
        a++;    //do not forget to increment, otherwise given the condition, the loop would be evaluated to true
    }

    return 0;
}
