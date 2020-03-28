import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

import javax.swing.text.Position;


public class Main {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		
		//FileReader fr = new FileReader("d:\\test.in");		
		Scanner sc = new Scanner(System.in);
		
		int white=0,black=0;
		while(sc.hasNext()){
			String s1 = sc.next();
			int n1 = PositionPoints(s1);
			s1 = sc.next();
			int n2 = PieceValue(s1.charAt(1));
			if(s1.charAt(0)=='W')
				white+= (n1*n2);
			else black+=(n1*n2);
		}
		System.out.println(white+" "+black);
		if(white>black)
			System.out.println("Advantage for white pieces");
		else if(black > white)
			System.out.println("Advantage for black pieces");
		else System.out.println("No decisive advantages");
		
	}
	
	static public int PieceValue(char c)
	{
		if(c=='P')
			return 1;
		if(c=='B')
			return 3;
		if(c=='N')
			return 3;
		if(c=='T')
			return 5;
		if(c=='Q')
			return 11;
		
		return 0;
	}

	static int PositionPoints(String position)
    {
        int x = 0, y = 0;
        switch (position.charAt(1))
        {
            case '1':
                x = 1;
                break;
            case '2':
                x = 2;
                break;
            case '3':
                x = 3;
                break;
            case '4':
                x = 4;
                break;
            case '5':
                x = 4;
                break;
            case '6':
                x = 3;
                break;
            case '7':
                x = 2;
                break;
            case '8':
                x = 1;
                break;                
        }

        switch (position.charAt(0))
        {
            case 'a':
                y = 1;
                break;
            case 'b':
                y = 2;
                break;
            case 'c':
                y = 3;
                break;
            case 'd':
                y = 4;
                break;
            case 'e':
                y = 4;
                break;
            case 'f':
                y = 3;
                break;
            case 'g':
                y = 2;
                break;
            case 'h':
                y = 1;
                break;
           
        }
        return Math.min(x, y);
    }
}
