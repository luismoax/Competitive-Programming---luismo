import java.io.BufferedReader;
import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;


/**
 * Author: Luis Manuel Díaz Barón
 * Problem: 3265 - Der Kroketten
 * Online Judge: COJ
 * Idea:
 *
 */

public class Main {

    static MyScanner sc;
    static MyWriter mw;
    static String filePath="e:\\lmo.in";

    public static void main(String[] args) throws IOException {
        sc = new MyScanner(System.in);

        // filePath = "e:\\ZZZ\\010.in";
        // sc = new MyScanner(new FileReader(filePath));
        mw = new MyWriter(System.out);

        // while(sc.canRead())
            SolveSingleProblem();

        mw.close();
    }

    static String str = "";


    public static void SolveSingleProblem() throws IOException{
        // BufferedReader br = new BufferedReader(new FileReader(filePath));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        str = br.readLine();
        while(str != null){
            String arr[] = str.split(" ");

            for (int i = 0; i < arr.length; i++) {
                if(i > 0) mw.print(" ");

                if(arr[i].toLowerCase().equals( "kroketten") )
                    mw.print("croqueta");
                else mw.print(arr[i]);
            }
            mw.println("");

            str = br.readLine();
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

    public long nextLong() throws IOException{
        return Long.parseLong(next());
    }

    public double nextDouble() throws IOException{
        return Double.parseDouble(next());
    }

    public boolean canRead() throws IOException{
        return br.ready();
    }

    public int [] nextIntArray(int n) throws IOException{
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
            arr[i] = nextInt();
        return arr;
    }

    public BigInteger nextBigInteger() throws IOException{
        return new BigInteger(this.next());
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

    public void printArray(int[] arr){
        for(int i=0;i<arr.length;i++){

            if(i==0)
                println(arr[i]);
            else println(" "+arr[i]);

        }
    }


    public void printVectorInteger(Vector<Integer> arr){
        for(int i=0;i<arr.size();i++){

            if(i==0)
                print(arr.elementAt(i));
            else print(" " + arr.elementAt(i));

        }
    }

    public void printVectorLong(Vector<Long> arr){
        for(int i=0;i<arr.size();i++){

            if(i==0)
                print(arr.elementAt(i));
            else print(" " + arr.elementAt(i));

        }
    }

    public void printIntMatrix(int [][] mt){
        for(int i=0;i<mt.length;i++){
            for(int j=0;j<mt[0].length;j++){
                print(mt[i][j]+" ");
            }
            println("");
        }
        println("");
    }
    public void close() {
        pw.close();
    }
}