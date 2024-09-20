#include "blackjack.h"
#include "utils.h"

#include <assert.h>
#include <stdlib.h>

static size_t card_value(Card card, bool soft_hand) {
    switch (card.rank) {
    case ACE:
        if (soft_hand) {
            return 11;
        }
        return 1;
    case TWO:
        return 2;
    case THREE:
        return 3;
    case FOUR:
        return 4;
    case FIVE:
        return 5;
    case SIX:
        return 6;
    case SEVEN:
        return 7;
    case EIGHT:
        return 8;
    case NINE:
        return 9;
    case TEN:
    case JACK:
    case QUEEN:
    case KING:
        return 10;
    }
    assert(0 && "Unreachable");
}

static inline Suite random_suite(void) {
    return HEARTS + (rand() % 4);
}

static inline Rank random_rank(void) {
    return ACE + (rand() % 13);
}

static bool card_exists(Deck *d, Card c) {
    for (size_t i = 0; i < d->size; i++) {
        Card it = d->cards[i];
        if (it.suite == c.suite && it.rank == c.rank) return true;
    }
    return false;
}

void reshuffle_deck(Deck *deck) {
    while (deck->size < MAX_DECK_SIZE) {
        Card c = {
            .suite = random_suite(),
            .rank = random_rank(),
        };
        if (!card_exists(deck, c)) {
            deck->cards[deck->size++] = c;
        }
    }
}

void draw_card(Player *player, Deck *deck) {
    assert(player && deck && "Player and deck must not be NULL");
    assert(deck->size != 0 && "Deck must have nonzero size");

    Card card = deck->cards[--deck->size];

    if (card.rank == ACE && !player->hand.first_ace_seen) {
        player->hand.first_ace_seen = true;
        player->hand.is_soft = true;
    }

    player->hand.value += card_value(card, player->hand.is_soft);

    if (player->hand.value > 21 && player->hand.is_soft) {
        player->hand.value -= 10;
        player->hand.is_soft = false;
    }

    player->hand.cards[player->hand.size++] = card;
}
