import java.io.BufferedReader;
import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;


/**
 * Author: Luis Manuel D�az Bar�n
 * Problem: 2419 - Joshua String
 * Online Judge: COJ
 * Idea: Greedy, using a Heap for the strings (WATCH FOR a string prefix of other)
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

        //int tc=sc.nextInt();
        while(sc.canRead())
            SolveSingleProblem();

        mw.close();
    }

    public static void SolveSingleProblem() throws IOException{

        int tc = sc.nextInt();
        while(tc-->0){
            int n = sc.nextInt();
            PriorityQueue<StrLMO> heap = new PriorityQueue<StrLMO>();

            for (int i = 0; i < n; i++)
                heap.add( new StrLMO(sc.next()));
            String s="";
            while(heap.size() > 0){

                String tmp = heap.poll().seed;
                s+=tmp.charAt(0);
                if(tmp.length()>1)
                    heap.add( new StrLMO(tmp.substring(1)) );
            }
            mw.println(s);
        }
    }

}

class StrLMO implements  Comparable<StrLMO>{
    String seed;
    public StrLMO(String seed){
        this.seed = seed;
    }
    @Override
    public int compareTo(StrLMO other){
        String myStr= this.seed;
        String otherStr = other.seed;

        if(myStr.length() > otherStr.length() && myStr.startsWith(otherStr))
            return -1;

        if(otherStr.length() > myStr.length() && otherStr.startsWith(myStr))
            return  1;

        return this.seed.compareTo(other.seed);
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