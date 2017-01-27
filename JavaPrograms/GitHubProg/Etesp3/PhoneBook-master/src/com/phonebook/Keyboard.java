package phone;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

/**
 * (c) Ermias B. Tesfamariam 2010
 *
 * @author Ermias
 * @since 09:01:39 - 21.03.2010
 */

public class Keyboard {
	private static final BufferedReader keyboard =
		new BufferedReader(new InputStreamReader(System.in));
	
	public static String readString() {
		String line = null;
		
		try {
			line = keyboard.readLine();
		}
		catch(IOException e) {
			show("Error reading a string of characters.");
		}
		
		return line;
	}
	
	public static int readInteger() {
		int integer = 0;
		String line = readString();
		
		if(line != null) integer = Integer.parseInt(line);
		
		return integer;
		
	}
	
	public static float readFloat() {
		float real = 0.0f;
		String line = readString();
		
		if(line != null) real = Float.parseFloat(line);
			
		return real;
	}
	
	public static double readDouble() {
		double real = 0.0;
		String line = readString();
		
		if(line != null) real = Double.parseDouble(line);
			
		return real;
	}
	
	private static void show(String line) {
		System.err.println(line);
	}
}