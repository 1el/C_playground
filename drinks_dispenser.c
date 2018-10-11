#include <stdio.h>

// ********** Constants
const int price [] = {120, 130, 150, 140};
const char drink [][7] = {{"Cola"},{"Fanta"},{"Sprite"},{"Wasser"}};
int numberOfDrinks = sizeof(drink)/sizeof(drink[0]);
const int cents [] = {200, 100, 50, 20, 10, 5};
int numberOfCoins = sizeof(cents)/sizeof(cents[0]);

// ********** Prototypes
void showMenu(void); // void is here optional
void scanChoice(int *);
int pay(int);
void returnCoins(int);

// ********** Main
int main()
{
    int selected;
    do {
        do {
            showMenu();
            scanChoice(&selected); // hier wird der Zeiger (die Adresse) als Parameter übergeben (call by reference)
        } while (selected < 0 || selected > numberOfDrinks);
        if (selected > 0 && selected <= numberOfDrinks) {
            printf("Sie haben %s gewaehlt. ", drink[selected-1]);

            int haveToPay = pay(price[selected-1]);
            if (haveToPay < 0) {
                returnCoins(-haveToPay);
            }

            printf("Ihre %s wird jetzt ausgegeben\n\n", drink[selected-1]);

        }
    } while (selected != 0);
    puts("\nTchuess!\n");
    return 0;
}


void showMenu() {
    int i;
    for(i = 0; i < numberOfDrinks; i++) {
        printf("%i. %s \t %i cent\n", i+1, drink[i], price[i]);
    }
    puts("\n0. Ende\n\n");
}

void scanChoice(int * selected){ // hier wird eine Adresse gewartet
    puts("Ihre Wahl: ");
    scanf("%i", selected); // Auswahl wird eingelesen und in die Adresse gespeichert
    if (*selected < 0 || *selected > numberOfDrinks){ // auswahl wird auf Richtigkeit geprueft (dabei um einen Wert zu erhalten brauchen wir * )
        puts("Falsche Eingabe! Probieren Sie es noch Mal\n\n");
    }
}

// ********** der Einwurf wird vom Preis abgezogen, bis den Preis bezahlt ist
int pay(int stillHaveToPay) {
    int inserted;
    int i = 0;
    int bingo = 0;
    do {
        printf("Zahlen Sie bitte %i cents\n\n", stillHaveToPay);
        scanf("%i", &inserted);
        i = 0;
        bingo = 0;
        do {
            if (inserted == cents[i]) {
            bingo = 1;
            }
            i++;
        } while (bingo == 0  && i < numberOfCoins);
        if (bingo == 0) {
            puts("ungueltige Muentze!");
            inserted = 0;
        }
        printf("\nSie haben %i cents eingeworfen\n\n", inserted);
        stillHaveToPay -= inserted;
    } while (stillHaveToPay > 0);
    return stillHaveToPay;
}

void returnCoins(int coins) {
    printf("Rueckgabe: %i cents\n\n", coins);
    puts("Sie erhalten...");
    int i;
    int x;
    for (i = 0; i < numberOfCoins; i++) {
        x = coins / cents[i];
        if (x != 0) {
            printf("%i Mal %i cents\n", x, cents[i]);
            coins %= cents[i];
        }
    }
    puts("...zurueck. \n");
}
