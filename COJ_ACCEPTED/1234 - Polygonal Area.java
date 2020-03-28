import java.io.FileNotFoundException;
import java.io.FileReader;
import java.text.DecimalFormat;
import java.util.Scanner;


/**
 *
 * @author LUISMO
 */
public class Main {

    /**
     * @param args the command line arguments
     */
	static double [] temperatures;
	static double [] di;
	static int [] pi;
    public static void main(String[] args) throws FileNotFoundException {
        //FileReader fr = new FileReader("d:\\in.lmo");
        Scanner sc = new Scanner(System.in);
        double pi =3.141592653589793;
        //Mientras se pueda leer
        while (sc.hasNext()) {
			double error = 0.000001;
        	double r1 = sc.nextDouble();
			double r2 = sc.nextDouble();
			double L = 2*r2;
			double l = r1+r2;
			double cosAlfa = 1- (Math.pow(L, 2)/(2*Math.pow(l, 2)));
			double alfa = Math.acos(cosAlfa);
			double AreaTriang = Math.pow(l, 2)*Math.sin(alfa)/2;
			DecimalFormat df = new DecimalFormat("0.0000");
			double n = ((2*pi)/alfa);
			
			//Comparamos n contra el error
			double distErrorUp = Math.abs(Math.ceil(n)-n);
			double distErrorDown = Math.abs(Math.floor(n)-n);

			if(n-Math.floor(n) <error)
				System.out.println(df.format(Math.floor(n)*AreaTriang));
			else if(Math.ceil(n)-n <error)
				System.out.println(df.format(Math.ceil(n)*AreaTriang));
			else
				System.out.println("No Solution");
			
		}
    }
    
}
