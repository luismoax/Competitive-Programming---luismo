import java.io.BufferedReader;
import java.io.*;
import java.util.*;


/**
 * Author: Luis Manuel Díaz Barón
 * Problem:
 * Online Judge:
 * Idea:
 * Fecha: 20/02/2013
 */


public class Main {

    static MyScanner sc;
    static MyWriter mw;
    static String filePath = "/media/luismo/Trabajo/lmo.in";

    public static void main(String[] args) throws IOException {
        sc = new MyScanner(System.in);
        
        mw = new MyWriter(System.out);

        while (sc.canRead())
            SolveSingleProblem();


        mw.close();
    }

    public static void SolveSingleProblem() throws IOException {
        int n = sc.nextInt();
        if(n==-1)
            return;

        String pupilsNames[] = new String[n];
        int pupilsMoney [] = new int[n];
        for (int i = 0; i < n; i++) {
            pupilsNames[i] = sc.next();
            pupilsMoney[i] = 5*sc.nextInt() + 10*sc.nextInt()+20*sc.nextInt();
        }

        int idxMax=0;
        int idxMin=0;
        int moneyMax = pupilsMoney[0];
        int moneyMin = pupilsMoney[0];

        for (int i = 1; i < n; i++) {
            if(moneyMax<pupilsMoney[i]){
                moneyMax = pupilsMoney[i];
                idxMax = i;
            }

            if(moneyMin>pupilsMoney[i]){
                moneyMin = pupilsMoney[i];
                idxMin = i;
            }
        }

        if(idxMax == idxMin)
            mw.println("All have the same amount.");
        else mw.println(pupilsNames[idxMax]+" has most, "+pupilsNames[idxMin]+" has least money.");




    }


    static int Dif(int a,int b){
        if(a>b)
            return a-b;
        return a+(60-b);
    }

    static int max(int a,int b){
        if(a<b)
            return b;
        return a;
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