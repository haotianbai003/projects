package blackjack;

public class Card {
	
	private String value;
	// TODO: need to integrate an image...? eventually
	private Object pic = null;
	
	public Card() {
		value = "";
	}
	
	public Card(String val) {
		value = val;
	}
	
	public String getCard() {
		return value;
	}
	
	public int getValue() {
		if (value.compareTo("A") < 0) {
			return Integer.parseInt(value);
		}
		if (value.compareTo("A") == 0) {
			return 1;
		}
		return 10;
	}
	
	public void overrideValue(String val) {
		value = val;
	}
	
	// TODO: getter/setters for image in future

}
