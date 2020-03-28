import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		while (n>0) 
		{
			String maleName = "";
            double malePercent = 0;
            String femaleName = "";
            double femalePercent = 0;
			
            for (int i = 0; i < n; i++) {
            	String name = sc.next();
            	String sx = sc.next();
            	//System.out.println(name+" "+sx);
				double initial = sc.nextDouble();
				double finall = sc.nextDouble();
				
				double lostPercent = (initial - finall) * 100 / initial;
				//System.out.println(initial+" "+finall+" "+lostPercent);
				
				if(sx.equals("F") && lostPercent>femalePercent)
				{
					femalePercent = lostPercent;
					femaleName = name;					
				}
				else if(sx.equals("M")&& lostPercent>malePercent)
				{
					malePercent = lostPercent;
					maleName = name;
				}			
			}
            String pc = "%";
            //System.out.println(maleName+" "+femaleName);
            System.out.printf("%s %.2f%s %s %.2f%s",maleName,malePercent,pc,femaleName,femalePercent,pc);
            System.out.println();
            n =sc.nextInt();
		}
	}

}