import java.io.FileNotFoundException;

import java.util.Scanner;
import java.util.Vector;


/**
 * @problem 1330 - Entering Bar
 * @author LUISMO
 */
public class Main {

    /**
     * @param args the command line arguments
     */
	
    public static void main(String[] args) throws FileNotFoundException {
    	//FileReader fr = new FileReader("d:\\in.lmo");
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        String [] arr = {
        	"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", 
        	"TEQUILA", "VODKA","WHISKEY", "WINE",
        	"0","1","2","3","4","5","6","7","8","9","10",
        	"11","12","13","14","15","16","17"
        };
        Vector<String> vect = new Vector<String>();
        for(int i=0;i<arr.length;i++)
        	vect.add(arr[i]);
        for (int t = 0; t < tc; t++) {
			int cnt=0, n = sc.nextInt();			
			for (int i = 0; i < n; i++) {
				String s= sc.next();				
				if((vect.contains(s)))
					cnt++;
			}
			System.out.println(cnt);
		}
    }
    
}
