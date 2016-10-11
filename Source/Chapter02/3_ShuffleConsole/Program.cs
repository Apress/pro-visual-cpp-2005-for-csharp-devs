using System;
namespace CSharp
{
    public class Deck
    {
        uint[] Cards;
        Random randomGenerator;
        public enum Suit
        {
            Clubs = 0, Diamonds, Hearts, Spades
        }
        public enum Card
        {
            Ace = 0, Deuce, Trey, Four, Five, Six, Seven,
            Eight, Nine, Ten, Jack, Queen, King
        }
        Deck()
        {
            randomGenerator = new Random();
            Cards = new uint[52];
            for (uint u = 0; u < 52; ++u)
            {
                Cards[u] = u;
            }
        }
        void Swap(ref uint u, ref uint v)
        {
            uint tmp;
            tmp = u;
            u = v;
            v = tmp;
        }
        void Shuffle()
        {
            for (uint u = 52; u > 0; --u)
            {
                Swap(ref Cards[u - 1], ref Cards[RandomCard(u)]);
            }
        }
        uint RandomCard(uint Max)
        {
            return (uint)((double)Max * randomGenerator.NextDouble());
        }
        string CardToString(uint u)
        {
            Suit s = (Suit)(Cards[u] / 13);
            Card c = (Card)(Cards[u] % 13);
            return c.ToString() + " of " + s.ToString();
        }
        public static void Main()
        {
            Deck deck = new Deck();
            deck.Shuffle();
            for (uint u = 0; u < 5; ++u)
            {
                Console.WriteLine(deck.CardToString(u));
            }
            Console.ReadLine();
        }
    }
}
