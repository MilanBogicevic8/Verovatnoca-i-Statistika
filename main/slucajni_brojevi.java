package main;

public class slucajni_brojevi {

enum Grupa { A, B, C };

static boolean sadrzan(int[] arr, int x, int offs) {
	for (int i = 0; i < offs; i++) {
		if (arr[i] == x) return true;
	}
	return false;
}

static void domaci() {

	
	int[] arr=new int[20];
	int[] count = new int[3];
	for (int i = 0; i < 20; i++) {
		int x= (int) ((Math.random() * 1.0) * (300 - 1) + 1);
		if (sadrzan(arr, x, i)) {
			i--;
			continue;
		}
		else {
			arr[i] = x;
		}
		if (arr[i] <= 100) count[0]++;
		else if (arr[i] <= 200) count[1]++;
		else count[2]++;
	}

	System.out.print("Broj ucenika iz skole A je: " + count[0] + ". " +"To su: ");
	for (int i = 0; i < 20; i++) {
		if (arr[i] <= 100) System.out.print( arr[i] + " ");
	}
	System.out.println();
	System.out.print( "Broj ucenika iz skole B je: " + count[1] + ". " +"To su: ");
	for (int i = 0; i < 20; i++) {
		if (arr[i] > 100 && arr[i] <= 200) System.out.print( arr[i] + " ");
	}
	System.out.println();
	System.out.print("Broj ucenika iz skole C je: " + count[2] + ". " + "To su: ");
	for (int i = 0; i < 20; i++) {
		if (arr[i] > 200 && arr[i] <= 300) System.out.print(arr[i] + " ");
	}
}
	public static void main(String[] args) {

		
			domaci();
	
}
}
