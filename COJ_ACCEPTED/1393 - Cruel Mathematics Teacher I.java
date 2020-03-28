import java.math.BigInteger;
import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger b1 = sc.nextBigInteger();
		int pw = sc.nextInt();
		//System.out.println(b1.pow(pw));
		String s = b1.pow(pw).toString();
		for(int i =0;i< s.length();i++){
			if((i+1) %70==0)
				System.out.println(s.charAt(i));
			else System.out.print(s.charAt(i));
		}		
	}
}
