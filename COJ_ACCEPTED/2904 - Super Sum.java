import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		BigInteger sum = new BigInteger("0");		
		for(int i = 0 ; i < N; i++){
			sum = sum.add(sc.nextBigInteger());
		}
		System.out.println(sum);
	}
}

