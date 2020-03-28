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
			double pi =3.141592653589793;
			double a = sc.nextDouble();
			double AreaTriang = ((a/2) * (a/2 - a/3))/2;
			double AreaQuadCircunf = (pi*(Math.pow(a/3,2)))/4;
			
			double QuadSomber = Math.pow(a/2, 2) -(2*AreaTriang + AreaQuadCircunf);
			DecimalFormat df = new DecimalFormat("0.0000");
			System.out.println(df.format(4*QuadSomber));
		}
	}

}