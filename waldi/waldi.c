#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

void setup() {
    setvbuf(stdin,0,2,0);
    setvbuf(stdout,0,2,0);
    puts(" #     #    #    #       ######  ### ");
    puts(" #  #  #   # #   #       #     #  #  ");
    puts(" #  #  #  #   #  #       #     #  #  ");
    puts(" #  #  # #     # #       #     #  #  ");
    puts(" #  #  # ####### #       #     #  #  ");
    puts(" #  #  # #     # #       #     #  #  ");
    puts("  ## ##  #     # ####### ######  ### ");
    puts("");
}

int test1();
int test2();
int test3();

void win() { system("cat /home/waldi/flag"); }

int main() {
    setup();
    puts("Welcome to Waldi's Basics in Education and Learning!");
    puts("You should pass all tests to get flag.");
    puts("");

    if(test1() && test2() && test3())
	win();
    else {
	puts("I HEAR MATH THAT BAD");
	exit(0);
    }

    return 0;
}

int test1() {
    int x, y;
    puts("[ --- test 1 --- ]");
    puts("Find x, y such that x*y == 0x1337.");
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);

    if(x < 0x1337 || y < 0x1337 || x*y != 0x1337)
	return 0;

    return puts("correct!\n");
}

int test2() {
    int x, y;
    puts("[ --- test 2 --- ]");
    puts("Find x, y such that x*y*y == x*x*y, x,y != 0, x != y.");
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);

    if(x == 0 || y == 0 || x == y || (x*y)*y != x*(x*y))
	return 0;

    return puts("correct!\n");
}

int test3() {
    int x, y;
    float fx, fy;
    puts("[ --- test 3 --- ]");
    puts("Find x, y such that x+y == 1337.1337.");
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);

    memcpy((char*)&fx, (char*)&x, 4);
    memcpy((char*)&fy, (char*)&y, 4);
    if(x < 1337 || y < 1337 || fabs(fx+fy - 1337.1337) > 0.1) {
	printf("%f\n", fx);
	printf("%f\n", fy);
	printf("%f\n", fx+fy);
	return 0;
    }

    return puts("correct!\n");
}
