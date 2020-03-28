import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.TreeSet;
import java.util.Vector;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));		
		String s= br.readLine();
		int tc = Integer.parseInt(s);
		while(tc-->0 ){
			String [] data = br.readLine().split(" ");
			int n = Integer.parseInt(data[0]);
			int alf = Integer.parseInt(data[1]);
			int gustav = Integer.parseInt(data[2]);
			int rounds=0;
			
			while(ABS(gustav-alf)>0){
				rounds++;
				//System.out.println(alf+" "+gustav);
				gustav =(gustav+1)/2;
				alf =(alf+1)/2;
			}
			System.out.println(rounds);
		}
		
		
	}
	
	static int ABS(int a){
		if(a<0)
			return a*-1;
		return a;
	}
	
	static int Min(int a,int b){
		if(a<b)
			return a;
		return b;
	}
	
	

}
