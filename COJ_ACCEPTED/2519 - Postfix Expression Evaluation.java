import java.io.BufferedReader;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.*;


/**
 Author: Luis Manuel Díaz Barón
 Problem: 2519 - Postfix Expression Evaluation
 Online Judge: COJ
 Idea: AdHoc

 */

public class Main {

    static MyScanner sc;
    static MyWriter mw;
    static String filePath="d:\\lmo.in";


    public static void main(String[] args) throws IOException {

        sc = new MyScanner(System.in);
        // sc = new MyScanner(new FileReader(filePath));
        mw = new MyWriter(System.out);

        while(sc.canRead())
            SolveSingleProblem();

        mw.close();
    }

    // static fields

    public static void SolveSingleProblem() throws IOException{        

        int tc = sc.nextInt();

        LinkedList<Integer> queue = new LinkedList<Integer>(); // queue (using a Linked List)
        PriorityQueue<Integer> heap = new PriorityQueue<Integer>(); // priority queue
        Stack<Integer> stack = new Stack<Integer>(); // stack

        int sumQ =0, sumS = 0, sumH = 0; // to store each sum

        while(tc-->0){

            String [] data = sc.nextLine().split(" "); // reading line

            for (int i = 0; i < data.length; i++) {
                
                if(data[i].equals("+") ){

                    int s = stack.pop() + stack.pop();
                    int q = queue.pollLast() + queue.pollLast();
                    int h = heap.poll() + heap.poll();

                    sumH += h;
                    sumQ += q;
                    sumS += s;

                    stack.push(s);
                    queue.addFirst(q);
                    heap.add(h);

                }
                else if(data[i].equals("*") ){

                    int s = stack.pop() * stack.pop();
                    int q = queue.pollLast() * queue.pollLast();
                    int h = heap.poll() * heap.poll();

                    sumH += h;
                    sumQ += q;
                    sumS += s;

                    stack.push(s);
                    queue.addFirst(q);
                    heap.add(h);

                }
                else if(data[i].equals( "-") ){

                    int s = -stack.pop() + stack.pop();
                    int q = -queue.pollLast() + queue.pollLast();
                    int h = -heap.poll() + heap.poll();

                    sumH += h;
                    sumQ += q;
                    sumS += s;

                    stack.push(s);
                    queue.addFirst(q);
                    heap.add(h);

                }
                else {
                    int val = Integer.parseInt(data[i]);
                    heap.add(val);
                    queue.addFirst(val);
                    stack.push(val);
                }
            }

            mw.println(stack.pop()+" "+queue.pollLast() + " "+heap.poll());
        }

    }


    static int gcd(int a, int b){
        if ( a==0 ) return b;
        return gcd ( b%a, a );
    }
    static int mcm(int a, int b){
        return (a * b ) / gcd(a,b);
    }
    static boolean powerOfTwo(int n){
        return Integer.numberOfTrailingZeros(n) == (String.valueOf(Integer.toBinaryString(n)).length() -1);
    }
    static int log2(int n){
        return (int) (Math.log(n) / Math.log(2));
    }
    static int min(int a,int b){
        return (a<b)?a : b;
    }
    static int max(int a,int b){
        return (a>b)?a : b;
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

    public String nextLine() throws IOException{

        return br.readLine();
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