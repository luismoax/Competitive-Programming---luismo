import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
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
		int n = Integer.parseInt(br.readLine());
		arr = new long[n];
		barr = new boolean[n];
		for(int t=0;t<n;t++){
			arr[t] = Integer.parseInt(br.readLine());
		}
		
		for(int k=0;k<arr.length;k++){
			Mtd(k,1,arr[k]);
		}
		
		System.out.println(okVal);
	}
	
	static void Mtd(int ind,int cnt,long amount){
		if(ind == arr.length-1){
			if(cnt>okVal)
				okVal = cnt;			
			return;
		}
		if(!Acarrga(amount,arr[ind+1]))
			Mtd(ind+1, cnt+1, amount+arr[ind+1]);
		
		Mtd(ind+1, cnt, amount);		
	}
	
	static boolean Acarrga(long a,long b){
		String as = String.valueOf(a),bs = String.valueOf(b);
		int n = Math.max(as.length(), bs.length())  - Math.abs(as.length()-bs.length());
		
		for(int c=0;c<n;c++){
			char ca = as.charAt(as.length()-1-c);
			char cb = bs.charAt(bs.length()-1-c);
			if(Integer.parseInt(String.valueOf(ca))+ Integer.parseInt(String.valueOf(cb))>=10)
				return true;
		}
		return false;
	}
	
}