import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Scanner sc = new Scanner(System.in);
		//int n = Integer.parseInt(br.readLine().trim());
		int n = sc.nextInt();
		long [] arr = new long[n];
		for(int t = 0;t<n;t++){
			//String s1 = br.readLine();
			String s1 = sc.next();
			String s2="";
			for(int i=0;i<s1.length();i++)
				s2+=s1.charAt(s1.length()-1-i);
			arr[t] = Long.parseLong(s2);
		}
		Arrays.sort(arr);
		for(long k: arr){
			System.out.println(k);
		}
	}

}
