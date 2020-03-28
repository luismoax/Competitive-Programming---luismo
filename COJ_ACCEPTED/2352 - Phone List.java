import java.io.BufferedReader;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;


/**
 * Author: Luis Manuel Díaz Barón
 * Problem: 2352 - Phone List
 * Online Judge: COJ
 * Idea: Use a Trie with modified insertion function in order to determine whether there is a common preffix 
 * between the String to insert and the ones stored before
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

    static  int [] arr;
    public static void SolveSingleProblem() throws IOException{
        int tc = sc.nextInt();
        int ccc=1;
        while(tc-->0){

            int n = sc.nextInt();

            // Trie to insert string
            Trie trie = new Trie();

            // true if all insertions were true
            boolean flag = true;

            for (int i = 0; i < n; i++) {
                // reading next string
                String s = sc.next();
                // if all insertions has gone well so far
                if(flag){
                    flag = trie.Insert(s);
                }
            }

            // answer whether or not all insertions were fine
            if(flag)
                mw.println("YES");
            else mw.println("NO");

        }

    }
}

class Trie{

    TrieNode root; // root node

    // constructor
    public Trie(){
        this.root = new TrieNode('^');
    }

    // Insertion function
    // returns true if in the insertion were found
    // no common preffix between this string and the ones stored
    // before
    public boolean Insert(String str){

        TrieNode node = this.root;

        Boolean flag = true;
        // inserting the new string
        for (int i = 0; i < str.length(); i++) {
            char c= str.charAt(i);
            // find the son with this char
            int idx = node.SonIDX(c);

            // if there is no son with that char, add it
            if(idx==-1){
                node.childs.add(new TrieNode(c));
                idx = node.childs.size()-1;
                // if is the last char, I set it as the end of a word
                if(i == str.length()-1)
                    node.childs.elementAt(idx).endOfWord = true;
            }
            // if there is a node with the current char to insert
            else{
                // if there is an end of a word
                // returns false
                if(node.childs.elementAt(idx).endOfWord)
                    flag = false;

                // if this is the last char of the string
                // and there is a node already here
                if(i == str.length()-1)
                    flag = false;
            }
            node = node.childs.elementAt(idx);
        }
        return flag;
    }
}

class TrieNode{

    public char C;
    public boolean endOfWord;
    Vector<TrieNode> childs;
    public TrieNode(char c){
        this.C = c;
        endOfWord = false;
        childs = new Vector<TrieNode>();
    }

    // index of a son with a char
    public int SonIDX(char c){
        return childs.indexOf(new TrieNode(c));
    }

    @Override
    public String toString(){
        return String.format("%c",C);
    }

    public boolean equals(Object o){
        TrieNode node2 = (TrieNode)o;
        return node2.C == this.C;
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