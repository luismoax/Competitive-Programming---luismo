import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class Main {

	/**
	 * Author: Luis Manuel Díaz Barón
	 * Problem: Interval Product
	 * Idea: We have two Fenwick Trees, one for the zeroes and other for the negatives values
	 * then we update the number of zeroes or negatives values by setting 1 or 0 in the Fenwicks
	 * so if interval [i,j] contains a 0, the result is 0
	 * else if contains an odd numbers of negatives values, the result is -
	 * otherwise +
	 */
	
	static InputReader ir;
	static OutputWriter ow;
	static String filePath="d:\\lmo.in";
	
	public static void main(String[] args) throws IOException {		
		
		ir = new InputReader(System.in);
		//ir = new InputReader(new FileReader(filePath));
		ow = new OutputWriter(System.out);		
		
		
		while(ir.CanRead()){			
			SolveSingleProblem();			
		}
		ow.close();
		
		
	}
	
	
	public static void SolveSingleProblem() throws NumberFormatException, IOException{
		
		int n = ir.NextInt();
		int k = ir.NextInt();
		FenwickTree zeros = new FenwickTree(new int[n]);
		FenwickTree negatives = new FenwickTree(new int[n]);
		
		int [] arr = new int[n];
		// Reading Data
		for(int i=0;i<n;i++){
			arr[i] = ir.NextInt();
			
			if(arr[i]<0)
				negatives.update(i+1, 1);			
			else if(arr[i]==0)
				zeros.update(i+1, 1);			
		}
		
		for(int i=0;i<k;i++){
			if(ir.Next().equals("C")){
				int idx = ir.NextInt();
				int v = ir.NextInt();
				
				if(v==0 && arr[idx-1]!=0){
					zeros.update(idx, 1);					
					if(arr[idx-1]<0)
						negatives.update(idx, -1);
				}
				
				if(v<0 && arr[idx-1]>=0){
					negatives.update(idx, 1);					
					if(arr[idx-1]==0)
						zeros.update(idx, -1);
				}
				
				if(v>0){
					if(arr[idx-1]==0)
						zeros.update(idx, -1);
					else if(arr[idx-1]<0)
						negatives.update(idx, -1);
				}
				
				arr[idx-1]=v;
			}
			else{
				int i1 = ir.NextInt();
				int i2 = ir.NextInt();
				
				if(zeros.intervalSum(i1, i2)>0)
					ow.print(0);
				else if(negatives.intervalSum(i1, i2)%2==1)
					ow.print('-');
				else ow.print('+');
			}
		}
		ow.println("");
		
	}
}


class FenwickTree{
	int [] arr;
	int [] tree;
	public FenwickTree(int arr[]){
		this.arr = arr;
		this.tree = new int[arr.length+1];
	}
	
	public void update(int idx, int v){
		for(int i= idx;i<tree.length;i+=LowBit(i))
			tree[i]+=v;		
	}
	
	public int retrieve(int idx){
		int sum=0;
		for(int i=idx;i>0;i-=LowBit(i))
			sum+=tree[i];
		return sum;
	}
	
	public int intervalSum(int i,int j){
		return retrieve(j) - retrieve(i-1);
	}
	
	int LowBit(int a){
		return a&-a;
	}
	
}

// Input Handler
class InputReader{
	
	BufferedReader br;
	StringTokenizer stk;
	public InputReader(InputStream stream){        
		br =new BufferedReader(new InputStreamReader(stream),2048);
		stk = new StringTokenizer("");
    }
	
	public InputReader(FileReader fr){
		br=new BufferedReader(fr);
		stk = new StringTokenizer("");
	}
	
	public boolean CanRead() throws IOException{
		return br.ready();
	}
	
	public String Next() throws IOException{
		while(!stk.hasMoreTokens()){
			String line = br.readLine();
			if(line==null)
				return null;
			stk = new StringTokenizer(line);			
		}
		return stk.nextToken();
	}
	
	public int NextInt() throws NumberFormatException, IOException{
		return Integer.parseInt(Next());
	}
	
	public long NextLong() throws NumberFormatException, IOException{
		return Long.parseLong(Next());
	}
	
	public double NextDouble() throws NumberFormatException, IOException{
		return Double.parseDouble(Next());
	}
	
	public BigInteger NextBigInteger() throws IOException{
		return new BigInteger(Next());
	}
	
	public int [] NextIntArray(int length) throws NumberFormatException, IOException{
		int [] arr = new int[length];
		for(int i=0;i<length;i++)
			arr[i]=NextInt();
		return arr;
	}
	
}

class OutputWriter{
	PrintWriter pw;
	
	public OutputWriter(OutputStream stream){
        pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(stream)));
    }
	
	public void printArray(Object [] array){
		for(int i=0;i<array.length;i++){
			if(i==0)
				pw.print(' ');
			pw.print(array[i].toString());
		}		
	}

	public void println(Object o){
		pw.println(o.toString());
	}

	public void print(Object o){
		pw.print(o.toString());
	}
	
	public void close(){
		pw.close();
	}
}
