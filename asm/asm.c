#include <stdio.h>
#include <unistd.h>
#include <seccomp.h>

char shellcode[128];

void banner() {
    puts("    #     #####  #     # ");
    puts("   # #   #     # ##   ## ");
    puts("  #   #  #       # # # # ");
    puts(" #     #  #####  #  #  # ");
    puts(" #######       # #     # ");
    puts(" #     # #     # #     # ");
    puts(" #     #  #####  #     # ");
    puts("");
}

int main() {
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);

    scmp_filter_ctx ctx;
    ctx = seccomp_init(SCMP_ACT_KILL);

    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sigreturn), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(open), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(read), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0);
    seccomp_load(ctx);

    banner();

    puts("Can you make a shellcode reading /home/asm/flag?");
    puts("");
    printf("shellcode: ");

    read(0, shellcode, 128);

    ((void(*)(void))shellcode)();

    return 0;
}
