#include <iostream>
#include <ctime>

using namespace std;

struct Suit
{
    string name;
    int value;
};

struct Rank
{
    string name;
    int value;
};

struct Card
{
    Suit suit;
    Rank rank;
    bool isFaceUp;
};

int main()
{

    srand(time(0));

    const int suitSize = 4;
    const int rankSize = 13;

    const Suit suits[suitSize] = {
        {"hearts", 1},
        {"diamonds", 2},
        {"clubs", 3},
        {"spades", 4}};
    const Rank ranks[rankSize] = {
        {"ace", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
        {"ten", 10},
        {"jack", 11},
        {"queen", 12},
        {"king", 13},
    };

    Card deck[rankSize * suitSize];

    for (int i = 0; i < 52; i++)
    {
        Card tempCard = {suits[i / 13], ranks[i % 13], true};
        deck[i] = tempCard;
    }

    Card hand[5];
    for (int i = 0; i < 5; i++)
    {
        hand[i].suit = suits[rand() % 3];
        hand[i].rank = ranks[rand() % 3];
        hand[i].isFaceUp = rand() % 1;

    }

    for (Card card : hand)
    {
        cout << card.rank.name << " of " << card.suit.name << endl;
    }

    return 0;
}