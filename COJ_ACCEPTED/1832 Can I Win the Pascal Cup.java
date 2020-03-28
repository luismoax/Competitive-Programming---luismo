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


    static float [][] pascalTree;


    public static void main(String[] args) throws IOException {
        sc = new MyScanner(System.in);
        
        pw = new MyWriter(System.out);



        int tc = sc.nextInt();

        // Generates the Pascal Tree until level 11
        pascalTree = new float[12][12];
        pascalTree[0][0] = 1;

        for(int i =1;i<12;i++){

            pascalTree[i][0]=1;
            pascalTree[i][i] = 1;

            for(int j=1;j<i;j++){
                pascalTree[i][j] = pascalTree[i-1][j-1] + pascalTree[i-1][j];
            }
        }

        while(tc-->0)
            SolveSingleProblem();


        /*
        // Printing Pascal Triangle
        for(int i=0;i<12;i++){
            for(int j=0;j<i+1;j++){

                pw.print(pascalTree[i][j]+" ");

            }
            pw.println("");
        }

        */



        pw.close();
    }

    public static void SolveSingleProblem() throws IOException{

        int t = sc.nextInt();
        int k = sc.nextInt();
        int n = sc.nextInt();

        // setting the formater
        DecimalFormat df = new DecimalFormat();
        df.setMaximumFractionDigits(4);
        df.setMinimumFractionDigits(4);
        DecimalFormatSymbols dfs = new DecimalFormatSymbols();
        dfs.setDecimalSeparator('.');
        df.setDecimalFormatSymbols(dfs);


        float f = (pascalTree[t][k] - pascalTree[t-n][k])  /pascalTree[t][k];

        pw.println(df.format(f));

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