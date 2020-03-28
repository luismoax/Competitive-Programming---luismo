import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		while(n!=-1){
			int zindex = -1;
			int total =0;
			int [] arr = new int[n];
			//Reading data
			for(int i=0;i<n;i++){
				arr[i] = sc.nextInt();
				total+= arr[i];
				if(zindex == -1 && arr[i] == i+1)
					zindex = i;
			}
			//Playing game
			while(total>0 && zindex!=-1){
				arr[zindex]=0;
				int zaux = -1;
				for(int c=0;c<zindex;c++){
					arr[c]++;
					if(zaux==-1 && arr[c]== c+1)
						zaux = c;
				}
				for(int c=zindex+1;c<arr.length && zaux==-1;c++)
					if(arr[c]== c+1)
						zaux = c;					
				total--;
				zindex = zaux;
			}
			
			if(total==0)
				System.out.println("S");
			else System.out.println("N");
			
			//Reading new entry
			n = sc.nextInt();
		}		
	}
}
