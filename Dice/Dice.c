#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll(int, int);
int main(){
    int n, m, sum;
    char num;
    do{
        printf("#######################################\n");
        printf("#              DICE ROLL              #\n");
        printf("#######################################\n");
        printf("Type the number of sides of the dice and the amout of times to repeat the roll (As in 2d8, for 2 8-sided dices): ");

        scanf("%dd%d", &n, &m); 
        printf("Chosen dice: d%d\nNumber of rolls: %d\n", n, m);

        sum = roll(n, m);
        
        printf("\nDo you want to do another roll? (Y/N): ");
        scanf(" %c", &num);

        while(num != 'N' && num != 'Y'){
            printf("Couldn't recognize the choice, type Y or N: ");
            scanf(" %c", &num);
        }

    }while(num != 'N');

    return 0;
}

int roll(int sides,int times){
    srand(time(NULL));
    int dice, sum;
    sum = 0;
    printf("Your roll(s): ");
    for(int i = 0; i < times; i++){
        dice = (rand() % (sides)) + 1;
        sum += dice;
        printf("%d ", dice);
    }
    printf("\n");
}
