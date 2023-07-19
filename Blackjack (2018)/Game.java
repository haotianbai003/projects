package blackjack;

import java.util.ArrayList;
import java.util.Scanner;

public class Game {
	
	private Deck dealer;
	private Deck player;
	private Deck discard;
	private Deck cards;
	private int chips, win, loss, round;
	
	public Game() {
		dealer = new Deck();
		player = new Deck();
		discard = new Deck();
		cards = new Deck();
		chips = 0;
		win = 0;
		loss = 0;
		round = 0;
	}
	
	// TODO: setup and takedown to be implemented eventually
	// to allow for loading/unloading saved games
	private void setup() {
		cards.generate();
		dealer.clear();
		player.clear();
		discard.clear();
		chips = 1000; 
		// TODO: to be implemented later, just count Win/Loss for now
	}
	
	private void takedown() {
		return;
	}
	
	public void play() throws Exception {
		boolean quit = false;
		this.setup();
		while (! quit) {
			System.out.println("=========");
			System.out.println("ROUND: " + (round+1));
			System.out.println("WIN: " + (win));
			System.out.println("LOSS: " + (loss));
			quit = this.round();
		}
		this.takedown();
	}
	
	private void printCards() {
		System.out.println();
		System.out.println("DEALER CARDS:");
		dealer.displayDealer();
		System.out.println("PLAYER CARDS:");
		player.display();
		System.out.println();
	}
	
	private void printResult() {
		System.out.println();
		System.out.println("DEALER CARDS:");
		dealer.display();
		System.out.println("PLAYER CARDS:");
		player.display();
		System.out.println();		
	}
	
	private boolean inputTF() {
		Scanner scan = new Scanner(System.in);
		String in = scan.nextLine();
		System.out.println();
		// scan.close();
		if (in.equals("Y"))
			return true;
		else
			return false;
	}
	
	public boolean round() throws Exception {
		if (cards.countSize() < 52) {
			ArrayList<Card> c = discard.clear();
			for (int i = 0; i < c.size(); i++) {
				cards.add(c.get(i));
			}
		}
		
		// dealer draw
		dealer.add(cards.draw());
		dealer.add(cards.draw());
		// player draw
		player.add(cards.draw());
		player.add(cards.draw());
		// display
		this.printCards();
		
		// draw until stand
		int pcount = player.countValue();
		while (pcount <= 21) {
			if (pcount == 21) {
				break;
			}
			// stand?
			System.out.println("HIT? (Y/N)");
			if (! this.inputTF()) {
				break;
			}
			// draw
			player.add(cards.draw());
			// display
			this.printCards();

			pcount = player.countValue();
		}
		
		if (pcount > 21) { // bust
			loss++;
			System.out.println("LOSS!");
			this.printResult();
			System.out.println();
		}
		else if (pcount == 21) { // bj
			win++;
			System.out.println("WIN!");
			this.printResult();
			System.out.println();
		}
		else { // compare with dealer
			// dealer draws until 17
			int dcount = dealer.countValue();
			while (dcount < 17) {
				dealer.add(cards.draw());
				dcount = dealer.countValue();
			}
			// check who's higher
			if (dcount > 21 || pcount > dcount) {
				win++;
				System.out.println("WIN!");
				this.printResult();
				System.out.println();
			}
			else if (dcount > pcount) {
				loss++;
				System.out.println("LOSS!");
				this.printResult();
				System.out.println();
			}
			else {
				System.out.println("TIED!");
				this.printResult();
				System.out.println();
			}
		}
		
		// discard cards
		ArrayList<Card> c = player.clear();
		for (int i = 0; i < c.size(); i++) {
			discard.add(c.get(i));
		}
		ArrayList<Card> cc = dealer.clear();
		for (int i = 0; i < cc.size(); i++) {
			discard.add(cc.get(i));
		}

		round++;
		// continue?
		System.out.println("QUIT? (Y/N)");
		return this.inputTF();
	}

}
