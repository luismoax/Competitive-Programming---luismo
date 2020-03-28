import java.io.BufferedReader;
import java.io.*;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.Vector;


/**
 * Author: Luis Manuel Díaz Barón
 * Problem:
 * Online Judge:
 * Idea:
 * Fecha: 20/02/2013
 */



public class Main {

    static MyScanner sc;
    static MyWriter pw;
    static String filePath="/media/luismo/Trabajo/lmo.in";


    static boolean [] taken;
    static String s;
    static int x=-1,sol=Integer.MAX_VALUE;


    public static void main(String[] args) throws IOException {
        sc = new MyScanner(System.in);
        
        pw = new MyWriter(System.out);



        while(sc.canRead())
            SolveSingleProblem();


        pw.close();
    }

    public static void SolveSingleProblem() throws IOException{

        s = sc.next();

        x = Integer.parseInt(s);

        taken = new boolean[s.length()];

        BackTrack("");

        if(sol == Integer.MAX_VALUE)
            sol = 0;
        pw.println(sol);

    }


    public static void  BackTrack(String build){

        if(build.length() == taken.length){
            int k = Integer.parseInt(build);
            if(k>x && k < sol)
                sol = k;
        }

        for(int i =0;i<taken.length;i++){

            if(!taken[i]){

                if(!( build.length()==0 && s.charAt(i)=='0')){

                    taken[i] = true;

                    BackTrack(build+s.charAt(i));

                    taken[i] = false;

                }

            }

        }

    }



}


class MyScanner{
    BufferedReader br;
    StringTokenizer stk;
    public MyScanner(InputStream stream){
        this.br = new BufferedReader(new InputStreamReader(stream),72357);
        this.stk = new StringTokenizer("");
    }
    public MyScanner(FileReader fr){
        this.br = new BufferedReader(fr);
        this.stk = new StringTokenizer("");
    }
    public String next() throws IOException {
        while(!stk.hasMoreElements()){
            String line = br.readLine();
            if(line == null)
                return null;
            stk = new StringTokenizer(line);
        }
        return stk.nextToken();
    }
    public int nextInt()throws IOException{
        return Integer.parseInt(next());
    }
    public boolean canRead() throws IOException{
        return br.ready();
    }
}

class MyWriter{
    PrintWriter pw;
    public MyWriter(OutputStream out){
        this.pw = new PrintWriter(out);
    }
    public void print(Object obj){
        pw.print(obj.toString());
    }
    public void println(Object obj){
        pw.println(obj.toString());
    }
    public void printArr(int [] objects){
        for(int i =0;i<objects.length;i++){
            if(i!=0)
                print(" "+objects[i]);
            else print(objects[i]);
        }
        println("");
    }

    public void close() {
        pw.close();
    }
}