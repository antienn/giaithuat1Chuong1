#include<iostream>
using namespace std;
struct danhsach {
	int arr[100];
	int n;
	void input(danhsach& ds) {
		cout << "moi ban nhap so luong phan tu" << endl;
		cin >> ds.n;
		for (int i = 0; i < ds.n; i++) {
			cout << "arr[" << i << "]= ";
			cin >> ds.arr[i];
		}
	}

	void output(danhsach ds) {
		cout << "mang arr gom: " << endl;
		for (int i = 0; i < ds.n; i++) {
			cout << "arr[" << i << "]= " << ds.arr[i] << endl;
		}
	}

	void findIndex(danhsach ds, int x) {
		cout << "so " << x << " xuat hien tai vi tri: ";
		for (int i = 0; i < ds.n; i++) {
			if (ds.arr[i] == x) {
				cout << i << " ";
			}
		}
		cout << endl;
	}

	int findFirstIndex(danhsach ds, int x) {
		cout << "so " << x << " xuat hien tai vi tri: ";
		for (int i = 0; i < ds.n; i++) {
			if (ds.arr[i] == x) {
				return i;
			}
		}
		cout << endl;
	}

	void add1ItemInArr(danhsach& ds, int x, int index) {
		for (int i = ds.n; i >= index; i--) {
			ds.arr[i] = ds.arr[i - 1];
		}
		ds.arr[index] = x;
		ds.n++;
		cout << "add successfully" << endl;
	}

	void delete1ItemInArr(danhsach& ds, int index) {
		for (int i = index; i < ds.n; i++) {
			ds.arr[i] = ds.arr[i + 1];
		}
		ds.n--;
	}

	void delete1NumberinArr(danhsach& ds, int x) {
		for (int i = 0; i < ds.n; i++) {
			if (ds.arr[i] == x) {
				delete1ItemInArr(ds, i);
				i--;
			}
		}
	}
};

