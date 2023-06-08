#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;

public:
	CircularLinkedList() {
		LAST = NULL;
	}

	void addNode();
	bool search(int rollno, Node** aulia, Node** nadila);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() { 
	int nim; //membuat data integerdengan nama variabel nim
	string nm; //membuat tipe data dengan nama variabel nm
	cout << "\nEnter the roll number of the student : ";
	cin >> nim; //dimasukkan ke nim
	cout << "\nEnter the name of the student : ";
	cin.ignore();
	getline(cin, nm);
	Node* newNode = new Node(); //membuat pointer Node ke newNode
	newNode->rollNumber = nim;

	if (LAST == NULL || nim <= LAST->rollNumber) { //apabila last nya sama dengan null atau kurang dari last->rollNumber
		if (LAST != NULL && nim == LAST->rollNumber) {
			cout << "Buat linked list terlebih dahulu" << endl;
			return;
		}

		LAST = newNode;
		newNode->next = LAST;
		return;
	}

	Node* nadila = LAST;
	Node* aulia = NULL;


}

bool CircularLinkedList::search(int rollno, Node** aulia, Node** nadila) {
	*aulia = LAST->next;
	*nadila = LAST->next;

	while (*aulia != LAST) {
		if (rollno == (*nadila)->rollNumber) {
			return true;
		}
		*aulia = *nadila;
		*nadila = (*nadila)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { 
	if (listEmpty()) {
		cout << "List is empty" << endl; // maka keluar tampilan itu
		return false; //Diulang jika kosong
	}

	if (LAST->next == LAST) {
		delete LAST;
		LAST = NULL;
	}
	else {
		Node* nadila = LAST->next;
		LAST->next = nadila->next;
	}
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}