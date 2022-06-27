#include<iostream>

using namespace std;

struct number {
	int integer;
	number* next;
};

number* createNumber(int x) {
	number* temp = new number;
	temp->next = NULL;
	temp->integer = x;
	return temp;
}
number* addStart(number* l, int x) {
	if (l == NULL) {
		number* p = createNumber(x);
		return p;
	}
	number* temp = new number;
	temp->integer = x;
	temp->next = l;
	l = temp;
	return l;
}
number* addEnd(number* l, int x) {
	if (l == NULL) {
		number* q = createNumber(x);
		return q;
	}
	number* p = l;
	while (p->next != NULL) {
		p = p->next;
	}
	number* temp = new number;
	temp->integer = x;
	temp->next = NULL;
	p->next = temp;
	return l;
}

void printList(number* l) {
	number* p = l;
	while (p != NULL) {
		cout << p->integer << " ";
		p = p->next;
	}
	cout << endl;
}
void find(number* l, int x) {
	int count = 0;
	number* p = l;
	cout << "danh sach vi tri cua so " << x << " : ";
	while (p != NULL ) {
		count++;
		if (p->integer == x) {
			cout <<count <<" ";
		}
		p = p->next;
	}
	cout << endl;
}
number* deleteStart(number* l) {
	number* p = l;
	l = l->next;
	cout << "delete successful !" << endl;
	return l;
	delete p;
}
number* deleteEnd(number* l) {
	number* p = l;
	number* q = NULL;
	while (p->next != NULL) {
		q = p;
		p = p->next;
	}
	q->next = NULL;
	cout << "delete successful !" << endl;
	return l;
	delete p;
}
number* deleteIndex(number* l,int index) {
	int count = 1;
	number* p = l;
	number* q = NULL;
	if (index == 1) {
		l = deleteStart(l);
		return l;
	}
	else {
		while (count != index) {
			q = p;
			p = p->next;
			count++;
		}
		q->next = p->next;
		cout << "delete successful !" << endl;
		delete p;
		return l;
	}
}

number* deleteNumber(number* l, int num) {
	number* q = NULL;
	number* p = l;
	while (p->next != NULL && p->integer != num) {
		q = p;
		p = p->next;
	}
	q->next = p->next;
	delete p;
	return l;
}
number* deleteAllNumber(number* l, int num) {
	number* q = NULL;
	number* p = l;
	while (p->next != NULL) {
		q = p;
		p = p->next;
		if (p->integer == num) {
			q->next = p->next;
			delete p;
		}
	}
	return l;
}
number* interChangeSort(number*& l) {
	for (number* q = l; q != NULL; q = q->next) {
		for (number* p = q->next; p != NULL; p = p->next) {
			if (p->integer < q->integer) {
				int tmp = p->integer;
				p->integer = q->integer;
				q->integer = tmp;
			}
		}
	}
	return l;
}

int main() {
	int tmp;
	int choose;
	number* first = NULL;
	do {
		cout << "nhap so nguyen: ";
		cin >> tmp;
		if (tmp != 0) {
			first = addEnd(first, tmp);
		}
	} while (tmp != 0);
	printList(first);
	do {
		cout << "1/xuat danh sach man hinh" << endl;
		cout << "2/tim 1 phan tu trong danh sach" << endl;
		cout << "3/them 1 phan tu vao dau danh sach" << endl;
		cout << "4/them 1 phan tu vao cuoi danh sach" << endl;
		cout << "5/xoa 1 phan tu dau danh sach" << endl;
		cout << "6/xoa 1 phan tu cuoi danh sach" << endl;
		cout << "7/xoa phan tu tai vi tri thu i trong danh sach" << endl;
		cout << "8/tim 1 phan tu va xoa phan tu do trong danh sach" << endl;
		cout << "9/tim 1 phan tu va xoa tat ca phan tu trong danh sach" << endl;
		cout << "10/sap xep thu tu tang dan" << endl;
		cout << "11/thoat" << endl;
		cin >> choose;
		switch (choose) {
		case 1: {
			printList(first);
			break;
		}
		case 2: {
			cout << "nhap so ban muon tim trong danh sach" << endl;
			cin >> tmp;
			system("cls");
			find(first, tmp);
			break;
		}
		case 3: {
			cout << "moi ban nhap so muon them vao dau mang" << endl;
			cin >> tmp;
			first = addStart(first, tmp);
			system("cls");
			printList(first);
			break;
		}
		case 4: {
			cout << "moi ban nhap so muon them vao cuoi mang" << endl;
			cin >> tmp;
			first = addEnd(first, tmp);
			system("cls");
			printList(first);
			break;
		}
		case 5: {
			first = deleteStart(first);
			system("cls");
			printList(first);
			break;
		}
		case 6: {
			first = deleteEnd(first);
			system("cls");
			printList(first);
			break;
		}
		case 7: {
			cout << "moi ban nhap vi tri ban muon xoa:" << endl;
			cin >> tmp;
			first = deleteIndex(first,tmp);
			system("cls");
			printList(first);
			break;

		}
		case 8: {
			cout << "moi ban nhap so ban muon xoa:" << endl;
			cin >> tmp;
			first = deleteNumber(first, tmp);
			system("cls");
			printList(first);
			break;
		}
		case 9: {
			cout << "moi ban nhap so ban muon xoa:" << endl;
			cin >> tmp;
			first = deleteAllNumber(first, tmp);
			system("cls");
			printList(first);
			break;
		}
		case 10: {
			first=interChangeSort(first);
			system("cls");
			printList(first);
			break;
		}
		case 11: {
			cout << "thanks for using" << endl;
			break;
		}
		default:
			cout << "error choose, pls choose again" << endl;
			break;
		}
	} while (choose != 11);
}