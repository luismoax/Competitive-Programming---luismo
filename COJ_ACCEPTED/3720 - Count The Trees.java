/**
  Author: Luis Manuel Díaz Barón
  Problem: 3720 - Count The Trees
  Online Judge: COJ
  Idea: Combinatorics + DP. First of all calculate the number of binary trees that can be formed with N nodes 	using Dynamic Programming.
  dp[i] - number of trees with exactly i nodes
  dp[i] = Sum from j = 0 to j = i -1 of (dp[j] * dp[i - 1 - j)
  The for each binary tree of N nodes, we can label it in N! ways
  So the final answer is:
	N! * dp[N]
 
 */

 

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		BigInteger [] dp = new BigInteger[305];
		
		// DP
		dp[0] = new BigInteger("1");
		dp[1] = new BigInteger("1");	
		
		for(int i = 2; i <= 300; i++){
			dp[i] = new BigInteger("0");
			for(int j = 0; j < i; j++){
				
				BigInteger k = dp[j].multiply(dp[i - 1 - j]);
				dp[i] = dp[i].add(k);				
			}
		}
		
		// Factorials
		BigInteger fact[] = new BigInteger[301];
		fact[0] = new BigInteger("1");
		for(int i = 1; i <= 300; i++)
			fact[i] = fact[i - 1].multiply(new BigInteger(String.valueOf(i)));
		
		int x = Integer.parseInt(br.readLine());
		
		while(x != 0){
			System.out.println(fact[x].multiply(dp[x]));
			x = Integer.parseInt(br.readLine());
		}		
	}		

}
