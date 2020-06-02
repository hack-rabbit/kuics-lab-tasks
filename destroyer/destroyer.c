#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

uint64_t g_ret;
uint64_t g_name;
uint64_t g_crd = 5;

int8_t g_start = 0;

int setup(void) {
    setvbuf(stdin,0,2,0);
    setvbuf(stdout,0,2,0);
    setvbuf(stderr,0,2,0);
    srand(time(0));
    puts(" #####  ######  ####  ##### #####   ####  #   # ###### #####  ");
    puts(" #    # #      #        #   #    # #    #  # #  #      #    # ");
    puts(" #    # #####   ####    #   #    # #    #   #   #####  #    # ");
    puts(" #    # #           #   #   #####  #    #   #   #      #####  ");
    puts(" #    # #      #    #   #   #   #  #    #   #   #      #   #  ");
    puts(" #####  ######  ####    #   #    #  ####    #   ###### #    # ");
    return puts("");
}

void read_str(char *s, int len) {
    int i;
    char c;
    for(i = 0; i < len-1; i++) {
	c = getchar();
	if(c == '\x0' || c == '\n')
	    break;
	s[i] = c;
    }
    s[i] = '\0';
}

void jackpot(int *n) {
    int i = rand() % 4;
    switch(i) {
	case 1:
	    *n = '?'; break;
	case 2:
	    *n = '&'; break;
	case 3:
	    *n = '$'; break;
	default:
	    *n = '!'; break;
    }
}

int play(void) {
    int a;
    int b;
    int c;
    char *name;
    char buf[32];

    a = '?';
    b = '?';
    c = '?';

    name = g_name;
    while(g_crd) {
	printf("                RET DESTROYER - A SOUVENIR FOR %s                   \n", name);
	puts("");
	printf("           I have just DESTROYED the RET on your stack frame !!     \n");
	printf("     However, I have a copy in RAM, and I'm giving you a last chance\n");
	printf("                  to restore your previous data.                    \n");
	printf("  WARNING: IF YOU RESET NOW, ALL YOUR DATA WILL BE LOST - FOREVER !!\n");
	printf("               Your Data dependes on a game of JACKPOT              \n");
	puts("");
	printf("                   CASINO DE WALDE JACKPOT                          \n");
	puts("");
	printf("                     ╔═╗     ╔═╗     ╔═╗                            \n");
	printf("                     ╫%c╫     ╫%c╫     ╫%c╫                         \n", a, b, c);
	printf("                     ╚═╝     ╚═╝     ╚═╝                            \n");
	printf("                         CREDITS : %d                               \n", g_crd);
	puts("");
	puts("");
	printf("                     &&& = Your Data                                \n");
	printf("                     ??? = My Phone No.                             \n");
	puts("");
	puts("");
	printf("                     PRESS ENTER TO PLAY                            \n");
	puts("");

	if(g_start && a==b && b==c) {
	    puts("BASTARD ! You're lucky this time - what was your name again?");
	    read(0, name, 32);
	    return 1;
	}
	g_start = 1;

	read(0, buf, 48);

	printf("", &name, &buf);
	jackpot(&a);
	jackpot(&b);
	jackpot(&c);
	g_crd--;
    }
    // fail
    puts("HA HA !! You asshole, you`ve lost: say Bye to your Balls ...");
    return 0;
}

int main(void) {
    int n, result;

    // ret destroyer
    n = setup();
    g_ret = (uint64_t)*((uint64_t *)&n + 2);
    *((uint64_t *)&n + 2) = 0xFFFFFFFFFFFFFFFF;

    g_name = malloc(32);
    printf("Name: ");
    read_str(g_name, 32);
    printf("Welcome, %s\n\n", g_name);

    result = play();
    if(result) {
	puts("");
	puts("Well, surprise! No Fuckin' Chance!");
    }

    free(g_name);

    return 0;
}
