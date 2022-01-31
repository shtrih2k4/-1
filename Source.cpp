#include<iostream>
#include<string>
#include<vector>
#include<ofstream>
using namespace std;
struct Node {
	Node* next;
	int val;
	Node(int _val) :val(_val), next(nullptr) {}
};
struct List {
	Node* first;
	Node* last;
	List() :first(nullptr), last(nullptr) {}
	List(vector<int> a) {
		first = nullptr;
		last = nullptr;
		for (unsigned int i = 0; i < a.size(); i++) {
			Node* p = new Node(a[i]);
			if (i == 0) {
				first = p;
				last = p;
			}
			else {
				last->next = p;
				last = p;
			}
		}
	}
	bool emptylist() {
		return first == nullptr;
	}
	Node* find_node_by_index(int index) {
		if (emptylist()) return nullptr;
		Node* p = first;
		for (int i = 1; i < index; i++) {
			p = p->next;
			if (!p) return nullptr;
		}
		return p;
	}
	void insert(int _val, int index) {
		Node* new_element = new Node(_val);
		if (emptylist()) {
			cout << "Ñïèñîê ïóñòîé, ïîýòîìó åëåìåíò " << _val << " áóäåò ïåðâûì" << endl;
			first = new_element;
			last = new_element;
			return;
		}
		else if (find_node_by_index(index) != nullptr) {
			if (index == 0) {
				Node* temp = first;
				first = new_element;
				first->next = temp;
			}
			else {
				Node* temp = find_node_by_index(index)->next;
				find_node_by_index(index)->next = new_element;
				new_element->next = temp;
			}
		}
		else {
			//cout << "Èíäåêñ>=ðàçìåðà ñïèñêà, ïîýòîìó åëåìåíò " << _val << " áóäåò äîáàâëåí â êîíåö" << endl;
			last->next = new_element;
			last = new_element;
		}
	}
	void print() {
		if (emptylist()) return;
		Node* p = first;
		while (p) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
	void remove(const int index) {
		if (emptylist()) { return; }
		else if (find_node_by_index(index) != nullptr) {
			if (index == 0) {
				Node* p = first;
				first = p->next;

			}
			else if (find_node_by_index(index) != last) {
				Node* p = find_node_by_index(index)->next;
				find_node_by_index(index)->next = p->next;
			}
			else {
				cout << "Óêàçàííûé èíäåêñ(" << index << ")>= ðàçìåðó ñïèñêà" << endl;
			}
		}
	}
	void find_by_value(int _val) {
		cout << "Äàííûé åëåìåíò("<<_val<<") âñòðå÷àåòñÿ íà ïîçèöèÿõ : ";
		Node* p = first;
		unsigned int k = 0;
		while (p) {
			if (p->val == _val) {
				cout << k << " ";
			}
			p = p->next;
			k++;
		}
		cout << endl;
	}
	void search_duplicates() {
		vector<int> dupl;
		Node* p = first;
		while (p) {
			Node* current = p->next;
			while (current) {
				if (current->val == p->val and count(dupl.begin(), dupl.end(), current->val) == 0) {
					dupl.push_back(p->val);
				}
				current = current->next;
			}
			p = p->next;
		}
		cout << "Ïîâòîðÿþùèåñÿ åëåìåíòû:";
		for (unsigned int i = 0; i < dupl.size(); ++i) {
			cout << dupl.at(i) << " ";
		}
		cout << endl;
	}
	void search_multiple_duplicates() {
		vector<int> dupl;
		Node* p = first;
		unsigned int k;
		while (p) {
			k = 1;
			Node* current = p->next;
			while (current) {
				if (current->val == p->val and count(dupl.begin(), dupl.end(), current->val) == 0) {
					k++;
				}

				current = current->next;
			}
			if (k == 3 or k == 4) {
				dupl.push_back(p->val);
			}
			p = p->next;
		}
		cout << "Åëåìåíòû, êîòîðûå ïîâòîðÿþòñÿ 3-4 ðàçà:";
		for (auto& k : dupl) {
			cout << k << " ";
		}
	}
};
int main() {
	setlocale(LC_ALL, "");
	List a(vector<int>({ 99,19,15,17 }));
	cout << "Åñëè èíäåêñ>=ðàçìåðà ñïèñêà, îí áóäåò äîáàâëåí â êîíåö"<<endl;
	a.insert(3, 5);
	a.insert(3, 2);
	a.insert(1, 0);
	a.insert(2, 1);
	a.insert(4, 5);
	a.insert(0, 0);
	a.insert(3, 0);
	a.remove(2);
	a.print();
	a.find_by_value(3);
	a.search_duplicates();
	a.search_multiple_duplicates();
	return 0;
}
