import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.TreeSet;


public class Main {
	/**
	 * @author LUISMO
	 */
	public static void main(String[] args) throws IOException {
		
		//FileReader fr = new FileReader("d:\\in.lmo");		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		TreeSet<Integer> ts = new TreeSet<Integer>();		
		int tc = Integer.parseInt(br.readLine());
		
		for(int t=0;t<tc;t++){
			ts.clear();			
			int n = Integer.parseInt(br.readLine());
			boolean flag = false;
			for(int i =0;i<n;i++){
				int ki = Integer.parseInt(br.readLine());
				if(!ts.add(ki)){
					flag = true;
					System.out.println(ki);
				}
			}
			if(!flag)
				System.out.println("Not found!");
			
			
		}
	}

}