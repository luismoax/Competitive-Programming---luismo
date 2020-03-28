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
		double maxFactor = 0;
		String nombre = "";
		
		for(int i = 0 ; i< tc ; i++)
		{
			String nm = sc.next();
			double pa = sc.nextDouble();
			double pj = sc.nextDouble();
			double g = sc.nextDouble();
			double a = sc.nextDouble();
			double ta = sc.nextDouble();
			double tr = sc.nextDouble();
			
			double factor =Math.log10(pa) + pj + 2*g + a - (ta + 2*tr);
			
			if(factor > maxFactor) 
			{
				maxFactor = factor;
				nombre = nm;				
			}
			
		}
		System.out.println(nombre);
				
		
	}

}
