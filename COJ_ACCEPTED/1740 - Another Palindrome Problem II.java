import java.io.BufferedReader;
import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;


/**
 * Author: Luis Manuel Díaz Barón
 * Problem: 1740 - Another Palindrome Problem II
 * Online Judge: COJ
 * Idea: Use a Dynamic method O(N^2) to count all palindormes substring in the original string, and for each index: idx, store the number of palindromes that
 * can be found from 0 to idx, the if you find a palindorme at position x, he can be paired with all the palindromes from 0 to x-1, thus count them all
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

        
        while(sc.canRead())
            SolveSingleProblem();

        mw.close();
    }


    public static void SolveSingleProblem() throws IOException{
        // mw.println(2147483647 == Integer.MAX_VALUE);
        String str = sc.next();
        int n = str.length();

		// matrix, cell[i][j] = 1 if there a palindrome starting at
		// position i with length j, otherwise = 0
        int [][] mt = new int[n][n + 1];
		// amount of palindormes that start at position i
        int [] begin = new int[n];
		// amount of palindormes that finish at position i
        int [] finish = new int[n];

        for (int i = 0; i < n; i++) {
            // setting palindromes of length 0 (empty string)
			mt[i][0] = 1;
			// setting palindromes of length 1 (base case)
            mt[i][1] = 1;

			// setting starting and finished indexes
			// of palindromes of length 1
            begin[i] = 1;
            finish[i] = 1;
        }

        // COUNTING PALINDORMES
		// foreach possible length
        for (int j = 2; j <= n; j++) {
			
			// foreach possible start
            for (int i = 0; i < n - j + 1; i++) {
                int leftIdx = i; // begin index
                int rightIdx = i + j - 1; // last index

				// if first and last characters match and the substring between them is a palindrome
				// set mt[i,j] as a palindrome
                if(str.charAt(leftIdx) == str.charAt(rightIdx) && mt[i+1][j - 2]==1){
                    mt[i][j] = 1;

					// increase the amount of palindromes that start at position leftIdx
					// and the amount that finish at position rightIdx
                    begin[leftIdx]++;
                    finish[rightIdx]++;
                }
            }
        }
        // END COUNTING PALINDORMES
		
        long answer = 0; 
		// cumulative table for the finish indexes
        int [] finishedSums = new int[n];
        //
        finishedSums[0] = finish[0];
		
		// foreach index: i, add the number of palindromes starting at position i multiplied by
		// the number of palindromes that finish before index i
        for (int i = 1; i < n; i++) {
            finishedSums[i] = finishedSums[i-1] + finish[i];
            answer += (begin[i] * finishedSums[i-1]);
        }
        mw.println(answer);
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