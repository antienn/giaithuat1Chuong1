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
		cout << "delete successfully" << endl;
	}

	void delete1NumberinArr(danhsach& ds, int x) {
		for (int i = 0; i < ds.n; i++) {
			if (ds.arr[i] == x) {
				for (int j = i; j < ds.n; j++) {
					if (ds.arr[j] == x) {
						delete1ItemInArr(ds, j);
					}
				}
				break;
			}
		}
	}
};


int main() {
	int tmp, tmp1;
	int choose;
	danhsach ds;
	do {
		cout << "1/nhap danh sach" << endl;
		cout << "2/xuat danh sach man hinh" << endl;
		cout << "3/tim 1 phan tu trong danh sach" << endl;
		cout << "4/them 1 phan tu vao dau danh sach" << endl;
		cout << "5/them 1 phan tu vao cuoi danh sach" << endl;
		cout << "6/xoa 1 phan tu dau danh sach" << endl;
		cout << "7/xoa 1 phan tu cuoi danh sach" << endl;
		cout << "8/xoa phan tu tai vi tri thu i trong danh sach" << endl;
		cout << "9/them phan tu tai vi tri thu i trong danh sach" << endl;
		cout << "10/tim xoa phan tu thay dau tien trong danh sach" << endl;
		cout << "11/tim 1 phan tu va xoa tat ca phan tu do trong danh sach" << endl;
		cout << "12/thoat" << endl;
		cin >> choose;
		switch (choose) {
		case 1: {
			ds.input(ds);
			break;
		}
		case 2: {
			ds.output(ds);
			break;
		}
		case 3: {
			cout << "moi ban nhap 1 so can tim vi tri" << endl;
			cin >> tmp;
			ds.findIndex(ds, tmp);
			break;
		}
		case 4: {
			cout << "moi ban nhap so de them vao dau mang" << endl;
			cin >> tmp;
			ds.add1ItemInArr(ds, tmp, 0);
			break;
		}
		case 5: {
			cout << "moi ban nhap so de them vao cuoi mang" << endl;
			cin >> tmp;
			ds.add1ItemInArr(ds, tmp, ds.n);
		}
		case 6: {
			ds.delete1ItemInArr(ds, 0);
			break;
		}
		case 7: {
			ds.delete1ItemInArr(ds, ds.n);
			break;
		}
		case 8: {
			cout << "moi ban nhap vi tri  ban muon xoa" << endl;
			cin >> tmp;
			ds.delete1ItemInArr(ds, tmp);
			break;
		}
		case 9: {
			cout << "moi ban nhap vi tri  ban muon them" << endl;
			cin >> tmp;
			cout << " nhap so ban muon them" << endl;
			cin >> tmp1;
			ds.add1ItemInArr(ds, tmp1, tmp);
			break;
		}
		case 10: {
			cout << "nhap so ban muon xoa tai vi tri dau tien" << endl;
			cin >> tmp1;
			ds.delete1ItemInArr(ds, ds.findFirstIndex(ds, tmp1));
		}
		case 11: {
			cout << "nhap so ban muon xoa tat ca trong mang" << endl;
			cin >> tmp1;
			ds.delete1NumberinArr(ds, tmp1);
			break;
		}
		case 12: {
			cout << "thanks for using" << endl;
			break;
		}
		default:
			cout << "error choose, pls choose again" << endl;
			break;
		}
	} while (choose != 12);
	return 0;
}