import java.io.BufferedReader;
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Vector;


/**
 * Author: Luis Manuel Díaz Barón
 * Problem: Encoded Message
 * Online Judge: COJ
 * Idea: Ad-Hoc, using a matrix 
 * Fecha: 
 */

public class Main {

    static MyScanner sc;
    static MyWriter mw;
    static String filePath="d:\\lmo.in.txt";


    public static void main(String[] args) throws IOException {
        sc = new MyScanner(System.in);
        //sc = new MyScanner(new FileReader(filePath));
        mw = new MyWriter(System.out);

        int tc = sc.nextInt();
        while(tc-->0)
            SolveSingleProblem();

        mw.close();
    }

    public static void SolveSingleProblem() throws IOException{
        // Solve single problem
        String s = sc.next();
        int k = (int)Math.sqrt(s.length());
        char [][]mt = new char[k][k];
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                mt[i][j] = s.charAt(i*k + j);
            }
        }

        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                mw.print(mt[j][k-i-1]);
            }
        }
        mw.println("");
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

    public long [] nextLongArray(int n) throws IOException{
        long arr[] = new long[n];
        for(int i=0;i<n;i++)
            arr[i] = nextInt();
        return arr;
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
    public void printStr(String s){
        pw.println(s);
    }

    public void printArray(Object... arr){
        for(int i=0;i<arr.length;i++){
            if(i==0)
                print(arr[i].toString());
            else print(" "+arr[i].toString());
        }
    }

    public void close() {
        pw.close();
    }

}
