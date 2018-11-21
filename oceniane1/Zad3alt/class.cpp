#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "class.h"

//Card

const std::string Card::toString()
{
    if (rank_ == 13)
        return "Joker";
    return ranks_[rank_] + " of " + suits_[suit_];
}

// Deck

Deck::Deck(int sz)
{
    srand(time(0));
    if (sz!=24 && sz!=52 && sz!=54)
        throw std::invalid_argument("Invalid number of cards in the deck");
    sz_ = sz;
    deck_ = new Card [sz_];
    int i = 0;
    if (sz_ == 24) {
        for (int s=0; s<4; ++s)
            for (int r=7; r<13; ++r)
                deck_[i++] = Card(r, s);
    } else if (sz_ == 52 || sz_ == 54) {
        for (int s=0; s<4; ++s)
            for (int r=0; r<13; ++r)
                deck_[i++] = Card(r, s);
    }
    if (sz_ == 54){
        deck_[52] = Card(13, 0);
        deck_[53] = Card(13, 1);
    }
}

void Deck::shuffle()
{
    for (int i=0; i<1000; ++i)
        std::swap(deck_[rand()%sz_], deck_[rand()%sz_]);
}

void Deck::display()
{
    for (int i=1; i<=sz_; ++i)
        std::cout << "Card nr " << i << ": " << deck_[i-1].toString() << '\n';
}
