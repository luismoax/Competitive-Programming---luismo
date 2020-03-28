import java.io.BufferedReader;
	import java.io.FileReader;
	import java.io.IOException;
	import java.io.InputStreamReader;
	import java.io.PrintWriter;
	import java.math.BigInteger;
	import java.util.LinkedList;
	import java.util.StringTokenizer;
	
	public class Main {
	
		/**
		 * LUISMO'S Java Template
		 * 
		 * Name: Luismo
		 * Problem: Bessie Weight Problem
		 * Online Judge:
		 * Idea: Dynamic I keep an array with the possible weigths 0...H, where i mark
		 * if there's a way of achieving that weight, first i begin with 0 marked as true
		 * (I can always achive 0 weight) 
		 * then foreach hay bale i sum it to the possible achieved weights (every marked cell before this iteration)
		 * and mark that sum as a possible weight to achieve.
		 * I take the maximun weight achieved
		 * 
		 */
		static StringTokenizer stk = new StringTokenizer("");
		
		static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		static PrintWriter pw = new PrintWriter(System.out);
		
		public static void main(String[] args) throws NumberFormatException, IOException {		
			new Main().Run();
		}		
		
		void Run() throws NumberFormatException, IOException{
			int h = NextInt();
			int n = NextInt();
			int [] hayBales = new int[n]; // Array for hay bales
			int [] weights = new int[h+1]; // Array to mark the achieven weights
			// Reading Data
			for(int i=0;i<n;i++){
				hayBales[i] = NextInt();				
			}
			
			weights[0] = 1; // We can always achieve 0 weight 
			int maxVal = 0; // Maximun value
			
			
			for(int i=0;i<n;i++) // Foreach hay bale 
				for(int j=0;j<=h;j++){ 
					// Search through the possible weights to achieve
					if(weights[j]>0 && weights[j]<i+2){
						int nextWeight = hayBales[i]+j;
						if(nextWeight<=h && weights[nextWeight]==0){
							weights[nextWeight] = i+2;
							if(nextWeight> maxVal)
								maxVal=nextWeight;
						}
					}					
				}
	
			// Answer
			pw.println(maxVal);		
			pw.close();
		}
		
		// Input/Output
		static String Next() throws IOException{
			// While the StringTokenizer si empty
			// read another line
			while(stk.countTokens()==0)
				stk = new StringTokenizer(br.readLine());
			// return the next Token
			return stk.nextToken();
		}
		
		static int NextInt() throws NumberFormatException, IOException{
			return Integer.parseInt(Next());
		}
		
		static long NextLong() throws NumberFormatException, IOException{
			return Long.parseLong(Next());
		}
		
		static BigInteger NextBigInteger() throws IOException{
			return new BigInteger(Next());
		}
		
		static double NextDouble() throws NumberFormatException, IOException{
			return Double.parseDouble(Next());
		}
		
		
		//Math Methods
		static int ABS(int a){
			if(a<0)
				return a*-1;
			return a;
		}	
		
		static int Min(int a,int b){
			if(a<b)
				return a;
			return b;
		}
		
			
		// Printing Methods
		static void PrintMt(boolean [][] mt){
			for (int i = 0; i < mt.length; i++) {
				for (int j = 0; j < mt[0].length; j++) {
					if(mt[i][j])
						System.out.print("X ");
					else System.out.print("0 ");
				}
				System.out.println();
			}
			System.out.println();		
		}
		
		
	}
	
	
	
	class Pair{
		public int x,y;
		public Pair(int x,int y){
			this.x = x;
			this.y = y;
		}	
	}
	
	class Point{
		public int x,y;
		public Point(int x,int y){
			this.x = x;
			this.y = y;
		}
		public double EuclideanDistance(Point p1){
			return Math.sqrt(  p1.x-this.x*p1.x-this.x + p1.y-this.y*p1.y-this.y );
		}
	}
