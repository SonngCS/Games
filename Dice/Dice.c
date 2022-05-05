#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll(int, int);
int main(){
    int n, m;
    char num;
    do{
        printf("#######################################\n");
        printf("#              DICE ROLL              #\n");
        printf("#######################################\n");
        printf("Type the number of sides of the dice and the amout of times to repeat the roll (one space between the two numbers): ");

        scanf("%d %d", &n, &m); 
        printf("Chosen dice: d%d\nNumber of rolls: %d\n", n, m);

        roll(n, m);
        
        printf("\nDo you want to do another roll? (Y/N): ");
        scanf(" %c", &num);

        while(num != 'N' && num != 'Y'){
            printf("Couldn't recognize the choice, type Y or N: ");
            scanf(" %c", &num);
        }

    }while(num != 'N');

    return 0;
}

void roll(int sides,int times){
    srand(time(NULL));
    int dice;
    printf("Your roll(s): ");
    for(int i = 0; i < times; i++){
        dice = (rand() % (sides)) + 1;
        printf("%d ", dice);
    }
    printf("\n");
}