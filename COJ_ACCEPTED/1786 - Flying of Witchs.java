import java.io.BufferedReader;
import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;


/**
 * Author: Luis Manuel Díaz Barón (LUISMO)
 * Problem: 1786 - Flying of Witchs
 * Online Judge: COJ
 * Idea:O(N). Use a cumulative sums table, and a pointer to the left part of the current interval. 
 *		Each time a new value is read if the previos sum of an interval plus the new value is lesser than the top-> continue, else while the
 *  	cumulative sum between the value at left pointer + 1 and the last one read is greater than the top -> increase left pointer, otherwise keep the same size
 *		for a new interval (increasing the pointer on every loop).
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

        //int tc=sc.nextInt();
        while(sc.canRead())
            SolveSingleProblem();

        mw.close();
    }


    public static void SolveSingleProblem() throws IOException{
        // mw.println(2147483647 == Integer.MAX_VALUE);

        int tc = sc.nextInt();

        while(tc-->0){

            int maxWeigth = sc.nextInt();

            int n = sc.nextInt();
            int [] brooms = new int[n];
            int [] sums = new int[n+1];
            for (int i = 0; i < n; i++) {
                brooms[i] = sc.nextInt();

                sums[i+1] = sums[i] + brooms[i];
            }

			// flag is set true if at least there is an  interval whose sum is greater than the max weight possible
			// having flag = true, the left index must increase every time the loop begins in order to keep the interval size
            boolean flag= false; 

            int leftPointer = 0;
            for (int i = 1; i <= n; i++) {
                
				if(flag)
                    leftPointer++;
				// while the current interval sum is greater than the max possible weight
                while (sums[i] - sums[leftPointer] > maxWeigth  && leftPointer < i){
                    leftPointer++;
                    flag = true;
                }
				
				// if found a single value greater than max weight
                if(leftPointer == i ){
                    leftPointer = n;
                    break;
                }
            }
			// size of the last interval whose sum is less or equal than max weight
            mw.println(n- leftPointer);
        }

    }

    static boolean isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
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