package blackjack;

import java.util.*;

public class Deck {
	private ArrayList<Card> cards = new ArrayList<Card>();
	
	public Deck() {
		// creates an empty deck
		cards.clear();
	}
	
	public Card draw() throws Exception {
		// draws a card
		if (cards.size() == 0)
			throw new Exception("Cannot draw from empty deck");
		int pos = (int) (Math.random() * cards.size() + 1);
		return cards.remove(pos);
	}
	
	
	public void add(Card c) {
		cards.add(c);
	}
	
	
	public void display() {
		for (int i = 0; i < cards.size(); i++) {
			System.out.print(cards.get(i).getCard() + " ");
		}
		System.out.println();
	}
	
	
	public void displayDealer() {
		System.out.println(cards.get(0).getCard() + " ?");
	}
	
	
	public ArrayList<Card> clear() {
		// clears deck
		ArrayList<Card> tmp = cards;
		cards = new ArrayList<Card>();
		return tmp;
	}
	
	
	public void generate() {
		// generates 4 full decks
		for (int i = 0; i < 144; i++)
		{
			cards.add(new Card(Integer.toString(2 + (i%9))));
		}
		for (int i = 0; i < 16; i++)
		{
			cards.add(new Card("A"));
			cards.add(new Card("J"));
			cards.add(new Card("Q"));
			cards.add(new Card("K"));
		}
	}
	
	public int countSize() {
		return cards.size();
	}
	
	public int countValue() {
		// counts highest possible value w/out going over 21
		int totalVal = 0;
		int ace = 0;
		for (int i = 0; i < cards.size(); i++) {
			Card card = cards.get(i);
			int v = card.getValue();
			if (v == 1) {
				ace++;
			}
			else {
				totalVal += card.getValue();
			}
		}
		
		if (totalVal > 21) {
			return totalVal += ace;
		}
		else {
			for (int i = 1; i <= ace; i++) {
				if (totalVal + 11 > 21) {
					totalVal += 1;
				}
				else if (totalVal + 11 > 20 && ace - i > 0) {
					totalVal += 1;
				}
				else {
					totalVal += 11;
				}
			}
		}
		return totalVal;
	}
}
