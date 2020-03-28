import java.io.BufferedReader;
import java.io.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.Vector;


/**
 * Author: Luis Manuel Díaz Barón
 * Problem: Barica
 * Online Judge: COJ
 * Idea: Dynamic algorithm, carriying best energy posible from each column and each row
 * Fecha: 20/02/2013
 */


public class Main {

    static MyScanner sc;
    static MyWriter mw;
    static String filePath = "d:\\barica\\2barica.in";

    public static void main(String[] args) throws IOException {
        sc = new MyScanner(System.in);

        mw = new MyWriter(System.out);        
        while (sc.canRead())
           SolveSingleProblem();
       

        mw.close();
    }

    public static void SolveSingleProblem() throws IOException {

        int n = sc.nextInt();
        int k = sc.nextInt();

        // reading plants
        Plant [] plants = new Plant[n];
        for (int i = 0; i < n; i++) {
            plants[i] = new Plant(sc.nextInt(),sc.nextInt(),sc.nextInt());
        }

        Plant first = plants[0]; // first plant
        Plant last = plants[plants.length-1]; // last plant

        // sorting plants
        Arrays.sort(plants);

        int [] rows = new int[100009];
        int [] cols = new int[100009];

        boolean  flag = false; // flag that marks if the first plant is scanned
        int answer = -1;
        // foreach plant
        for (int i = 0; i < n; i++) {

            if(plants[i].equals(first)){

                rows[plants[i].x] = plants[i].f;
                cols[plants[i].y] = plants[i].f;
                flag = true;
            }
            // if the first plant is already visited
            else if(flag){

                // maximun that can be achieved from columns or rows
                int mx = max(rows[plants[i].x], cols[plants[i].y]);

                // if a can Jump from a colum or a row
                if(mx>=k){

                    // amount of energy before jumping to other plant
                    int fct = mx - k + plants[i].f;

                    // uptade the values of best energy to jump
                    // per rows or columns
                    if(fct > rows[plants[i].x])
                        rows[plants[i].x] = fct;
                    if(fct > cols[plants[i].y])
                        cols[plants[i].y] = fct;

                    // last plant
                    if(plants[i].equals(last)){
                        //answer = max(cols[plants[i].y], rows[plants[i].x]);
                        answer = fct;
                        break;
                    }
                }

            }



        }
        mw.println(answer);


    }

    static int max(int a,int b){
        if(a<b)
            return b;
        return a;
    }
}


class Plant implements Comparable<Plant> {
    int x,y,f;
    public Plant(int x,int y,int f){
        this.x = x;
        this.y = y;
        this.f = f;
    }


    public int compareTo(Plant p){
        if(p.x == this.x)
            return this.y - p.y;
        return this.x - p.x;

    }


    public boolean equals(Plant other){
        return this.x==other.x && this.y==other.y;
    }

}


class MyScanner {
    BufferedReader br;
    StringTokenizer stk;

    public MyScanner(InputStream stream) {
        this.br = new BufferedReader(new InputStreamReader(stream), 72357);
        this.stk = new StringTokenizer("");
    }

    public MyScanner(FileReader fr) {
        this.br = new BufferedReader(fr);
        this.stk = new StringTokenizer("");
    }

    public String next() throws IOException {
        while (!stk.hasMoreElements()) {
            String line = br.readLine();
            if (line == null)
                return null;
            stk = new StringTokenizer(line);
        }
        return stk.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public boolean canRead() throws IOException {
        return br.ready();
    }

    public int[] nextIntArray(int n) throws IOException {
        int arr[] = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = nextInt();
        return arr;
    }

    public long[] nextLongArray(int n) throws IOException {
        long arr[] = new long[n];
        for (int i = 0; i < n; i++)
            arr[i] = nextInt();
        return arr;
    }
}

class MyWriter {

    PrintWriter pw;

    public MyWriter(OutputStream out) {
        this.pw = new PrintWriter(out);
    }

    public void print(Object obj) {
        pw.print(obj.toString());
    }

    public void println(Object obj) {
        pw.println(obj.toString());
    }

    public void printArray(Object[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (i == 0)
                print(arr[i].toString());
            else print(" " + arr[i].toString());
        }
    }

    public void printMatrix(Object[][] mt) {
        for (int i = 0; i < mt.length; i++) {
            for (int j = 0; j < mt[i].length; j++) {
                if (j == 0) {
                    print(mt[i][j].toString());
                } else print(' ' + mt[i][j].toString());
            }
            println("");
        }
    }

    public void close() {
        pw.close();
    }

}