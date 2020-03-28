import java.util.Scanner;

public class Main
{

	/**
	 * @param args
	 */
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for (int c = 0; c < tc; c++)
		{
			int n = sc.nextInt();
			int[] arr = new int[n];
			for (int j = 0; j < n; j++)
				arr[j] = sc.nextInt();

			int k = 0;

			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
					if (arr[i] > arr[j])
					{
						// System.out.println(arr[i] + " " + arr[j]);
						k++;
						int aux = arr[i];
						arr[i] = arr[j];
						arr[j] = aux;
					}

			// Imprimo respuesta
			System.out.printf("Optimal train swapping takes %d swaps.\n", k);

		}
	}

}
