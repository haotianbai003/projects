//import toolkit
import java.util.ArrayList;
import java.util.Scanner;
public class Hangman {
	public static void main(String[] args) {
		//variable declaration and initialization
		int ranNum1 = 0, ranNum2 = 0, counter = 0;
		boolean correctGuess = false;
		String guess = "", userInput = "";
		Scanner scan = new Scanner(System.in);
		//declare dynamic array
		ArrayList<Character> usedLetter = new ArrayList<Character>();
		//declare 2D array
		String words[][] = new String[4][8];
		//populate array
		//movies and tv shows category
		words[0][0] = "THE GODFATHER";
		words[0][1] = "TITANIC";
		words[0][2] = "CASABLANCA";
		words[0][3] = "STAR WARS";
		words[0][4] = "THE TWILIGHT ZONE";
		words[0][5] = "STAR TREK";
		words[0][6] = "THE SIMPSONS";
		words[0][7] = "SATURDAY NIGHT LIVE";
		//important figures in history category
		words[1][0] = "JULIUS CAESAR";
		words[1][1] = "MICHAEL JORDAN";
		words[1][2] = "ARISTOTLE";
		words[1][3] = "LEONARDO DA VINCI";
		words[1][4] = "JESUS CHRIST";
		words[1][5] = "ISSAC NEWTON";
		words[1][6] = "CHARLES DARWIN";
		words[1][7] = "WILLIAM SHAKESPEARE";
		//countries and regions of the world category
		words[2][0] = "CHINA";
		words[2][1] = "INDIA";
		words[2][2] = "UNITED STATES";
		words[2][3] = "INDONESIA";
		words[2][4] = "AFRO EURASIA";
		words[2][5] = "MIDDLE EAST";
		words[2][6] = "ANTARTICA";
		words[2][7] = "OCEANIA";
		//animals category
		words[3][0] = "CAPYBARA";
		words[3][1] = "FALCON";
		words[3][2] = "GRIZZLY BEAR";
		words[3][3] = "VULTURE";
		words[3][4] = "YAK";
		words[3][5] = "DRAGONFLY";
		words[3][6] = "DOLPHIN";
		words[3][7] = "BARRACUDA";
		//start outermost loop
		do
		{
			//reset all variables
			ranNum1 = 0; ranNum2 = 0; counter = 0;
			correctGuess = false;
			guess = ""; userInput = "";
			//generate random numbers
			ranNum1 = (int) ((Math.random()*4)+0);
			ranNum2 = (int) ((Math.random()*8)+0);
			//assign new value to guess
			for (int i = 0; i < words[ranNum1][ranNum2].length(); i++)
			{
				if ((words[ranNum1][ranNum2].charAt(i)) == ' ')
				{
					guess += " ";
				}
				else
				{
					guess += "-";
				}
			}//end loop
			//print clues
			System.out.print("Your category is: ");
			if (ranNum1 == 0)
			{
				System.out.println("TV Shows and Movies");
			}
			else if (ranNum1 == 1)
			{
				System.out.println("Important Figures in Human History");
			}
			else if (ranNum1 == 2)
			{
				System.out.println("Places of the World");
			}
			else
			{
				System.out.println("Animals");
			}
			//print the word
			System.out.println(guess);
			
			//start loop for user to guess word
			do
			{
				//user input to get user to enter letter or cheat code
				System.out.println();
				System.out.println("Enter your guess\nYou can make up to " + (7-counter) + " error(s).");
				//print used letters
				System.out.println(usedLetter);
				userInput = scan.nextLine();
				
				
				//start outermost if statement - check if user entered cheat code
				if (userInput.equals("OMEGA 93 RED"))
				{
					//print out the word if cheat code is correct
					System.out.println(words[ranNum1][ranNum2] + "\n");
				}
				else if (userInput.equals("THETA 47 BLUE"))
				{
					//resets the number of guesses
					counter = 0;
				}
				//if no code, check the first letter of user input for matches
				else
				{
					userInput = userInput.toUpperCase();
					char in = userInput.toUpperCase().charAt(0);
					if (usedLetter.contains(in)) {
						System.out.println("Invalid guess. You already gussed this letter.");
						continue;
					}
					
					//add letter to usedLetter
					usedLetter.add(in);
					
					//set boolean at false
					correctGuess = false;
					//start loop to check for the letter in the mystery word
					for (int i = 0; i < words[ranNum1][ranNum2].length(); i++)
					{
						//inner if 1 - check if there is a match
						if (userInput.charAt(0) == (words[ranNum1][ranNum2].charAt(i)))
						{
							//change boolean to true
							correctGuess = true;
							//replace the '-' with the letter
							guess = guess.substring(0, i) + userInput.charAt(0) + guess.substring(i + 1);
						}//end inner if 1
					}//end inner loop
					//inner if 2 - if there are no matches in mystery word
					if (correctGuess == false)
					{
						//increase counter
						counter++;
						//print result to user
						System.out.println("Incorrect guess. " + (7-counter) + " guess(es) remaining");					
						System.out.println(guess);
						//print out the hangman
						man(counter);
						System.out.println();
					}
					else
					{
						System.out.println("Correct guess! " + (7-counter) + " guess(es) remaining");					
						System.out.println(guess);
						//print out the hangman
						man(counter);
						//check if the entire word has been guessed
						for (int i = 0; i < guess.length(); i++)
						{
							if (guess.charAt(i) == '-')
							{
								correctGuess = false;
							}
						}
						if (correctGuess == true)
						{
							System.out.println("Congradulations, you guessed the word!");
							break;
						}
						System.out.println();
					}//end inner if 2
				}//end outermost if statement
			} while (counter < 7);
			if (counter >= 7)
			{
				System.out.println("You lost...");
				System.out.println("Your word was: " + words[ranNum1][ranNum2]);
				System.out.println();
			}
			//reset usedLetter
			usedLetter.clear();
			
			System.out.println("Enter '1' to play again, anything else to exit");
		} while (scan.nextLine().equals("1"));
		//end loop if user does not want to play again
	}//end main
	
	
	//start man method to print the hangman
	static void man(int tries) {
		//if statements to determine what to print
		if (tries == 1)
		{
			System.out.println(" O");
			
		}
		else if (tries == 2)
		{
			System.out.println(" O");
			System.out.println(" |");
			
		}
		else if (tries == 3)
		{
			System.out.println(" O");
			System.out.println("/|");
			
		}
		else if (tries == 4)
		{
			System.out.println(" O");
			System.out.println("/|\\");
			
		}
		else if (tries == 5)
		{
			System.out.println(" O");
			System.out.println("/|\\");
			System.out.println(" |");
		}
		else if (tries == 6)
		{
			System.out.println(" O");
			System.out.println("/|\\");
			System.out.println(" |");
			System.out.println("/");
		}
		else if (tries == 7)
		{
			System.out.println(" O");
			System.out.println("/|\\");
			System.out.println(" |");
			System.out.println("/ \\");
		}//end if statements
	}//end man method
}//end class