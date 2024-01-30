// Code by James Cowley, plz come see me if you have any questions
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Card structure
class Card {
    public:

        enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
        enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

        Suit suit;
        Rank rank;

        // Constructor
        Card(Suit s, Rank r) : suit(s), rank(r) {}

        // Get value of the card
        int getValue() const {
            if (rank >= TWO && rank <= TEN)
                return rank;
            else if (rank >= JACK && rank <= KING)
                return 10;
            else
                return 11; // Ace
        }
};

// Deck class
class Deck {
private:
    vector<Card> cards;

public:
    // Constructor
    Deck() {
        for (int s = Card::CLUBS; s <= Card::SPADES; ++s) {
            for (int r = Card::ACE; r <= Card::KING; ++r) {
                cards.push_back(Card(static_cast<Card::Suit>(s), static_cast<Card::Rank>(r)));
            }
        }
        shuffle();
    }

    // Shuffle the deck
    void shuffle() {
        srand(time(0));
        random_shuffle(cards.begin(), cards.end());
    }

    // Deal a card
    Card dealCard() {
        Card c = cards.back();
        cards.pop_back();
        return c;
    }
};

// Player class
class Hand {
protected:
    vector<Card> hand;
public:
    // Add a card to player's hand
    void addCard(const Card& card) {
        hand.push_back(card);
    }

    // Clear player's hand
    void clearHand() {
        hand.clear();
    }

    // Get player's hand value
    int getHandValue() const {
        int value = 0;
        int numAces = 0;

        for (const auto& card : hand) {
            value += card.getValue();
            if (card.getValue() == 11)
                numAces++;
        }

        while (value > 21 && numAces > 0) {
            value -= 10;
            numAces--;
        }

        return value;
    }

    // Display player's hand
    void showHand() const {
        for (const auto& card : hand) {
            cout << "[" << card.rank << " of " << card.suit << "] ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    Deck deck;
    Hand player, dealer;

    // Initial deal
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());

    // Display hands
    cout << "Player's Hand:\n";
    player.showHand();
    cout << "Dealer's Hand:\n";
    dealer.showHand();

    // Game logic goes here...

    return 0;
}
