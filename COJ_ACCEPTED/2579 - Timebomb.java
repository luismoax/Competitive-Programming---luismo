import java.io.BufferedReader;
import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;


/**
 * Author: Luis Manuel Díaz Barón
 * Problem: 2579 - Timebomb
 * Online Judge: COJ
 * Idea: Easy, store each digit in a map (as a string)
 *
 */


public class Main {

    static MyScanner sc;
    static MyWriter mw;
    static String filePath="d:\\lmo.in";

    public static void main(String[] args) throws IOException {
        sc = new MyScanner(System.in);
        // sc = new MyScanner(new FileReader(filePath));
        mw = new MyWriter(System.out);

        //while(sc.canRead())
        SolveSingleProblem();

        mw.close();
    }

    static String [] arr;
    public static void SolveSingleProblem() throws IOException{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in)) ;
	// read from file
        // BufferedReader br = new BufferedReader(new FileReader(filePath)) ;


        String first = br.readLine();
        // length
        arr = new String[(first.length() + 1) / 4];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = "";
        }

        for (int k = 0; k < 5; k++) {

            for (int i = 0; i < arr.length; i++) {

                String s = "";

                for (int j = 0; j < 3; j++) {
                    s+= String.valueOf( first.charAt(3*i + j + i) );
                }

                arr[i] +=s;
            }
            first = br.readLine();

        }

        HashMap<String, Integer> map = new HashMap<String, Integer>();

        map.put("**** ** ** ****", 0);
        map.put("  *  *  *  *  *", 1);
        map.put("***  *****  ***", 2);
        map.put("***  ****  ****", 3);
        map.put("* ** ****  *  *", 4);
        map.put("****  ***  ****", 5);
        map.put("****  **** ****", 6);
        map.put("***  *  *  *  *", 7);
        map.put("**** ***** ****", 8);
        map.put("**** ****  ****", 9);

        String number = "";
        boolean  boom = false;
        for (int i = 0; i < arr.length; i++) {
            if(!map.containsKey(arr[i])){
                boom = true;
                break;
            }
            else number += String.valueOf(map.get(arr[i]));

        }
        if(boom || Integer.valueOf(number) == 0 || Integer.valueOf(number) % 6 != 0)
            boom = true;

        if(boom)
            mw.println("BOOM!!");
        else mw.println("BEER!!");

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


    public void printVector(Vector<Integer> arr){
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