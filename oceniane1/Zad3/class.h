#pragma once
#include <iostream>
#include <string>

class Card
{
public:
    enum Rank {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace, Joker};
    enum Suit {Clubs, Diamonds, Hearts, Spades, none};

private:
    Rank rank_;
    Suit suit_;
    std::string toString(Rank&);
    std::string toString(Suit&);

public:
    Card(Rank r = Ace, Suit s = Spades) : rank_(r), suit_(s) {};
    Rank getRank() {return rank_;}
    Suit getSuit() {return suit_;}
    std::string toString();
};

std::ostream& operator<<(std::ostream&, Card&);

class Deck
{
private:
    Card *deck_;
    int sz_;
    void swap(int, int);

public:
    Deck(int = 52);
    ~Deck() {delete [] deck_;}
    void shuffle();
    void display();
};
