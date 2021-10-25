#include <stdio.h>
#include <stdlib.h>

void msg() {
    printf("Welcome to Diceney!\n");
    printf("Diceney is live today, you only need to guess 20 times to get flag.txt\n");
}
void init() {

    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    alarm(30);
}
int menu() {
    char* file;
    FILE *f;
    int space;
    int seed;
    int guess;
    int win = 0;
    file = "/dev/urandom";
    int input = 0;
    for (int i = 0; i < 30; ++i) {
        printf("Round: %d\n",i+1);
        if (win == 15) {
            printf("Hurry up! you will Win!!!\n");
        }
        printf("Your first guess: ");
        scanf("%d", &input);
        f = fopen(file,"r");
        fread(&seed, 4, 1, f);
        srand((unsigned int) seed);
        *(&input + i%4) = input;
        guess = rand() % 1553;
        printf("My turn to say: %d\n",guess);

        if (input == guess) {
            prsintf("You are really lucky\n");
            win++;
        }else {
            printf("No! maybe you haven't found the trick\n");
        }
        if (win == 20) {
            printf("Great!!! You win\n");
            system("/bin/sh");
            return 0;
        }

        printf("(%d/20) games to win!\n", win);
        fclose(f);
    }

    return 0;
}
int main() {
    init();
    msg();
    menu();
    return 0;
}

