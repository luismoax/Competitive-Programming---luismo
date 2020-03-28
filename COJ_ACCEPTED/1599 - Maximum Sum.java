import java.io.FileNotFoundException;
import java.io.FileReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Collection;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.Vector;


import javax.swing.text.Position;


public class Main {

	/**
	 * @author LUISMO
	 * 
	 * IDEA: En este ejercicio la cuesti�n es ir formando rect�ngulos de P*Q (1<=P<=n , 1<=Q<=n) e ir moviendo 
	 * esa �rea a trav�s del �rea total y calcular su suma, si calcul�ramos esta suma recorriendo el �rea de P*Q,
	 * el orden ser�a O(n^6) por tanto hay que mejorar este �ltimo paso.
	 * Aqu� lo que hago para optimizar el c�lculo de la suma en un �rea de P*Q, es mientras me va entrando los datos, 
	 * llevar en una matriz aparte las sumas por columnas es decir en la columna j en la i-�sima fila tengo sumados
	 * todos los valores desde los �ndices 0 hasta i. Luego lo que hago es sumar estos valores de las columnas pero en filas, 
	 * de manera que en la posici�n i,j de esta matrz estar� el valor de la suma total de la sumas de todas las 
	 * columnas hasta la fila i. Una vez que tengo esto hallar la suma de un rect�ngulo cuya esquina superior izquierda
	 * est� en i,j y sus dimensiones son p*q, lo que hago es ir a la posici�n (i+p-1,j+q-1) y restarle los valores en 
	 * (i-1,j+q-1) y el valor en (i+p-1,j-1) menos el valor en (i-1,j-1). Gr�ficamente se ve mejor.
	 * 
	 * @Complejidad: O(n^4)
	 */
	static int [][] cumulative ;
	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int [][] mt = new int[n][n];
		cumulative = new int[n][n];
		
		// Leyendo los datos
		for(int i =0;i<n;i++){			
			for (int j = 0; j < n; j++) {
				mt[i][j] = sc.nextInt();
				cumulative[i][j] = mt[i][j];
				if(i>0)
					cumulative[i][j] +=cumulative[i-1][j];				
			}			
		}
		// Actualizando sumas acumulativas por filas
		for(int i =0;i<n;i++){			
			for (int j = 0; j < n; j++) {		
				if(j>0)
					cumulative[i][j] +=cumulative[i][j-1];				
			}
		}
		
		int max = 0;
		//O(n^4)
		// Dimensiones del rect�ngulo a mover
        for (int cntRow = 1; cntRow <= n; cntRow++){
        	
            for (int cntCol = 1; cntCol <= n; cntCol++){
				
				//Movi�ndome en las posiciones del rect�ngulo original
                for (int c = 0; c + cntRow <= n; c++)
                {
				
                    for (int d = 0; d + cntCol <= n; d++){
                        // Calculo la suma del rect�ngulo
						int val = Sum(c, d, cntRow, cntCol);
                        // Actualizo el mejor valor
						if (val > max)
                            max = val;
                    }
                }
            }
        }

        //Imprimo la respuesta
        System.out.println(max);        
	}
	
	//M�todo que me calcula la suma en  un rect�ngulo cuya esquina superior izquierda es i,j y tiene
	//cntRow filas y cntCol columnas 
	//O(1)
	static int Sum(int i,int j,int cntRow,int cntCol){
		int k1 = 0;
        if (i > 0 && j>0)
        {
            k1 = cumulative[i - 1][ j + cntCol - 1] + cumulative[i+cntRow-1][j-1] - cumulative[i-1][j-1];
        }            
        else if (j > 0)
        {
            k1 = cumulative[i + cntRow - 1][ j - 1];
        }
        else if (i > 0)
        {
            k1 = cumulative[i - 1][ j + cntCol - 1];
        }
        return cumulative[i + cntRow - 1][j + cntCol - 1] - k1;
	}
    
}
