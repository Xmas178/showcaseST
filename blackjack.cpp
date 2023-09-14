//Tämä koodi sisältää tekstipohjaisen Blackjack-pelin, ohjelma tekee korttipakan, pelaaja pelaa ensin. Tietokone toisena.
//ohjelma sisältää ääkkösiä joten tulostus on vielä vähän keskeneräinen. Mutta ohjema toimii muuten.  Ohjelman on 
//projektityö mikä valmistui 2000-luvun alussa Turun yliopiston Tietojenkäsittelytieteen laitoksella. 
//Minä tein funktiot korttipakan luomiseksi (void LuoKorttipakka),funktion korttipakan sekoittamiseksi (void SekoitaKorttipakka)
// ja funktion kortin nostamiseksi. 
//Muut osat teimme yhdessä ryhmän kanssa. Koodi siistitty ja testattu 140923 ST.

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>

// Kortin rakenne
struct Kortti {
    std::string maa;
    std::string arvo;
    int arvopisteet;
};

// Pelin tilan rakenne
struct PeliTila {
    std::vector<Kortti> korttipakka;
    std::vector<Kortti> pelaajanKasi;
    std::vector<Kortti> tietokoneenKasi;
    int pelaajanPisteet = 0;
    int tietokoneenPisteet = 0;
};

// Funktio korttipakan luomiseksi
void LuoKorttipakka(PeliTila& tila) {
    std::string maat[] = { "hertta", "ruutu", "pata", "risti" };
    std::string arvot[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "jätkä", "kuningatar", "kunkku", "ässä" };

    // Alla oleva rivi määrittää kortin arvopisteet pelissä.
    // Jos kortti on ässä, sille annetaan 11 pistettä, muuten 10 pistettä,
    // paitsi jos kortti on kuningatar, kuningas tai jätkä, niille annetaan myös 10 pistettä.
    for (const std::string& maa : maat) {
        for (const std::string& arvo : arvot) {
            int arvopisteet = (arvo == "ässä") ? 11 : (arvo == "kunkku" || arvo == "kuningatar" || arvo == "jätkä") ? 10 : std::stoi(arvo);
            tila.korttipakka.push_back({ maa, arvo, arvopisteet });
        }
    }
}

// Funktio korttipakan sekoittamiseksi
void SekoitaKorttipakka(PeliTila& tila) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(tila.korttipakka.begin(), tila.korttipakka.end(), g);
}

// Funktio kortin nostamiseksi
Kortti NostaKortti(PeliTila& tila) {
    Kortti kortti = tila.korttipakka.back();
    tila.korttipakka.pop_back();
    return kortti;
}

// Funktio kortin lisäämiseksi pelaajan tai tietokoneen käteen
void LisaaKorttiKasiin(PeliTila& tila, std::vector<Kortti>& kasi, Kortti kortti) {
    kasi.push_back(kortti);
}

// Pelaajan vuoro
void PelaajanVuoro(PeliTila& tila) {
    char valinta;
    do {
        Kortti kortti = NostaKortti(tila);
        LisaaKorttiKasiin(tila, tila.pelaajanKasi, kortti);

        tila.pelaajanPisteet += kortti.arvopisteet;

        if (tila.pelaajanPisteet > 21) {
            std::cout << "Pelaaja hävisi! Pistemäärä: " << tila.pelaajanPisteet << std::endl;
            return;
        }

        std::cout << "Pelaajan käsi: ";
        for (const Kortti& k : tila.pelaajanKasi) {
            std::cout << k.maa << " " << k.arvo << ", ";
        }
        std::cout << "Pisteet: " << tila.pelaajanPisteet << std::endl;

        std::cout << "Haluatko nostaa lisää kortteja? (K/E): ";
        std::cin >> valinta;
    } while (valinta == 'K' || valinta == 'k');
}

// Tietokoneen vuoro
void TietokoneenVuoro(PeliTila& tila) {
    while (tila.tietokoneenPisteet < 17) {
        Kortti kortti = NostaKortti(tila);
        LisaaKorttiKasiin(tila, tila.tietokoneenKasi, kortti);
        tila.tietokoneenPisteet += kortti.arvopisteet;
    }

    std::cout << "Tietokoneen käsi: ";
    for (const Kortti& k : tila.tietokoneenKasi) {
        std::cout << k.maa << " " << k.arvo << ", ";
    }
    std::cout << "Pisteet: " << tila.tietokoneenPisteet << std::endl;
}

int main() {
    PeliTila peliTila;

    LuoKorttipakka(peliTila);
    SekoitaKorttipakka(peliTila);

    PelaajanVuoro(peliTila);
    if (peliTila.pelaajanPisteet <= 21) {
        TietokoneenVuoro(peliTila);

        if (peliTila.tietokoneenPisteet > 21 || peliTila.pelaajanPisteet > peliTila.tietokoneenPisteet) {
            std::cout << "Pelaaja voitti!" << std::endl;
        } else if (peliTila.pelaajanPisteet == peliTila.tietokoneenPisteet) {
            std::cout << "Tasapeli!" << std::endl;
        } else {
            std::cout << "Tietokone voitti!" << std::endl;
        }
    }

    return 0;
}
