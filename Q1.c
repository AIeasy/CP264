#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checker(char alp[],char inp){//my little helper function for checking if the element in the array

    bool ans = true;
    for(int i =0;i<100;i++){
        if (alp[i] == inp){
            ans = false;
        }
    }

  
    return ans;
}
void counter(){
    int count =0;//counting the times a char appeared
    char alpha[100];//the alphabet for checking
    char input[100];// users input
    for(int p = 0;p<100;p++){//remove all the/0s
        alpha[p]=' ';
    }
    printf("Enter a string: ");//getting input
    scanf("%s",&input);
    for(int o = strlen(input);o<100;o++){//remove all the /0s
        input[o]= ' ';
    }
    for(int x =0;x<100;x++){
        
        if(checker(alpha,input[x])==true){//caling my checker function to create the alphabet
            alpha[x]=input[x];
        }else{
            alpha[x]=' ';//remove all the nulls
        }
        
    }
    
    for (int y = 0;y<100;y++){
        for(int z =0;z<100;z++){
            if (alpha[y] == input[z]){//if the element in input apeaared in alpha then count++
                if(alpha[y]!=' '){
                    if(input[z]!=' '){
                        count++;
                    }
                }
                
            }
        }
        if(alpha[y]!=' ' && alpha[y]!=' '){
            printf("%c %d\n",alpha[y],count);//printing output
        }
        
        count=0;//clear count
    }
    
}

int main(int argc, char *argv[]) {
    

    printf("Start testing task1\n");//testing calculator
    counter();
    printf("Finished testing task1\n");//finished testing calculator
    
}

