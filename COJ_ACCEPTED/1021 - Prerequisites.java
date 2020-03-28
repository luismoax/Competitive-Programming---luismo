import java.io.BufferedReader;
import java.util.TreeSet;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;


public class Main {

	/**
	 * @author LUISMO
	 * 
	 * Problem: 
	 * 
	 */
	static int [][]cumulative; 
	public static void main(String[] args) throws NumberFormatException, IOException {
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in) );
		Scanner sc = new Scanner(System.in);
		//int n = Integer.parseInt(br.readLine());
		
		String s="";
		while(true)
		{

			
			int k = sc.nextInt();
			if(k==0) break;
			
			int m = sc.nextInt();
			TreeSet<String> courses = new TreeSet<String>();
			//Metiendo los cursos a tomar en el arbol
			for (int i = 0; i < k; i++) {
				courses.add(sc.next());
			}
			boolean flag= true;
			//Leyendo cada categor?a
			for (int i = 0; i < m; i++) {
				int c = sc.nextInt();
				int r = sc.nextInt();

				int temp=0;
				//Leyendo los curso de esta categor?a
				for (int j = 0; j < c; j++) {
					if(courses.contains(sc.next()))
						temp++;
				}
				if(temp<r)
					flag = false;
			}			
			if(flag)
				System.out.println("yes");
			else System.out.println("no");
			
		}
		
		
	}

}

