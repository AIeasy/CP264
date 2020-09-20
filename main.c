#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void calculator(){
    int a;//fist value
    int b;//second value
    double da;//double version for 1st value
    double db;// double version for 2nd value
    printf("Enter the first number: ");
    scanf("%d",&a);//get 1st input and give it to the variable a
    da= (double)a;//get the double version of it
    printf("Enter the second nubmer: ");
    scanf("%d",&b);//get 2nd input and give it to the variable b
    db=(double)b;//get the double version of it
    printf("%d + %d = %d\n",a,b,a+b);//do the calculation and print it
    printf("%d - %d = %d\n",a,b,a-b);
    printf("%d x %d = %d\n",a,b,a*b);
    printf("%d / %d = %d (Interger Division)\n",a,b,a/b);
    printf("%d % %d = %d (Modulo Division)\n",a,b,a%b);
    printf("%d + %d = %.2f (Normal Division)\n",a,b,da/db);//using double version so we can get the normal divisoin

    return ;
}
void typechecker(){
    char input[100]="";//create the string 
    printf("Enter any character: ");
    scanf("%s",&input);//get the input string and give it to string input
    if (strlen(input)!=1){//if it is a string input
        printf("Please make sure only enter 1 character\n");
    }else if(isalpha(input[0])!=0){//check if the input char is character or not
        if(isupper(input[0])){//check is upper?
            printf("Upper case character was entered\n");
        }else{//if not upper then lower
            printf("Lower case character was entered\n");
        }
    
    }else{//error handling user should only enter 1 char
        printf("Please make sure enter character\n");
    }
    return;


}
int main(int argc, char *argv[]) {
    

    printf("Start testing task1\n");//testing calculator
    calculator();
    printf("Finished testing task1\n");//finished testing calculator
    printf("Start testing task2\n");//testing typechecker
    typechecker();
    printf("Finished testing task2\n"); //finished testing typechecker
}


	