#include <stdio.h>
#include <windows.h>

void convertToBin(unsigned long n);

int main(int argc, char *argv[]) {
    unsigned int n;
    SetConsoleOutputCP(CP_UTF8);
    system("cls");
    printf("\nPodaj liczbę całkowitą (nie-cyfra - kończy program): ");

    while (scanf("%ld", &n) == 1)
    {
        printf("Reprezentacja dwójkowa: ");
        convertToBin(n);
        putchar('\n');
        printf("\nPodaj liczbę całkowitą (!cyfra - kończy program): ");
    }

    puts("\nTo już koniec...");
    fflush(stdin);
    getchar();
    return 0;
}

void convertToBin(unsigned long n) {
    if (n > 1) {
        convertToBin(n / 2);
    }
    putchar('0' + n % 2);
}
