import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

import javax.swing.Box.Filler;


/**
 * Author: Luis Manuel Díaz Barón
 * Problem: 2858 - Parsing Binary Strings
 * Online Judge: COJ
 * Idea: Easy, Ad-Hoc
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
    	String s = sc.next();
    	boolean flag = false;
    	String number = "";
    	for(int i =0 ; i < s.length(); i++){
    		char c = s.charAt(i);
    		
    		if(c != '0' && c != '1'){
    			
    			if(flag){    				
    				pw.print(toInt(number));
    				flag = false; number = "";
    			}
    			pw.print(c);
    			
    		}
    		else{
    			
    			flag = true;
    			number+=c;
    			
    		}
    	}
    	if(number.length() > 0)
    		pw.print(toInt(number));
    	
    }
    static int mod = 1000000007;
    static long toInt(String s){
    	long ret = 0;
    	long pw = 1;
    	for(int i = s.length() - 1; i >=0 ; i--){
    		ret+= (Integer.parseInt(String.valueOf(s.charAt(i))) * pw) % mod;
    		pw = (pw * 2) % mod;
    	}
    	return ret % mod;
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
    public double nextDouble()throws IOException{
        return Double.parseDouble(next());
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
