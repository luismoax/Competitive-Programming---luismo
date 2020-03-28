/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication1;

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
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        String s = "";
        
        while(sc.hasNext())
        {
            String answ = "EVIL";
            s = sc.nextLine();
            if(!s.contains("6"))
                answ = "GOOD";
            else if(Integer.parseInt(String.valueOf(s.charAt(s.length()-1)))% 2 !=0)
                answ = "GOOD";
            else
            {
                int k=0;
                int inic = 0;
                if(s.charAt(0) == '-')
                    inic = 1;
                for(int i =inic;i<s.length();i++)
                {
                    k+= Integer.valueOf(s.charAt(i));
                }
                if(k%6!=0)
                    answ = "GOOD";
            }
            System.out.println(answ);
        }
        
    }

}

