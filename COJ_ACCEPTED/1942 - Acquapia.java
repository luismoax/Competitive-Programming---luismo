import java.io.BufferedReader;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.*;


/**
  Author: Luis Manuel Díaz Barón
  Problem: 1942 - Acquapia
  Online Judge: COJ
  Idea: Every river map is a graph where every city is a node and every river section is a edge
  the main idea is to find LCA of every pair of cities in the queries y LCA is one of these cities,
  then there is no turning needed
  
 
 */

public class Main {

    static MyScanner sc;
    static MyWriter mw;
    static String filePath="d:\\lmo.in";

    public static void main(String[] args) throws IOException {

        sc = new MyScanner(System.in);
        // sc = new MyScanner(new FileReader(filePath));
        mw = new MyWriter(System.out);

        while(sc.canRead()) {

            // reading
            c = sc.nextInt(); // cities
            r = sc.nextInt(); // number of rivers
            s = sc.nextInt(); // river sections (EDGES)
            q = sc.nextInt(); // Queries

            if(c + r + s + q == 0)
                break;

            SolveSingleProblem();
        }

        mw.close();
    }

    // static fields
    static int c,r,s,q;
    static Vector<City> cities;
    static Vector<Vector<Integer>> adj;
    static Vector<Integer> riverSources;

    // for Euler Tours
    static Vector< Integer > eulerTours;
    static int currentRiver;
    static int currentVector;

    // for RMQ;
    static int [][] rmq;

    public static void SolveSingleProblem() throws IOException{


        // creating adjacency vectors
        adj = new Vector<Vector<Integer>>();
        for (int i = 0; i < c; i++)
            adj.add(new Vector<Integer>());

        // creating cities
        cities = new Vector<City>();
        for (int i = 0; i < c; i++)
            cities.add(new City(i));

        // reading riversources
        riverSources = new Vector<Integer>();
        for (int i = 0; i < r; i++)
            riverSources.add(sc.nextInt()  - 1);

        // reading ADJACENCY
        for (int i = 0; i < s; i++) {
            int x = sc.nextInt() - 1;
            int y = sc.nextInt() - 1;
            // adding the edge
            adj.elementAt(x).add(y);
            adj.elementAt(y).add(x);
        }


        // LCA
        
        // EULER TOUR
		
		// foreach river store its Euler Tour
        eulerTours = new Vector<Integer>();
        for (int i = 0; i < riverSources.size(); i++) {

            currentRiver = riverSources.elementAt(i);
            // Euler Tour from this root
            int root = riverSources.elementAt(i);
            Tour(root);
        }
        // END EULER TOUR

        // RMQ PROCESS
        RMQProcess();
        // END RMQ PROCESS

        // END LCA

        mw.println("");
        for (int i = 0; i < q; i++) {
			// Cities to query
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;

            // if they are from diferent rivers output -1
            if(cities.elementAt(a).crossingRiver != cities.elementAt(b).crossingRiver)
                mw.println(-1);
            else{
                // queriyng
				
				// first occurrence of each city on the Euler Tour
                int aOcu = cities.elementAt(a).firstOcurrence;
                int bOcu = cities.elementAt(b).firstOcurrence;
				
				// Lowest Common Ancestor
                int lca = RMQQuery(aOcu,bOcu);

				// If no river turns needed
                if(lca == a || lca ==b)
                    mw.println(0);
                else mw.println(lca + 1);

            }
        }
    }


    static int RMQQuery(int i, int j){
        // swaping inverted indexes
        if(i > j){
            int tmp = i;
            i = j;
            j = tmp;
        }

        // block length
        int k = (int)log2(j - i + 1);

        int first = rmq[i][k];

        int second = rmq[j - (1<<k) + 1][k];
		// comparing by level
        if(cities.elementAt(first).level < cities.elementAt(second).level)
            return first;

        return second;
    }

    static void RMQProcess(){

        int n = eulerTours.size();
        int col =   (int) Math.ceil( log2(n) ) + 1;
        rmq = new int[n][col];

        // setting intervals of length 2^0
        for (int i = 0; i < n; i++) {
            rmq[i][0] = cities.elementAt( eulerTours.elementAt(i) ).ID;
        }

        // botton - up DP
        // foreach possible interval
        for (int j = 1; 1<<j <= n; j++) {

            int pw = 1<<j;
            // foreach possible index
            for (int i = 0; i + pw - 1 < n; i++) {

                int first = rmq[i][j-1];
                int second = rmq[i + ( 1<<(j-1)) ][ j-1 ];

                // comparing cities by LEVEL on the euler tour
                if(cities.elementAt(first).level < cities.elementAt(second).level)
                    rmq[i][j] = first;

                else rmq[i][j] = second;
            }
        }
    }


	// Euler Tour
    static void Tour(int idx){
        // setting river
        cities.elementAt(idx).crossingRiver = currentRiver;
        // setting VISITEd
        cities.elementAt(idx).visited = true;
        // setting first ocurrence
        cities.elementAt(idx).firstOcurrence = eulerTours.size();

        eulerTours.add(idx);

        for (int i = 0; i < adj.elementAt(idx).size(); i++) {
            // adjacent
            int next = adj.elementAt(idx).elementAt(i);
            // if has not been visited
            if(!cities.elementAt(next).visited){
                // setting level
                cities.elementAt(next).level =cities.elementAt(idx).level +1;

                // recursive call
                Tour(next);
                // push to the tour again
                eulerTours.add(idx);
            }
        }
    }

    static int log2(int n){
        return (int) (Math.log(n) / Math.log(2));
    }

}


class City{

    public int ID, crossingRiver;
    public boolean  visited;
    public int firstOcurrence;
    public int level;

    public City(int ID){
        this.ID = ID;
        this.visited = false;
        firstOcurrence = -1;
        level = 0;
    }

    @Override
    public String toString(){
        return String.format("%d %d ",ID,crossingRiver);
    }
}


// IO
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