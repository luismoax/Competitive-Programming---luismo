import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.security.CodeSource;
import java.util.Scanner;


public class Main {

	/**
	 * @Author: Luismo
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		//FileReader fr = new FileReader("d:\\in.lmo");
		//Scanner sc = new Scanner (System.in);
		//new InputStreamReader(System.in)
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < tc; i++) {
			String tmp = br.readLine();
			int eCnt = 0;
			int oCnt = 0;
			for (int j = 0; j < tmp.length(); j++) {
				if(tmp.charAt(j)%2==0)
					eCnt++;
				else oCnt++;
			}
			
			if(eCnt>oCnt)
				System.out.println("Even");
			else System.out.println("Odd");
		}
		
	}
	
		
}


