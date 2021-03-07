#include<stdio.h>

void move(int n, char source, char spare, char d);
int main(){
    //Your code here
    int n;
    char source, spare , d ;

    printf("Enter the source bar: ");
    scanf("%c %c", &source, &d);

    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    if(source == 'A' && d == 'C'){
        spare = 'B';
    }
    else{
        if(source == 'B' && d == 'C'){
            spare = 'A';
        }
        else{
            if(source == 'C' && d == 'A'){
                spare = 'B';
            }
            else{ 
                if(source == 'C' && d == 'B'){
                    spare = 'A';
                }
                else{
                    if(source == 'A' && d == 'B'){
                        spare = 'C';
                    }
                    else{
                        if(source == 'B' && d == 'A'){
                         spare = 'C';
                        }
                        else{
                            printf("INVALID COMBINATION");
                            return 0;
                        }
                    }
                }
            }
        }
    }

    move(n, source, spare, d);                   

    return 0;
}

void move(int n, char source, char spare, char d){

    if(n == 1)
        printf("\n Move from %c to %c", source, d);
    else{

        move(n-1, source, d, spare);
        move(1, source, spare, d);
        move(n-1, spare, source, d);
    }    
}