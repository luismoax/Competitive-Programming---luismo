import java.io.BufferedReader;
import java.io.*;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.Vector;



/**
 * Author: Luis Manuel Díaz Barón
 * Problem:
 * Online Judge:
 * Idea:
 *
 */


public class Main {

    static MyScanner sc;
    static MyWriter mw;
    static String filePath="/media/luismo/Trabajo/lmo.in";

    public static void main(String[] args) throws IOException {
        sc = new MyScanner(System.in);
        
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
            String [] letters = new String[n];
            int vowels=0,nonVowels=0;
            for (int i = 0; i < n; i++) {
                letters[i] = sc.next();
                if(isVowel(letters[i].charAt(0)))
                    vowels++;
                else nonVowels++;
            }
            if(vowels <2 || nonVowels <2){
                mw.println(-1);
            }
            else {
                // sort all the letters
                Arrays.sort(letters);

                // length of the string
                vowels = min(vowels,nonVowels);
                if(vowels%2==1)
                    vowels--;
                nonVowels = vowels;

                String [] cad = new String[2*vowels];

                cad[0] = letters[0];
                if(isVowel(letters[0].charAt(0)))
                    vowels--;
                else nonVowels--;

                cad[cad.length-1] = letters[letters.length-1];
                if(isVowel(letters[letters.length-1].charAt(0)))
                    vowels--;
                else nonVowels--;

                int cadIdx = 1;

                for (int i = 1; i < letters.length-1 && cadIdx<cad.length-1; i++) {
                    if(vowels>0 && isVowel(letters[i].charAt(0))){
                        cad[cadIdx++] = letters[i];
                        vowels--;
                    }
                    else if(nonVowels>0 && !isVowel(letters[i].charAt(0))){
                        cad[cadIdx++] = letters[i];
                        nonVowels--;
                    }
                }

                String adev = "";
                for (int i = 0; i < cad.length; i++) {
                    adev+=cad[i];
                }

                mw.println(adev+" "+(cad[cad.length-1].charAt(0) -cad[0].charAt(0) ) );

            }


        }


    }

    public static boolean isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }


    public static double min(double  a, double b){
        return (a>b)?b : a;
    }

    public static int min(int  a, int b){
        return (a>b)?b : a;
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