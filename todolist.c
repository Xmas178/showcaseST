/*Tässä C-kielen to-do-lista-sovelluksessa käytetään tiedostoja tehtävien tallentamiseen. 
Tämä projekti ei sisällä tietokantaa, mutta tallentaa tehtävät tekstitiedostoon. Yksinkertainen ja
tekstipohjainen. Ei sisällä grafiikkaa.  140923 v1.0 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Määritellään vakioita tiedostonimen ja tehtävän maksimipituuden kanssa
#define FILENAME "tasks.txt"
#define MAX_TASK_LENGTH 100

// Tarkistaa, onko tiedosto olemassa. Jos tiedosto on jo olemassa ohjelma jatkaa sen tiedoston käyttöä.
int isFileExists(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

// Luo uuden tiedoston nimi määritelty tasks.txt tallentaa sen samaan polkuun mistä ohjelma käynnistetää. Muuttaminen mahdollista.
void createNewFile() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Virhe luotaessa tiedostoa");
        exit(1);
    }
    fclose(file);
}

// Funktio tehtävän lisäämiseksi
void addTask() {
    char task[MAX_TASK_LENGTH];
    printf("Syötä uusi tehtävä: ");
    getchar(); // Tyhjentää puskurin
    fgets(task, MAX_TASK_LENGTH, stdin);

    // Avataan tiedosto lisäystä varten
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Virhe avattaessa tiedostoa");
        return;
    }

    // Lisätään tehtävä tiedostoon
    fprintf(file, "%s", task);

    // Suljetaan tiedosto
    fclose(file);
}

// Funktio merkitsee tehtävän suoritetuksi ja poistaa sen listalta
void markAsDone(int taskNumber) {
    // Luetaan tehtävät tiedostosta
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Virhe avattaessa tiedostoa");
        return;
    }

    char tasks[MAX_TASK_LENGTH][MAX_TASK_LENGTH];
    int numTasks = 0;

    char line[MAX_TASK_LENGTH];
    while (fgets(line, MAX_TASK_LENGTH, file)) {
        numTasks++;
        if (numTasks == taskNumber) {
            // Merkitään tehtävä suoritetuksi poistamalla se
            continue;
        }
        strcpy(tasks[numTasks - 1], line);
    }

    // Suljetaan tiedosto
    fclose(file);

    // Avataan tiedosto uudelleen ylikirjoittamista varten
    file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Virhe avattaessa tiedostoa");
        return;
    }

    // Kirjoitetaan tehtävät takaisin tiedostoon
    for (int i = 0; i < numTasks - 1; i++) {
        fprintf(file, "%s", tasks[i]);
    }

    // Suljetaan tiedosto
    fclose(file);
}

// Funktio listaa kaikki tehtävät
void listTasks() {
    // Luetaan tehtävät tiedostosta
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Virhe avattaessa tiedostoa");
        return;
    }

    int lineNumber = 1;
    char line[MAX_TASK_LENGTH];
    printf("Tehtävät:\n");
    while (fgets(line, MAX_TASK_LENGTH, file)) {
        // Poista rivinvaihto tehtävän lopusta
        strtok(line, "\n");
        printf("%d. %s\n", lineNumber, line);
        lineNumber++;
    }

    // Suljetaan tiedosto
    fclose(file);
}

int main() {
    int choice;

    // Tarkista, onko tiedosto olemassa. Ohjelma sulkeutuu mikäli tiedostoa ei haluta luoda. Jo luodun tiedoston löytyessä
    // jatketaan automaattisesti siinä tiedostossa. Oli se tyhjä tai täynnä tehtäviä.
    if (!isFileExists(FILENAME)) {
        printf("Tiedostoa \"%s\" ei löytynyt. Luodaanko uusi tiedosto? (1 = Kyllä, 0 = Ei): ", FILENAME);
        scanf("%d", &choice);
        if (choice == 1) {
            createNewFile();
        } else {
            printf("Ohjelma päättyy.\n");
            return 0;
        }
    }
    // switch-case rakenne "käyttöliittymänä"
    printf("Tervetuloa to-do-lista-sovellukseen!\n");

    while (1) {
        printf("\nValitse toiminto:\n");
        printf("1. Lisää uusi tehtävä\n");
        printf("2. Merkitse tehtävä suoritetuksi\n");
        printf("3. Listaa tehtävät\n");
        printf("4. Poistu\n");
        printf("Valintasi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                listTasks();
                printf("Anna tehtävän numero, jonka haluat merkitä suoritetuksi: ");
                int taskNumber;
                scanf("%d", &taskNumber);
                markAsDone(taskNumber);
                break;
            case 3:
                listTasks();
                break;
            case 4:
                printf("Kiitos, näkemiin!\n");
                exit(0);
            default:
                printf("Virheellinen valinta. Yritä uudelleen.\n");
                break;
        }
    }

    return 0;
}
