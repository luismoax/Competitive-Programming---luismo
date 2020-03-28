import java.io.BufferedReader;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;


/**
 * Author: Luis Manuel Díaz Barón
 * Problem: 2403 - NATJECANJE
 * Online Judge: COJ
 * Idea: Backtrack (Divide And Conquer) foreach competitor with reserve Kayaks try to lend to the one on the left
 * and the one to the right
 *
 */

public class Main {

    static MyScanner sc;
    static MyWriter mw;
    static String filePath="d:\\lmo.in";

    public static void main(String[] args) throws IOException {
        sc = new MyScanner(System.in);
        //sc = new MyScanner(new FileReader(filePath));
        mw = new MyWriter(System.out);

        while(sc.canRead())
            SolveSingleProblem();

        mw.close();
    }

    static  int [] arr;

    public static void SolveSingleProblem() throws IOException{
        int n = sc.nextInt();
        int s = sc.nextInt();
        int r = sc.nextInt();

        arr = new int[n] ;

        // teams with damaged kayaks
        for (int i = 0; i < s; i++)
            arr[sc.nextInt()-1] -=1;
        // teams with reserve kayaks
        for (int i = 0; i < r; i++)
            arr[sc.nextInt()-1] +=1;

        int cnt = 0;
        for (int i = 0; i < n; i++)
            if(arr[i]==-1)
                cnt++;

        // BackTrack
        BackTrack(cnt);

        mw.println(min);
    }

    static int min = Integer.MAX_VALUE;
    static void BackTrack(int left){

        for (int i = 0; i < arr.length; i++) {
            if(arr[i] == 1){

                if(i>0 && arr[i-1]==-1){

                    arr[i-1] +=1;
                    arr[i]--;
                    BackTrack(left-1);
                    arr[i]++;
                    arr[i-1] -=1;
                }

                if(i<arr.length-1 && arr[i+1]==-1){
                    arr[i+1]+=1;
                    arr[i]--;
                    BackTrack(left-1);
                    arr[i]++;
                    arr[i+1]-=1;
                }

            }
        }

        if(left<min)
            min = left;
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