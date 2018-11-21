#include <iostream>
#include <stdexcept>
#include <random>
#include "class.h"

//Card

std::string Card::toString(Rank& rank)
{
    switch (rank)
    {
        case Two:   return "2";
        case Three: return "3";
        case Four:  return "4";
        case Five:  return "5";
        case Six:   return "6";
        case Seven: return "7";
        case Eight: return "8";
        case Nine:  return "9";
        case Ten:   return "10";
        case Jack:  return "Jack";
        case Queen: return "Queen";
        case King:  return "King";
        case Ace:   return "Ace";
        case Joker: return "Joker";
        default: throw std::logic_error("Invalid Rank");
    }
}

std::string Card::toString(Suit& suit)
{
    switch (suit)
    {
        case Clubs:    return "Clubs";
        case Diamonds: return "Diamond";
        case Hearts:   return "Hearts";
        case Spades:   return "Spades";
        case none:     return "";
        default: throw std::logic_error("Invalid Suit");
    }
}

std::string Card::toString()
{
    if (rank_ == Joker)
        return ("[Joker]");
    else
        return ("[" + toString(rank_) + " of " + toString(suit_) + "]");
}

std::ostream& operator<<(std::ostream& out, Card& c)
{
    return out << c.toString();
}

// Deck

Deck::Deck(int sz)
{
    if (sz!=24 && sz!=52 && sz!=54)
        throw std::invalid_argument("Invalid number of cards in the deck");
    sz_ = sz;
    deck_ = new Card [sz_];
    int i = 0;
    if (sz_ == 24) {
        for (int s = Card::Clubs; s<=Card::Spades; ++s)
            for (int r = Card::Nine; r<=Card::Ace; ++r)
                deck_[i++] = Card((Card::Rank)r, (Card::Suit)s);
    } else if (sz_ == 52 || sz_ == 54) {
        for (int s = Card::Clubs; s<=Card::Spades; ++s)
            for (int r = Card::Two; r<=Card::Ace; ++r)
                deck_[i++] = Card((Card::Rank)r, (Card::Suit)s);
    }
    if (sz_ == 54){
        deck_[52] = Card(Card::Joker, Card::none);
        deck_[53] = Card(Card::Joker, Card::none);
    }
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, sz_-1);

    for (int i=0; i<1000; ++i)
        std::swap(deck_[distr(eng)], deck_[distr(eng)]);

}

void Deck::display()
{
    for (int i=1; i<=sz_; ++i)
        std::cout << "Card nr " << i << ": " << deck_[i-1] << '\n';
}
