import java.io.BufferedReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		
		for(int i = 0 ; i< tc ; i++)
		{
			int n = sc.nextInt();
			int s = sc.nextInt();
			
			String reg = sc.next();
			
			int arr [] = new int[n];
			int suma=0;
			
			for(int c=0;c<n;c++)
			{
				arr[c] = sc.nextInt();
			}
			
			Arrays.sort(arr);
			
			for(int k =0;k<s;k++)
			{
				if(reg.equals("regular"))
				{
					suma+= arr[n-1-k];
				}
				else suma+=arr[k];
			}
			
			System.out.println(suma);
			
		}
		
		
		
		
		
		
	}

}
