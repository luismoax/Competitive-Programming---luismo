import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));		
		int tc = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < tc; i++) {
			
			String s = br.readLine();
			if(s.charAt(0) == 'A' || s.charAt(s.length()-1) == 'A')
				System.out.println("Alf");
			else System.out.println("Gustav");
			
		}
	}

}
