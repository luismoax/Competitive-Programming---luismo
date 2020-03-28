import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.Vector;


public class Main {

	/**
	 * @throws IOException 
	 * @throws NumberFormatException 
	 * @LUISMO
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		for(int t=0;t<n;t++){
			
			String [] arrStr = br.readLine().split(" ");
			String id = arrStr[0];
			Vector<String> name = new Vector<String>();
			for(int i =1;i< arrStr.length;i++){
				name.add(arrStr[i]);
			}
			
			System.out.print(id.substring(0,2));
			
			for(int i=name.size()-1;i>=0;i--){
				if(i<name.size()-1)
					System.out.print("*"+name.elementAt(i));
				else System.out.print(name.elementAt(i));
			}
			
			System.out.println(id.substring(2,4));
			
		}
	}

}
