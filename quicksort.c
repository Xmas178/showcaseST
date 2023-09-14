/*Tämä ohjelma on toteutettu C-kielellä ja se suorittaa pikajärjestämisalgoritmin, joka tunnetaan nimellä "Quicksort". 
Ohjelma kysyy käyttäjältä viisi kokonaislukua ja tallentaa ne taulukkoon. Sen jälkeen se lajittelee taulukon pienimmästä 
suurimpaan käyttäen Quicksort-algoritmia. Käyttäjä näkee alkuperäisen taulukon ja järjestetyn taulukon tulosteina ohjelman 
suorituksen aikana. Ohjelma kysyy käyttäjältä 5 lukua jotka se järjestää pienimmästä suurimpaan. Lopuksi ohjelma tulostaa alkuperäisen
taulukon se järjestetyn uuden taulukon.

Koodissa on myös optimoitu toinen versio: se käyttää "insertion sort" -lajittelualgoritmia pienille taulukoille, 
mikä voi olla nopeampaa kuin Quicksort tietyissä tilanteissa.

Tämän lisäksi ohjelma sisältää kommentteja selventämään koodia ja parantamaan sen ymmärrettävyyttä. 14.09.23*/


#include <stdio.h>

// Vaihtaa kahden kokonaisluvun paikkaa taulukossa
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Valitsee jakoalkion (pivot) ja lajittelee taulukon. Jakoalkio (pivot) on taulukon alkio, 
jonka ympärille muut alkiot jaetaan siten, että pienemmät arvot siirtyvät sen 
vasemmalle puolelle ja suuremmat arvot sen oikealle puolelle.*/

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Käytetään viimeistä alkioita jakoalkiona
    int i = (low - 1);    // Indeksi pienemmälle osataulukolle

    for (int j = low; j <= high - 1; j++) {
        // Jos nykyinen alkio on pienempi tai yhtä suuri kuin jakoalkio
        if (arr[j] <= pivot) {
            i++; // Siirry seuraavaan pienempään alkioon
            swap(&arr[i], &arr[j]); // Vaihda paikkoja
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Rekursiivinen Quicksort-algoritmi
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Etsi jakoalkio
        int pi = partition(arr, low, high);

        // Lajittele vasen ja oikea osataulukko jakoalkion ympärillä
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Tulostaa taulukon
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[5]; // Taulukko, johon tallennetaan 5 numeroa

    printf("Syota 5 numeroa:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]); // Kysy käyttäjältä numeroita
    }

    printf("Taulukko ennen lajittelua: \n");
    printArray(arr, 5);

    quickSort(arr, 0, 4); // Lajittele taulukko

    printf("Taulukko QuickSortin jälkeen: \n");
    printArray(arr, 5);

    return 0;
}

/*

// Tässä on lisäyksenä Insertion sort -lajittelu joka optimoi prosessia pienille taulukoille

#include <stdio.h>

// Vaihtaa kahden kokonaisluvun paikkaa taulukossa
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Valitsee jakoalkion (pivot) ja lajittelee taulukon niin, että pienemmät ovat ennen ja suuremmat jälkeen

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Käytetään viimeistä alkioita jakoalkiona
    int i = (low - 1);    // Indeksi pienemmälle osataulukolle

    for (int j = low; j <= high - 1; j++) {
        // Jos nykyinen alkio on pienempi tai yhtä suuri kuin jakoalkio
        if (arr[j] <= pivot) {
            i++; // Siirry seuraavaan pienempään alkioon
            swap(&arr[i], &arr[j]); // Vaihda paikkoja
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Insertion sort -lajittelu pienille taulukoille
void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Rekursiivinen Quicksort-algoritmi
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        if (high - low + 1 <= 10) { // Esimerkki kynnysarvosta
            insertionSort(arr, low, high); // Käytä insertion sortia pienille taulukoille
            return;
        }
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Tulostaa taulukon
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[5]; // Taulukko, johon tallennetaan 5 numeroa

    printf("Syota 5 numeroa:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]); // Kysy käyttäjältä numeroita
    }

    printf("Taulukko ennen lajittelua: \n");
    printArray(arr, 5);

    quickSort(arr, 0, 4); // Lajittele taulukko

    printf("Taulukko QuickSortin jälkeen: \n");
    printArray(arr, 5);

    return 0;
}
*/