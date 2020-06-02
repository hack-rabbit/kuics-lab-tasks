#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX     100
#define ROUND   1000

int arr[MAX];

void banner() {
    puts(" #####  #        ##    ####  #    #      #   ##    ####  #    # ");
    puts(" #    # #       #  #  #    # #   #       #  #  #  #    # #   #  ");
    puts(" #####  #      #    # #      ####        # #    # #      ####   ");
    puts(" #    # #      ###### #      #  #        # ###### #      #  #   ");
    puts(" #    # #      #    # #    # #   #  #    # #    # #    # #   #  ");
    puts(" #####  ###### #    #  ####  #    #  ####  #    #  ####  #    # ");
    puts("");
}

int solver(int n, int m) {
    int i, j, k, sum, ans;
    ans = 0;
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            for(k = j+1; k < n; k++) {
                sum = arr[i] + arr[j] + arr[k];
                if(sum <= m && sum > ans)
                    ans = sum;
            }
        }
    }
    return ans;
}

int main() {
    int n, m, round, ans, input, i, j;
    int fd;
    int state;
    struct  timeval tv;
    fd_set  readfds, writefds;

    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);

    fd = fileno(stdin);
    FD_ZERO(&readfds);

    banner();
    puts("Blackjack is a popular card game in casino.");
    puts("Players have to pick 3 cards whose sum is not bigger than 21,");
    puts("but very close to.");
    puts("");
    puts("In this challenge, a number M and the card set is given.");
    puts("Your objective is to find the sum of 3 cards which is closest to the number M."); 
    puts("Like blackjack, the sum should not exceed M.");
    puts("");
    puts("[ Example ]");
    puts("21");
    puts("5 6 7 8 9");
    puts("answer: 21");
    puts("");
    puts("The flag will be given when you make 1000 consecutive win!");
    puts("");

    srand(time(0));
    for(round = 1; round <= ROUND; round++) {
        FD_SET(fd, &readfds);
        tv.tv_sec = 3;
        tv.tv_usec = 0;
        n = rand()%10 + 30;
        m = rand()%5000 + 1000;
        for(i = 0; i < n; i++)
            arr[i] = 0;
        for(i = 0; i < n; i++) {
            if((i % (n/3)) == 0)
                arr[i] = rand() % ((m-50)/3) + 200;
            else
                arr[i] = rand() % (m/4) + 100;
        }

        printf("[ Round %d ]\n%d\n", round, m);
        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

        ans = solver(n, m);
        state = select(fd+1, &readfds, (fd_set*)0, (fd_set*)0, &tv);
        switch(state) {
            case -1:
                printf("Error.\n");
                exit(0);
                break;
            case 0:
                printf("Timeout!\n");
                close(fd);
                exit(0);
                break;
            default:
                scanf("%d", &input);
                break;
        }

        if(ans == input) {
            puts("");
            puts("You win!");
            puts("");
        }
        else {
            puts("");
            puts("You lose...ToT");
            exit(0);
        }
    }

    puts("Wait..wait.. this can\'t be true!");
    system("cat /home/blackjack/flag");

    return 0;
}
