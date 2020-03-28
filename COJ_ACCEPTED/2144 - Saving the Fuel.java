import java.awt.print.Book;
import java.io.BufferedReader;
import java.util.TreeSet;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;
import java.util.prefs.BackingStoreException;


public class Main {

	/**
	 * @author LUISMO
	 * 
	 * Problem: 
	 */
		
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in) );				
				
		int tc = Integer.parseInt(br.readLine());
		for (int t = 0; t < tc; t++) {
			int n,d;
			String [] data = br.readLine().split(" ");
			n = Integer.parseInt(data[0]);
			d = Integer.parseInt(data[1]);
			String tmp = data[2].trim();
			
			data = br.readLine().split(" ");
			int [] arr = new int[data.length];
			for(int i=0;i<arr.length;i++)
				arr[i] = Integer.parseInt(data[i]);
			
			Arrays.sort(arr);
			
			int cnt = 0;
						
			for(int i=0; i < d;i++){
				
				if(tmp.equals("regulate"))
					cnt+=arr[arr.length-1-i];									
				else cnt+=arr[i];				
			}
			
			System.out.println(cnt);			
		}
				
	}
	
}

