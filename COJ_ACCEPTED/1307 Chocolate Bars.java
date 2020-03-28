
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author LUISMO
 */
public class Main {

    /**
     * 1307 Chocolate Bars
     */
   
    public static void main(String[] args) throws FileNotFoundException {
        //FileReader fr = new FileReader("d:\\in.lmo");
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        for (int t = 0; t < tc; t++) 
        {
        	int n = sc.nextInt();
        	int [] chBars= new int[2*n];
        	for (int i = 0; i < chBars.length; i++) {
				chBars[i] = sc.nextInt();
			}
        	//Ordenamos las barras de chocolate
        	Arrays.sort(chBars);
        	boolean flag = false;
        	int suposedLength = chBars[0]+chBars[chBars.length-1];
        	for (int i = 1; i < chBars.length/2; i++) {
				if(chBars[i]+chBars[chBars.length-1-i] !=suposedLength){
					flag = true;
					break;
				}				
			}
        	if(!flag) System.out.println("NO");
        	else System.out.println("YES");        	
        }
    }

}
