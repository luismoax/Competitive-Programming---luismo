import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Vector;


public class Main {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	static int okVal=0;
	static long [] arr;
	static boolean []barr;
	public static void main(String[] args) throws NumberFormatException, IOException {		
		//FileReader fr = new FileReader("e:\\x.in");
		//Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//BigInteger bi = new BigInteger(br.readLine());		
		
		System.out.println(toBinary(toInteger(br.readLine()).multiply(new BigInteger("17"))));
	}
	
	static BigInteger toInteger(String number){
		BigInteger bi = new BigInteger("0");
		for(int i=0;i<number.length();i++){
			int ind = number.length()-1-i;
			if(number.charAt(ind)=='1'){
				bi=bi.add(new BigInteger("2").pow(i));
			}
		}
		return bi;
	}
	
	public static String toBinary(BigInteger bi){
		String s="";
		BigInteger two =new BigInteger("2");
		BigInteger zero =new BigInteger("0");
		while(bi.compareTo(zero)>0){
			s=bi.remainder(two).toString()+s;
			bi = bi.divide(two);
		}
		
		return s;
	}
}