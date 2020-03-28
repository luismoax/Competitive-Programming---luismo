import java.io.*;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Main  
{
    
    public static void main(String[] args) throws Exception
    {
         
         //FileReader fr = new FileReader("d:\\in.lmo");
         Scanner sc = new Scanner(System.in);
         int tc = sc.nextInt();
         for(int i=0;i<tc;i++)
         {
             double r = sc.nextDouble();
             double n = sc.nextDouble();
             double alfa = 360.0/n;
             
             double a1 = r*(Math.sqrt(2*(1-Math.cos(Math.toRadians(alfa)))));
             
             double h2 = r/(Math.cos(Math.toRadians(alfa/2)));
             double a2 = 2*(Math.sqrt(h2*h2 - r*r));
             
             System.out.printf("%.4f %.4f",n*a1,n*a2);
             System.out.println();
             
         }         
    }
}

        