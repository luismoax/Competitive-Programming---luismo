import java.io.BufferedReader;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.*;


/**
 * Author: Luis Manuel Díaz Barón
 * Problem: 2119 - Cellphone Typing
 * Online Judge: COJ
 * Idea: Using a Trie to insert all the strings, then check for every node with multiple childs (need to type again). Watch nodes 
 * with end of the word, and having 1 child
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
        int n = sc.nextInt();
        // Trie
        Trie trie = new Trie(); 
		// Inserting string into the Trie
        for (int i = 0; i < n; i++) {
            trie.insert(sc.next());
        }
		
        double type = trie.totalTyping(); // amounts of necessary types
        double cnt = trie.size(); // amount of string into the Trie

        // Decimal formatter for the answer
        DecimalFormat df = new DecimalFormat("0.00");
        // Setting decimal separator : .
        DecimalFormatSymbols dfs = new DecimalFormatSymbols();
        dfs.setDecimalSeparator('.');
        df.setDecimalFormatSymbols(dfs);
		// printing the answer
        mw.println(df.format(type/cnt));

    }

}

class Trie{

    TrieNode root; // root node
    int count;

    // constructor
    public Trie(){
        this.root = new TrieNode('^');
    }

    public int size(){
        return this.count;
    }

    // Insertion function    
    public boolean insert(String str){

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
            }

            if(i == str.length()-1)
                node.childs.elementAt(idx).endOfWord = true;
            //
            node = node.childs.elementAt(idx);
        }
        this.count++;
        return true;
    }
	
    static int carry=0; // amount of necessary types
    public int totalTyping(){
        carry = 0;
        
		for (int i = 0; i < root.childs.size(); i++) {
            DFS(root.childs.elementAt(i),1);
        }
        return carry;
    }

	// DFS over a node carrying in cnt the current amount of types
    void DFS(TrieNode node, int cnt){
        // if completed a word, add ammount of necessary types to complete it
		if(node.endOfWord){
            carry+= cnt;
        }
        
		// if has only 1 child
		if(node.childs.size() ==1)
            if(node.endOfWord)
				// need to type again (cnt+1) to get the other word(s)
                DFS(node.childs.elementAt(0),cnt+1);
            else DFS(node.childs.elementAt(0),cnt);
        // if has more then one
		else {
			// foreach  possible branch type again (cnt+1)
            for (TrieNode child:node.childs){
                DFS(child,cnt+1);
            }
        }
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