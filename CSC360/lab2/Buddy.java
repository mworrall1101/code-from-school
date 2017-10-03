import java.util.Scanner;

public class Buddy {

	private Scanner buddy;

	public Buddy() {
		buddy = new Scanner(System.in);
		System.out.println("Buddy is ready to talk.  To quit, type \"Bye\"");
	}

	public Scanner getBuddy() {
		return buddy;
	}

	public void setBuddy(Scanner update) {
		buddy = update;
	}

	public void startConversation() {
		String user;
		do {
			System.out.println("Tell me more");
			user = buddy.nextLine();
		} while (!user.equalsIgnoreCase("bye"));
	}

	public static void main(String[] args) {
		Buddy b = new Buddy();
		b.startConversation();
	}
}
