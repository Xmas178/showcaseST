# showcaseST
Esimerkkiohjelmia

todolist.c

Tämä ohjelma on yksinkertainen C-kielellä toteutettu sovellus, johon voit lisätä hoidettavia tehtäviä ja helposti nähdä, mitä tehtäviä on vielä tekemättä. Voit myös merkitä tehtävät suoritetuiksi. Ohjelma ei sisällä tietokantaa, vaan se tallentaa tehtävät tekstitiedostoon. Päivämäärä: 14.09.2023

quicksort.c

Tämä ohjelma on toteutettu C-kielellä ja se suorittaa pikajärjestämisalgoritmin, joka tunnetaan nimellä "Quicksort". Ohjelma pyytää käyttäjää syöttämään viisi kokonaislukua ja tallentaa ne taulukkoon. Sen jälkeen se järjestää taulukon pienimmästä suurimpaan Quicksort-algoritmin avulla. Käyttäjä näkee alkuperäisen taulukon ja järjestetyn taulukon tulosteina ohjelman suorituksen aikana. Ohjelma pyytää käyttäjää antamaan viisi lukua, jotka se järjestää pienimmästä suurimpaan. Lopuksi ohjelma tulostaa alkuperäisen taulukon ja järjestetyn uuden taulukon.
Lisäksi koodissa on optimoitu toinen versio, joka käyttää "insertion sort" -lajittelualgoritmia pienille taulukoille. Tämä voi olla nopeampaa kuin Quicksort tietyissä tilanteissa.
Tämän lisäksi ohjelma sisältää kommentteja selventämään koodia ja parantamaan sen ymmärrettävyyttä. Päivämäärä: 14.09.23

blackjack.cpp

Tämä koodi sisältää tekstipohjaisen Blackjack-pelin. Ohjelma luo korttipakan, ja pelaaja aloittaa pelin. Tietokone toimii toisena pelaajana. Ohjelma sisältää ääkkösiä, joten tulostus voi olla vielä hieman keskeneräinen. Muuten ohjelma toimii normaalisti. Tämä ohjelma oli projektityö, joka valmistui 2000-luvun alussa Turun yliopiston Tietojenkäsittelytieteen laitoksella. Olin vastuussa funktioista korttipakan luomiseksi (void LuoKorttipakka), korttipakan sekoittamiseksi (void SekoitaKorttipakka) ja kortin nostamiseksi. Muut osat tehtiin yhdessä ryhmän kanssa. Koodi on siistitty ja testattu 14.09.23.


IN ENGLISH

todolist.c

This program is a simple C-language program that allows you to add tasks to be done and easily see what tasks are still pending. You can mark tasks as completed. The program does not include a database; instead, it creates a text file to store the tasks. Date: 14th September 2023.
quicksort.c

quicksort.c

This program is implemented in C and performs the QuickSort algorithm. It prompts the user to input five integers, stores them in an array, and then sorts the array from smallest to largest using the QuickSort algorithm. The user can see the original array and the sorted array as outputs during program execution. The program asks the user for five numbers, which it sorts from smallest to largest. Finally, the program prints the original array and the newly sorted array.
Additionally, the code includes an optimized version that uses the "insertion sort" sorting algorithm for small arrays, which can be faster than QuickSort in certain situations.
The program also contains comments to clarify the code and improve its comprehensibility. Date: 14th September 2023.
blackjack.cpp

blackjack.cpp

This code contains a text-based Blackjack game. The program creates a deck of cards, and the player plays first, followed by the computer. The program includes special characters (ä,ö), so the output may be somewhat incomplete in terms of formatting. However, the program functions otherwise. This program was a project completed in the early 2000s at the Department of Computer Science at the University of Turku. The functions for creating a card deck (void CreateCardDeck), shuffling the card deck (void ShuffleCardDeck), and drawing a card were implemented by me, while other parts were done collaboratively with the group. The code has been cleaned up and tested as of 14th September 2023.

