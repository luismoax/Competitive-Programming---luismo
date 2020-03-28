/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.text.DecimalFormat;
import java.util.Scanner;

/**
 *
 * @author FAMILY
 */
public class Main {

    /**
     * @param args the command line arguments
     */
   
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        for(int t =0;t<tc;t++)
        {
            double d = sc.nextDouble();
            double v1 = sc.nextDouble();
            double v2 = sc.nextDouble();
            double m = sc.nextDouble();
            //Para dar formato a la salida
            DecimalFormat df = new DecimalFormat();
            df.setMaximumFractionDigits(2);
            df.setMinimumFractionDigits(2);
            df.setGroupingSize(0);
            System.out.println(df.format(m*d/(v1+v2)));
        }
    }
    
    

}
