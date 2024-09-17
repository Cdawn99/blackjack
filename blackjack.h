#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#include <stdbool.h>
#include <stddef.h>

#define MAX_DECK_SIZE 52

typedef enum {
    HEARTS = 0,
    DIAMONDS,
    CLUBS,
    SPADES,
} Suite;

typedef enum {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
} Rank;

typedef struct {
    Suite suite;
    Rank rank;
} Card;

size_t card_value(Card card, bool soft_hand);

typedef struct {
    size_t size;
    Card cards[MAX_DECK_SIZE];
} Deck;

void reshuffle_deck(Deck *deck);

typedef struct {
    Card *items;
    size_t length;
    size_t capacity;

    int value;
    bool is_soft;
    bool first_ace_seen;
} Hand;

typedef int Chips;

typedef struct {
    Hand hand;
    Chips chips;
} Player;

void draw_card(Player *player, Deck *deck);
void free_player_hand(Player *player);

#endif // BLACKJACK_H_
