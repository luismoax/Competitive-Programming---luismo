import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.TreeSet;
import java.util.Vector;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));		
		int tc = Integer.parseInt(br.readLine());
		
		for (int t = 0; t < tc; t++) {
			
			String [] data = br.readLine().split(" ");
			boolean [] arr = new boolean[data[0].length()];
			boolean cheater= false;
			for(int i=0;i<data[1].length();i++){
				int kidx = Cont(data[0], data[1].charAt(i));
				
				if(kidx!=-1)
					arr[kidx]=true;
				else{
					cheater = true;
					break;
				}
				
			}
			if(!cheater){
				
				for(int i=0;i<data[2].length();i++){
					int kidx =Cont(data[0], data[2].charAt(i)); 
				
					if( kidx!=-1)
						arr[kidx]=true;
					else{
						cheater = true;
						break;
					}
				
				}
			}
			
			//for(int i=0;i<arr.length;i++)
			//	System.out.print(arr[i]+" ");
			
			//System.out.println();
			
			
			// If was not cheater
			if(!cheater){
			
				TreeSet<Character> tree = new TreeSet<Character>();
				char [] adev = new char[data[0].length() - data[1].length() + data[2].length()];
				int index=0;
				for(int i=0;i<arr.length;i++){
					if(!arr[i]){
						adev[index] = data[0].charAt(i);
						//System.out.print(data[0].charAt(i));
						index++;
						tree.add(data[0].charAt(i));
					}
				}
					
				
				//Arrays.sort(adev);
				for(char c: tree)
					System.out.print(c);
				System.out.println();
			}
			else
				System.out.println("CHEATER");
		}
	}
	
	
	static int Cont(String s, char c)
	{
		for(int i=0;i<s.length();i++)
			if(s.charAt(i) == c)
				return i;
	
		return -1;
	}

}
