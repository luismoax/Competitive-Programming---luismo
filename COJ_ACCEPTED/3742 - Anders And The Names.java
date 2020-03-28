import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	
	

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
				String name = br.readLine();
		
		while(name != null){
			
			String [] words = name.split(" ");
			
			int capital = 0; // number of capital letters
			for(int i = 0; i < words.length; i++){				
				for(int j = 0; j < words[i].length(); j++){
					char c = words[i].charAt(j);
					if(c >= 'A' && c <= 'Z')
						capital++;
				}				
			}
			
			if(capital == words.length)
				System.out.println("correct");
			else System.out.println("awful");
			
			name = br.readLine();
		}
		
	}		

}
