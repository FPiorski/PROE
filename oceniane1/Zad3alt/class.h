#pragma once
#include <iostream>
#include <string>

const std::string ranks_[13] {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
const std::string suits_[4]  {"Clubs", "Diamonds", "Hearts", "Spades"};

class Card
{
private:
    int rank_;
    int suit_;

public:
    Card(int r = 0, int s = 0) : rank_(r), suit_(s) {};
    int getRank() {return rank_;}
    int getSuit() {return suit_;}
    const std::string toString();
};

class Deck
{
private:
    Card *deck_;
    int sz_;

public:
    Deck(int = 52);
    ~Deck() {delete [] deck_;}
    void shuffle();
    void display();
};
