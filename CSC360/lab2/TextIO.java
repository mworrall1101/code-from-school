import java.util.Scanner;
import java.io.File;
import java.io.PrintStream;
import java.io.FileNotFoundException;

/**
 * TextIO is a class created specifically for use by UVic CSC115 Spring2016 students.
 * It handles very simple cases of text file input and output.
 */

public class TextIO {

/**
 * Opens a text file for reading.
 * @param filename The name of the plain text file to read.
 * @throws FileNotFoundException if the file is not there or the program does
 *	not have permission to access the file.
 * @return A Scanner object that can parse the text in the file.
 */
	public static Scanner openForReading(String filename) throws FileNotFoundException {
		Scanner reader = new Scanner(new File(filename));
		return reader;
	}

/**
 * Opens a text file for writing.
 * If the file is not there, then one is created and opened.
 * @param filename The name of the file.
 * @throws FileNotFoundException if there is an error opening the file, or the program
 *	does not have permission to access the file.
 * @return A PrintStream object that will print to the file.
 */
	public static PrintStream openForWriting(String filename) throws FileNotFoundException {
		PrintStream writer = new PrintStream(new File(filename));
		return writer;
	}

/**
 * This method is to be used to practice reading and writing to files.
 * @param args Not used.
 */
	public static void main(String[] args) throws FileNotFoundException{
		Scanner opener = null;
		PrintStream digitizer = null;
		
		try{
			opener = openForReading("lyrics.txt");
		}catch(FileNotFoundException e){
			System.out.println("File not found.");
		}
		
		try{
			digitizer = openForWriting("lyricsCopy.txt");
		}catch(FileNotFoundException e){
				System.out.println("File not found.");
			}
		while(opener.hasNext()){
			opener.println(digitizer.next());
			
		}
		opener.close();
		digitizer.close();
		
	}
}
