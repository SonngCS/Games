#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll(int, int);

int main(){
    int n, m, sum;
    char num;
    do{
        printf("#######################################\n");
        printf("#              DICE ROLL              #\n");
        printf("#######################################\n");
        printf("Hello, adventurer! It's time to roll the dice! (you may roll by typing the number of rolls, 'd', and the type of die, as in '2d8')\n");

        scanf("%dd%d", &m, &n); 
        printf("Chosen dice: d%d\nNumber of rolls: %d\n", n, m);

        roll(n, m);
        
        printf("\nDo you want to roll again? (Y or y for 'yes' or any key to end the program): ");
        scanf(" %c", &num);

    }while(num = 'Y' && num != 'y');

    return 0;
}

void roll(int sides,int times){
    srand(time(NULL));
    int dice, sum;
    sum = 0;
    printf("Your roll(s): ");
    for(int i = 0; i < times; i++){
        dice = (rand() % (sides)) + 1;
        sum += dice;
        printf("%d ", dice);
    }
    printf("\nSum: %d\n", sum);
}
