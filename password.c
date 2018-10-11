/*
Tag 8
Erstellen Sie schrittweise ein Programm,
das einen Benutzernamen und ein Passwort abfragt,
verschlüsselt, speichert und überprüft.
*/

#include <stdio.h>
#include <stdlib.h>

void gen_key(char *, int);
void create_account(char *, char *);
void encrypt(char *, char *);
void save_to_file(char *, char *);
void login_input(char *, char *);
int check(char *, char *);

int main()
{
    char user[10]; // Login-Name kann max 10 Zeichen enthalten
    char pass[9]; // Passwort kann max 8 zeichen enthalten
    char key[9]; // Schluessel fuer XOR-Verschluesselung
    int key_len = sizeof(key)/sizeof(char);
    char input_user[10];
    char input_pass[9];
    int user_correct;
    int pass_correct;

    gen_key(key, key_len);

    create_account(user, pass);

    printf("\nuser: %s, clear text password: %s", user, pass);

    encrypt(pass, key);

    printf("\nuser: %s, encrypted password: %s", user, pass);

    save_to_file(user, pass);

    do {
        login_input(input_user, input_pass);

        encrypt(input_pass, key);

        user_correct = check(user, input_user);
        pass_correct = check(pass, input_pass);
        if (user_correct == 1 && pass_correct == 1) {
            printf("access allowed\n");
        } else {
            printf("access denied\n");
        }
    } while (user_correct == 0 || pass_correct == 0);

    return 0;
}

void gen_key(char * key_poi, int l) {
    int i = key_poi + l - 1;
    for ( ; key_poi < i; key_poi++) {
        *key_poi = rand() % 127; // generiert ein ASCII-Wert (127 bedeutet der Anzahl der mögliche ASCII Werte) eigentlich 128
    }
    *key_poi = '\0'; // setzte der letze Wert in dem Array auf NULL
}

void create_account(char *user_poi, char *pass_poi) {
    puts("\n*** create an account ***");
    printf("user: ");
    scanf("%s", user_poi);
    printf("password: ");
    scanf("%s", pass_poi);
}

void encrypt(char * pass_poi, char * key_poi) {
    for ( ; *pass_poi != '\0'; pass_poi++, key_poi++) {
        *pass_poi = *pass_poi ^ *key_poi;
    }
}

void save_to_file(char *user_poi, char *pass_poi) {
    FILE *doc;
    doc = fopen("pass_liste.dat", "w"); // spaeter a
    fprintf(doc, "\n");
    for ( ; *user_poi != '\0'; user_poi++) {
        fprintf(doc, "%c", *user_poi);
    }
    fprintf(doc, "\n");
    for ( ; *pass_poi != '\0'; pass_poi++) {
        fprintf(doc, "%c", *pass_poi);
    }
}

void login_input(char *input_user_poi, char *input_pass_poi) {
    puts("\n\n*** login ***");
    printf("user: ");
    scanf("%s", input_user_poi);
    printf("password: ");
    scanf("%s", input_pass_poi);
}

int check(char *saved_poi, char *input_poi) {
    int i;
    int gleich = 1;
    int l = strlen(saved_poi);
    for(i = 0; (gleich == 1 && i < l); saved_poi++, input_poi++, i++ ) {
        if (*saved_poi != *input_poi) {
            gleich = 0;
            printf("user name or password is wrong\n");
        }
    }
    return gleich;
}
