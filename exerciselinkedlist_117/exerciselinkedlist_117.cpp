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
	bool search(int rollno, Node** rosady, Node** nauval);
	bool listEmpty();
	bool delNode(int name);
	void traverse();
};

bool CircularLinkedList::search(int rollno, Node** rosady, Node** nauval) {
	*rosady = LAST->next;
	*nauval = LAST->next;

	while (*nauval != LAST) {
		if (rollno == (*nauval)->rollNumber) {
			return true;
		}
		*rosady = *nauval;
		*nauval = (*nauval)->next;
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

bool CircularLinkedList::delNode(int name) {
	Node* rosady, * nauval;
	rosady = nauval = NULL;
	if (search(name, &rosady, &nauval) == false)
		return false; 
	if (nauval->next != NULL)
		nauval->next->next = rosady ; 
	if (rosady != NULL)
		rosady->next = nauval->next; 
	delete nauval; 
	return true;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* nauvalNode = LAST->next;
		while (nauvalNode != LAST) {
			cout << nauvalNode->rollNumber << " " << nauvalNode->name << endl;
			nauvalNode = nauvalNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1.Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";

			char ch;
			cin >> ch;

			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
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