import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.util.Scanner;



public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int [] arr = new int[5001];
		
		boolean [] digits = new boolean[10];
		
		for (int i = 1; i < 5001; i++)
		{
			boolean b = false;
			int k = i;
		
			
			
			digits = new boolean[10];
			
			while(k>0)
			{
				int x = k%10;
				
				if(digits[x])
				{
					b= true;
					arr[i] = arr[i-1];
					break;
				}
				else
				{
					digits[x] = true;
				}
				k/=10;
			}
			
			if(!b)
				arr[i] = arr[i-1]+1;
		}			
		
		
		String xin="";
		while ((xin = br.readLine())!=null)
		{	
			String [] data = xin.split(" ");
			
			int n = Integer.parseInt(data[0]);
			int m = Integer.parseInt(data[1]);
			if(n==1)
				System.out.println(arr[m]);
			else 
				System.out.println (arr[m]-arr[n-1]);
		}
		
	}

}
