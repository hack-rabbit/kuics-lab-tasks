#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void banner() {
    puts("  ####  #    #  ####  #####  ####  #    # #    # ");
    puts(" #      #    # #    #   #   #    # #    # ##   # ");
    puts("  ####  ###### #    #   #   #      #    # # #  # ");
    puts("      # #    # #    #   #   #  ### #    # #  # # ");
    puts(" #    # #    # #    #   #   #    # #    # #   ## ");
    puts("  ####  #    #  ####    #    ####   ####  #    # ");
    puts("");
}

int main() {
    int pow;
    char name[32];
    
    setvbuf(stdin,0,2,0);
    setvbuf(stdout,0,2,0);
    srand(time(0));
    pow = rand() % 1000;

    banner();
    puts("After all, power is the true justice.");
    puts("Therefore, only man who are strong enough to break their keyboard \nwill obtain his flag!");
    puts("");
    puts("Brave volunteer, what is your name?");
    fgets(name, 36, stdin);
    puts("\nGood. I will count three... then punch the ENTER key with all strength!");
    sleep(1);
    puts("3...");
    sleep(1);
    puts("2...");
    sleep(1);
    puts("1...");
    sleep(1);
    puts("PUNCH!");
    getchar();

    printf("Let\'s see... your power was %d!\n", pow);
    if(pow >= 1000) {
        puts("Amazing!! you deserve what you want.\n");
	system("cat /home/shotgun/flag");
    }
    else {
        puts("No... you are too weak.");
    }

    return 0;
}
