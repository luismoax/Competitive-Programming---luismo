import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main {

   
    
    public static void main(String[] args) throws ParseException, IOException {
    
       BufferedReader br=new BufferedReader(new InputStreamReader(System.in));   
      int tc = Integer.parseInt(br.readLine());
      for(int t=0;t<tc;t++)
      {
          String [] p = br.readLine().split(" ");
          int m = Integer.parseInt(p[0]);
          int j = Integer.parseInt(p[1]);
          
          int [] matt = new int[m];
          int [] jimmy = new int[j];
          
          int sumaMatt = 0;
          int sumaJimmy = 0;
          
          //Cojiendo los de matt
          for(int i = 0;i<m;i++)
          {
              matt[i] = Integer.parseInt(br.readLine());
              sumaMatt+=matt[i];
          }
          //Cojiendo los de Jimmy
          for(int i = 0;i<j;i++)
          {
              jimmy[i] = Integer.parseInt(br.readLine());
              sumaJimmy+=jimmy[i];
          }
          //Ordenamos
          Arrays.sort(matt);
          Arrays.sort(jimmy);
          
          int cursorM = m-1;
          int cursorJ = j-1;
          
          boolean empate = false;
          boolean ganador = true;
          
          while(cursorJ >=0 && cursorM>=0)
          {
              int aux1 = cursorM;
              int aux2= cursorJ;
              
                            
              if(sumaJimmy > matt[cursorM])
              {
                  cursorM--;                  
              }
              else if(sumaJimmy<matt[aux1])
              {
                  ganador = true;
                  break;
              }
              
              if(sumaMatt > jimmy[cursorJ])
                  cursorJ--;
              else if(sumaMatt<jimmy[aux2])
              {
                  ganador = false;
                  break;
              }
              
              if(cursorM != aux1)
                  sumaMatt-=matt[aux1];
              if(cursorJ != aux2)
                  sumaJimmy-=jimmy[aux2];
                            
              if(cursorM <0 )
              {
                  ganador = false;
                  break;
              }
              if(cursorJ<0)
              {
                  ganador = true;
                  break;
              }
              
              
              if(cursorJ == aux2 && cursorM==aux1)
              {
                  empate = true;
                  break;
              }
              
          }
          
          if(empate)
          {
              System.out.println("T "+(cursorM+1)+" "+(cursorJ+1));
          }
          else
          {
              if(ganador)
                  System.out.println("M "+(cursorM+1));
              else System.out.println("J "+(cursorJ+1));
          }
                    
      }
       
    }
}



