import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        BigInteger one = new BigInteger("1");

        String line = br.readLine();
		
        while(line != null){
            String [] data = line.split(" ");
            BigInteger A = new BigInteger(data[0]);
            BigInteger B = new BigInteger(data[1]);
            BigInteger P = new BigInteger(data[2]);

            BigInteger axP = P;

            BigInteger answ = new BigInteger("0");

            while(axP.compareTo(B) <= 0){
                
				// cnt = B/axP - (A-1)/axP				
				BigInteger cnt = B.divide(axP);
                BigInteger aux = A.subtract(one).divide(axP);			
                cnt = cnt.subtract(aux);

                if(cnt.toString().equals("0"))
                    break;
				
                answ = answ.add(cnt);
				// P *= P
                axP = axP.multiply(P);
            }

			// convert the answer to octal
            String oct = toOctal(answ);
			// print the answer
            System.out.println(oct);

            // read again
            line = br.readLine();
        }
    }

    static String toOctal(BigInteger x){
        if(x.toString().equals("0"))
            return "0";

        BigInteger eight = new BigInteger("8");
        String ret = "";

        while(!x.toString().equals("0")){
            ret = x.divideAndRemainder(eight)[1].toString() + ret;

            x = x.divide(eight);
        }
        return ret;
    }

}
