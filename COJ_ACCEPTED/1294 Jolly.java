import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		//FileReader fr = new FileReader("d:\\in.lmo");
		Scanner sc = new Scanner(System.in);		
		while (sc.hasNext()) 
		{
			int n = sc.nextInt();
			boolean [] arr = new boolean[n-1];
			int x1=sc.nextInt();
			int left = n-1;
			
			for(int c=1;c<n;c++){
				int k = sc.nextInt();
				int dif = Math.abs(Math.abs(k)-Math.abs(x1));

				if(dif<=arr.length && !arr[dif-1]){
					arr[dif-1]=true;
					left--;
				}
				x1 = k;					
			}
			if(left==0) System.out.println("Jolly");
			else System.out.println("Not jolly");
		}
	}

}