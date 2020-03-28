import java.io.*;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.Vector;
import java.util.concurrent.PriorityBlockingQueue;
    
    
    /**
     * Author: Luis Manuel Díaz Barón
     * Problem: 2515 - Melman Cars
     * Online Judge: COJ
     * Idea: Ad-Hoc, MST. For each pair of cities (x , y) calculate LCS on its' names and set an edge from x to y with
	 * value equal to the LCS found. Then apply Kruskal and keep the value of the greatest edge on the remaining tree.
     */
    
    public class Main {
    
        static MyScanner sc;
        static MyWriter pw;
        static String filePathWin="d:\\lmo.in";
        static String filePathLinux="/media/luismo/Trabajo/lmo.in";
        public static void main(String[] args) throws IOException {
            sc = new MyScanner(System.in);
    
            // sc = new MyScanner(new FileReader(filePathWin));
            // sc = new MyScanner(new FileReader(filePathLinux));
    
            pw = new MyWriter(System.out);
    
            while(sc.canRead())
                SolveSingleProblem();
    
            pw.close();
        }
        
        
        public static void SolveSingleProblem() throws IOException{
        	int m= sc.nextInt();        	
        	Vector<Edge> edges = new Vector<Edge>(); // to store edges of the graph
        	Vector<String> names = new Vector<String>(); // to store cities' names
        	
        	for(int i = 0; i < m; i++){
        		names.add(sc.next()); // adding city name
        		
        		// creating edges
        		for(int j = 0; j < names.size() - 1; j++){
        			
        			int v = LCS(names.elementAt(i), names.elementAt(j));
        			
        			edges.add( new Edge(i, j, v) );
        		}
        	}
        	
        	int maximmun = 0;
        	// >> KRUSKAL
        	
        	// sort the edges
        	Collections.sort(edges);
        	
        	DisjointSet ds = new DisjointSet(m); // disjoint set for Kruskal
        	
        	for(int i =0 ; i < edges.size(); i++){
        		Edge e = edges.elementAt(i);
        		
        		int F = ds.setOf(e.x);
        		int S = ds.setOf(e.y);
        		
        		if(F != S){
        			ds.merge(F, S);
        			maximmun = e.v;
        		}
        	}
        	
        	// << KRUSKAL
        	
        	pw.println(maximmun + 1);        	
        }
        
        static int LCS(String a, String b){
        	int lcs[][] = new int[a.length() + 1][b.length() + 1]; // dynamic        	
        	for(int  i = 1; i < a.length() + 1; i++){
        		for(int j = 1; j < b.length() + 1; j++){        			
        			if(a.charAt(i - 1) == b.charAt(j - 1))
        				lcs[i][j] = 1 + lcs[i - 1][j - 1];        			
        			else
        				lcs[i][j] = max( lcs[i][j - 1] , lcs[i - 1][j]);        			
        		}        		
        	}
        	return lcs[a.length()][b.length()];
        }
        
        static long min(long a, long b){
            return (a < b)? a: b;
        }
        
        static int min(int a, int b){
            return (a < b)? a: b;
        }
        
        static int max(int a, int b){
            return (a > b)? a: b;
        }
        
    }
    
    class Edge implements Comparable<Edge>{
    	int x, y, v;
    	public Edge(int x, int y, int v){
    		this.x = x; this.y = y; this.v = v;
    	}
    	
    	@Override
    	public int compareTo(Edge other){
    		return this.v - other.v;
    	}
    }
    
    class DisjointSet{
    	int ds[];
    	public DisjointSet(int n){
    		ds = new int[n];
    		for(int i = 0; i < n; i++)
    			ds[i] = -1;
    	}
    	
		public int setOf(int idx){
    		int k = idx;
    		while(ds[idx] >= 0)
    			idx = ds[idx];    		
    		if(idx != k) 
    			ds[k] = idx;
    		return idx;
    	}
    	
    	public void merge(int F, int S){
    		    		
    		if(F == S)
    			return;
    		
    		if(ds[F] <= ds[S]){
    			ds[F] += ds[S];
    			ds[S] = F;
    		}
    		else{
    			ds[S] = ds[F];
    			ds[F] = S;
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
    
        public long nextLong()throws IOException{
            return Long.parseLong(next());
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