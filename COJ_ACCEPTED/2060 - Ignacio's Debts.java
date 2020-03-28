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
			int cnt=0,cumul=0;
			for(int i=0;i<n;i++){
				cumul+=sc.nextInt();
				if(cumul%100==0)
					cnt++;
			}
			System.out.println(cnt);
			n = sc.nextInt();
		}		
	}
}
