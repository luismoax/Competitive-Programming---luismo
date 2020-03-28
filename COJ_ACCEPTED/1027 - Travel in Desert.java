import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;

/**
 *
 * @author LUISMO
 */
public class Main {

    /**
     * @param args the command line arguments
     */
	static double [] temperatures;
	static double [] di;
	static int [] pi;
    public static void main(String[] args) throws FileNotFoundException {
        //FileReader fr = new FileReader("d:\\travel in desert.lmo");        
    	Scanner sc = new Scanner(System.in);
    	
    	while (sc.hasNext()) {

    		
            int n = sc.nextInt();
            int e = sc.nextInt();
            int s = sc.nextInt()-1;
            int t = sc.nextInt()-1;
            
            //Listas de adyacencia
            Vector<Vector<Edge>> ady = new Vector<Vector<Edge>>();
            for(int i=0;i<n;i++)
            	ady.add(new Vector<Edge>());
                    
            //Leyendo las aristas
            for(int i=0;i<e;i++){
            	int x = sc.nextInt()-1;
            	int y = sc.nextInt()-1;
            	double temperature = sc.nextDouble();
            	double distance = sc.nextDouble();
            	
            	ady.elementAt(x).add(new Edge(x, y, temperature, distance));
            	ady.elementAt(y).add(new Edge(y, x, temperature, distance));
            }
            
            //Llamamos al Dijkstra de la Temperatura
            DijkstraTemperature(ady, s);
            //Llamamos al Dijkstra de la Distancia
            DijkstraDistance(ady, s, t);
            //Imprimimos el Camino hacia atras
            Vector<Integer> path = new Vector<Integer>();
            path.add(t+1);
            int k =t;
            while (pi[k]>=0) {
    			path.add(pi[k]+1);
    			k= pi[k];
    		}
            for(int i=0;i<path.size();i++)
            	if(i==0) System.out.print(path.elementAt(path.size()-1));
            	else System.out.print(" "+path.elementAt(path.size()-1-i));
            System.out.println();
            System.out.println(di[t]+" "+temperatures[t]);
		}
    	
    }
    
    static void DijkstraTemperature(Vector<Vector<Edge>> ady,int s){
    	//ISS
    	int n = ady.size();
    	boolean [] taken = new boolean[n];
    	temperatures = new double[n];
    	for(int i =0;i<n;i++){
    		temperatures[i]= Double.MAX_VALUE;
    	}
    	temperatures[s]=0;
    	taken[s] = true;
    	int lastTaken = s;
    	for(int i=0;i<n;i++){
    		//Por c\ arista del ultimo nodo tomado "relajo"
    		for (int j = 0; j < ady.elementAt(lastTaken).size(); j++) {
				Edge e = ady.elementAt(lastTaken).elementAt(j);
				double tmp = temperatures[lastTaken];
				//Si la temperatura de esta arista es mayor que la del
				//?ltimo nodo tomado la actualizo
				if(e.temperature>tmp)
					tmp = e.temperature;
				//Si la temperatura tmp es menor que la del nodo al que voy
				//la actualizo
				if(tmp<temperatures[e.y])
					temperatures[e.y] = tmp;				
			}
    		//Seleccionando el siguiente nodo
    		int index = -1;
    		double mxVal = Double.MAX_VALUE;
    		for (int j = 0; j < temperatures.length; j++) {
				if(!taken[j] && temperatures[j]<mxVal){
					mxVal = temperatures[j];
					index = j;
				}					
			}
    		//Si pude cojer otro nodo
    		if(index!=-1){
    			taken[index]=true;
    			lastTaken = index;
    		}
    	}
    	
    }

    static void DijkstraDistance(Vector<Vector<Edge>> ady,int s,int t){
    	//ISS
    	int n = ady.size();
    	boolean [] taken = new boolean[n];
    	di = new double[n];
    	pi = new int[n];
    	for (int i = 0; i < n; i++) {
    		di[i] = Double.MAX_VALUE;
    		pi[i]=-1;    		
		}
    	di[s]= 0;
    	taken[s] = true;
    	int lastTaken = s;

    	
    	for(int i=0;i<n;i++){
    		//Por c\ arista del ?ltimo nodo tomado
    		for (int j = 0; j < ady.elementAt(lastTaken).size(); j++) {
				//Si la temperatura de esta es menor que la que me hace falta para llegar
    			//al destino la relajo, en otro casi sigue la iteracion
    			Edge e = ady.elementAt(lastTaken).elementAt(j);
    			//Relajo por distancia
    			if(e.temperature<=temperatures[t]){
    				
    				if(!taken[e.y] && di[lastTaken]+e.distance < di[e.y]){
    					di[e.y] = di[lastTaken] + e.distance;
    					pi[e.y] = lastTaken;    					    					
    				}
    			}
			}
    		
    		//Escojo el de menor distancia
    		int index = -1;
    		double mxDist = Double.MAX_VALUE;
    		for (int j = 0; j < di.length; j++) {
				if(!taken[j] && di[j]<mxDist){
					mxDist = di[j];
					index = j;
					
				}
			}
    		//
    		if(index !=-1){
    			taken[index] = true;
    			lastTaken = index;
    		}
    	}

    }
    
}

class Edge
{
	int x;
	int y;
	double temperature;
	double distance;
	public Edge(int x,int y,double temperature,double distance){
		this.x = x;
		this.y = y;
		this.temperature = temperature;
		this.distance = distance;
	}
}