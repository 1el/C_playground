/*
1. Tag 3. Aufgabe
Erstellen Sie folgendes Programm: ein Benutzer gibt eine vorzeichenlose Zahl ein
und das Programm gibt aus, an welchen Stelle die Bits gesetzt sind.
z.B. Zahl: 3  Bit gesetzt: 1. Stelle  Bit gesetzt: 2. Stelle 
*/
#include <stdio.h>

int main()
{
    unsigned int number;
    int divisor = 32768;
    int binarynumber [16];

    printf("Geben Sie den Zahl ein: ");
    scanf("%i", &number);

    int i;
    for (i = 0; i < sizeof(binarynumber)/sizeof(binarynumber[0]); i++) {
        binarynumber[i] = number / divisor;
        number %= divisor;
        divisor /= 2;
        printf("%i", binarynumber[i]);
    }
    return 0;
}
