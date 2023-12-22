#include <stdio.h>
#include <math.h>
#include <windows.h>

int obliczNWD(int a, int b);
void redukujUlamek(int *licznik, int *mianownik);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int licznik, mianownik;

    while (1) {
        printf("Podaj licznik ułamka: ");
        if (scanf("%d", &licznik) != 1) {
            printf("Niepoprawne dane!\n");
            while (getchar() != '\n');
            continue;
        }
        printf("Podaj mianownik ułamka: ");
        if (scanf("%d", &mianownik) != 1 || mianownik == 0) {
            printf("Niepoprawne dane!\n");
            while (getchar() != '\n');
            continue;
        }

        redukujUlamek(&licznik, &mianownik);

        printf("Postać zredukowana: %d/%d\n", licznik, mianownik);
    }

    return 0;
}

int obliczNWD(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void redukujUlamek(int *licznik, int *mianownik) {
    if (*mianownik != 0) {
        int nwd = obliczNWD(*licznik, *mianownik);

        *licznik /= nwd;
        *mianownik /= nwd;

        if (*mianownik < 0) {
            *licznik *= -1;
            *mianownik *= -1;
        }
    }
}
