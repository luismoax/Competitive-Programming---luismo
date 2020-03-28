import java.io.BufferedReader;
import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;


/**
 * Author: Luis Manuel Díaz Barón
 * Problem: 3540 - Exactly K Times
 * Online Judge: COJ
 * Idea: Use a Trie, store in each node the number of times it is visited during an insertion
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

        //while(sc.canRead())
        SolveSingleProblem();

        mw.close();
    }

    public static void SolveSingleProblem() throws IOException{

        Trie tree = new Trie();

        int k = sc.nextInt();
        String str = sc.next();

        for (int i = 0; i < str.length(); i++) {
            tree.insert(str.substring(i));
        }

        int answ = tree.count(k);

        if(answ == 0) answ = -1;

        mw.println(answ);
        //tree.DFS();
    }
}

class Node{
    public char c;
    public Node [] alph;
    int cnt;

    public Node(char c){
        this.c = c;
        alph = new Node[26];
        cnt = 1;
    }
}

class Trie{

    Node root;
    public Trie(){
        root = new Node('$');
    }

    int global;


    public void insert(String str){

        Node current = root;

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            int idx = c - 'a';

            if(current.alph[idx] == null){
                current.alph[idx] = new Node(c);
            }
            else{
                current.alph[idx].cnt++;
            }
            current = current.alph[idx];
        }
    }

    public void DFS(){

        DFS(root, "");
    }

    void DFS(Node n, String s){
        //System.out.println(n.c + " " + n.cnt);
        System.out.println(s + " " + n.cnt);

        for (int i = 0; i < 26; i++) {
            if(n.alph[i] != null)
                DFS(n.alph[i], s + n.c);
        }
    }

    public int count(int k){
        global = 0;
        count(root, k, 0);
        return global;
    }

    void count(Node n, int k, int len){
        if(n.cnt == k){
            if(len > global)
                global = len;
        }


        int aux = 0;
        for (int i = 0; i < 26; i++) {
            if(n.alph[i] != null){
                count(n.alph[i], k, len + 1);
            }
        }
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

    public BigInteger nextBigInteger() throws IOException{
        return new BigInteger(this.next());
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
            else println(" " + arr[i]);

        }
    }


    public void printVectorInteger(Vector<Integer> arr){
        for(int i=0;i<arr.size();i++){

            if(i==0)
                print(arr.elementAt(i));
            else print(" " + arr.elementAt(i));

        }
    }

    public void printVectorLong(Vector<Long> arr){
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