#include <iostream>

using namespace std;

int sadrzan(int* arr, int x, int offs) {
	for (int i = 0; i < offs; i++) {
		if (arr[i] == x) return 1;
	}
	return 0;
}
void domaci() {
	srand(time(0));

	enum Grupa { A, B, C };
	int arr[20];
	int count[3] = { 0 };
	for (int i = 0; i < 20; i++) {
		int x= (rand() * 1.0) / RAND_MAX * (300 - 1) + 1;
		if (sadrzan(arr, x, i)) {
			i--;
			continue;
		}
		else {
			arr[i] = x;
		}
		if (arr[i] <= 100) count[A]++;
		else if (arr[i] <= 200) count[B]++;
		else count[C]++;
	}

	cout << "Broj ucenika iz skole A je: " << count[A] << ". " << "To su: ";
	for (int i = 0; i < 20; i++) {
		if (arr[i] <= 100) cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Broj ucenika iz skole B je: " << count[B] << ". " << "To su: ";
	for (int i = 0; i < 20; i++) {
		if (arr[i] > 100 && arr[i] <= 200) cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Broj ucenika iz skole C je: " << count[C] << ". " << "To su: ";
	for (int i = 0; i < 20; i++) {
		if (arr[i] > 200 && arr[i] <= 300) cout << arr[i] << " ";
	}
}

void prosirenje() {
	// bira se m ucenika iz n skola, gde svaka ima k ucenika
	srand(time(0));
	cout << "Unesite koliko se ucenika bira:"; int m = 0; cin >> m;// cout << endl;
	cout << "Unesite koliko ima skola:"; int n = 0; cin >> n; cout << endl;
	//u nizu arr se nalazi zbir svih brojeva u nizu pre tog indeksa
	int* arr = new int[n+1] {0};
	int num = 0;
	for (int i = 1; i < n+1; i++) {
		cout << "Unesite broj ucenika u " << i << "." << " skoli:"; 
		cin >> arr[i]; num += arr[i];
		if (i > 0) arr[i] = arr[i] + arr[i - 1];
		
	}


	int* ucenici = new int[m];
	int* skola = new int[n] {0};
	for (int i = 0; i < m; i++) {
		int x= (rand() * 1.0) / RAND_MAX * (num-1) + 1;
		if (sadrzan(ucenici, x,i)) {
			i--;
			continue;
		}
		else {
			ucenici[i] = x;
		}
		for (int j = 0; j < n+1; j++) {
			if (arr[j]<ucenici[i] && ucenici[i] <= arr[j+1]) {
				skola[j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << "Broj ucenika iz " << i + 1 << "." << " skole je:" << skola[i];
		cout << " To su:";
		for (int j = 0; j < m; j++) {
			if (ucenici[j]>arr[i] && ucenici[j] <= arr[i+1]) {
				cout << ucenici[j] << " ";
			}
		}
		cout << endl;
	}
}
int main() {
	int i = 0;
	cout << "Unesite jedan ako hocete domaci, odnosno nulu za prosirenje:"; cin >> i;
	if (i) {
		domaci();
	}
	else {
		prosirenje();
	}
	return 0;
}