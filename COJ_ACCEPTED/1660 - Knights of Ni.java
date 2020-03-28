import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.Vector;


import javax.swing.text.Position;


public class Main {	
	
	/**
	 * @author LUISMO
	 * 
     * Idea: The main idea here is to calculate the minimun distance from Knight's base to the 
     * strawberries and do the same for Bessie, so the best path for Bessie to choose is the one
     * where the path to strawberrie x plus the path from x to Knight's base is minimum
	 *  
	 */
	
	public static void main(String[] args) throws IOException {
		
		//FileReader fr = new FileReader("d:\\lmo.in");		
		//Scanner sc = new Scanner(System.in);
		//BufferedReader br = new BufferedReader(fr);
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));		
		StringTokenizer stk = new StringTokenizer(br.readLine());
		int w = Integer.parseInt(stk.nextToken());
		int h = Integer.parseInt(stk.nextToken());
		
		int [][]forest = new int[h][w];
		
		Pair bessie = new Pair(0,0);
		Pair knights = new Pair(0,0);
		
		int strawberriesCount=0;
		// Filling the forest matrix
		for (int i = 0; i < h; i++) {
			
			int lim =w/40;
			if(w%40>0) lim ++;
			
			for (int j = 0; j < lim; j++) {
				stk = new StringTokenizer(br.readLine());
				int cnttokens = stk.countTokens(); // Count of tokens
				for (int k = 0; k < cnttokens; k++) {
										
					forest[i][j*40+k] = Integer.parseInt(stk.nextToken());
															
					if(forest[i][j*40+k] == 2) bessie = new Pair(i,j*40+k);
					else if(forest[i][j*40+k] == 3) knights = new Pair(i,j*40+k);
					else if(forest[i][j*40+k] == 4) strawberriesCount++;					
					
				}
			}
		}
		
		// Directional Arrays
		int [] xs = {0,0,1,-1};
		int [] ys = {1,-1,0,0};
		int cnt=0; // cnt will count the number of strawberries visited in the BFS
		
		// BFS for Knights
		int [][] kBFS  = new int[h][w];
		LinkedList<Pair> q = new LinkedList<Pair>();
		q.addFirst(knights);
		
		while(q.size()>0 && cnt < strawberriesCount){
			
			Pair p = q.getLast();
			q.removeLast();
			
			// Visiting adyacents cell to p
			for (int i = 0; i < 4; i++) {
				
				int tmpx = p.x+xs[i] , tmpy = p.y+ys[i]; // Next positions
				// If is a valid Cell and is not the knights' one, and has not been visited
				if(tmpx>=0 && tmpx < h && tmpy>=0 && tmpy<w && (tmpx!=knights.x || tmpy!=knights.y) && forest[tmpx][tmpy]!=1 && kBFS[tmpx][tmpy]==0){
					
					kBFS[tmpx][tmpy] = kBFS[p.x][p.y]+1;
					
					if(forest[tmpx][tmpy] == 4) strawberriesCount++;
					
					// Enqueue this cell
					q.addFirst(new Pair(tmpx,tmpy));
				}				
			}			
		}
		
		
		// --------------------- //
		
		// BFS for Bessie
		int [][] bBFS  = new int[h][w];
		q = new LinkedList<Pair>();
		q.addFirst(bessie);
		cnt=0; // reset the strawberries counter
		
		int min=Integer.MAX_VALUE; // the minimun value of a path from bessie to a strawberry and then to the knights
		
		while(q.size()>0 && cnt < strawberriesCount){
			
			Pair p = q.getLast();
			q.removeLast();
			
			// Visiting adyacents cell to p
			for (int i = 0; i < 4; i++) {
				
				int tmpx = p.x+xs[i] , tmpy = p.y+ys[i]; // Next positions
				// If is a valid Cell and is not the bessie's one, and has not been visited
				if(tmpx>=0 && tmpx < h && tmpy>=0 && tmpy<w && (tmpx!=bessie.x || tmpy!=bessie.y) && forest[tmpx][tmpy]!=1 && bBFS[tmpx][tmpy]==0){
					
					bBFS[tmpx][tmpy] = bBFS[p.x][p.y]+1;
					
					// If found a strawberrie, calculate the sum of the best path to the knights plus
					// the besta path to bessie
					if(forest[tmpx][tmpy] == 4){ 
						strawberriesCount++;
						if(kBFS[tmpx][tmpy]+bBFS[tmpx][tmpy] < min)
							min = kBFS[tmpx][tmpy]+bBFS[tmpx][tmpy];
					}					
					// Enqueue this cell
					q.addFirst(new Pair(tmpx,tmpy));
				}				
			}		
		}
		
		// Print best Value
		System.out.println(min);
		
	}
    
}

class Pair{
	public int x,y;
	public Pair(int x, int y){
		this.x = x;
		this.y = y;
	}	
}
