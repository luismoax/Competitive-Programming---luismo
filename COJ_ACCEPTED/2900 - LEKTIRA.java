import java.io.*;
import java.math.BigInteger;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

import javax.swing.Box.Filler;


/**
 * Author: Luis Manuel Díaz Barón
 * Problem: 2900 - LEKTIRA
 * Online Judge: COJ
 * Idea: Easy String Manipulation
 * Fecha: 20/02/2013
 */

public class Main {

    static MyScanner sc;
    static MyWriter pw;
    static String filePath="//media//luismo//Trabajo//lmo.in";
    public static void main(String[] args) throws IOException {
        sc = new MyScanner(System.in);
        // sc = new MyScanner(new FileReader(filePath));
        pw = new MyWriter(System.out);
        
        while(sc.canRead())
            SolveSingleProblem();

        pw.close();
    }
    
    public static void SolveSingleProblem() throws IOException{
    	PriorityQueue<String> heap = new PriorityQueue<>();
    	String word= sc.next();
    	
    	for(int i = 1; i < word.length(); i++){
    		
    		for(int j = i + 1; j < word.length(); j++){
    			
    			String aux = "";
			// Reverse first segment
    			for(int k = i - 1; k >=0; k--)
    				aux+= word.charAt(k);
			// Reverse second segment    				
    			for(int k = j - 1; k >= i; k--)
    				aux+= word.charAt(k);
			// Reverse third segment    			
    			for(int k = word.length() - 1; k >= j; k--)
    				aux+= word.charAt(k);
    			
    			heap.add(aux);
    		}    		
    	}
    	if(heap.size() == 0) 
    		pw.println(word);
    	else pw.println(heap.peek());
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
    public boolean canRead() throws IOException{
        return br.ready();
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
    public void close() {
        pw.close();
    }
}
