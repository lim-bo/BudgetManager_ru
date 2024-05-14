#ifndef NodeClass
#define NodeClass
template <class T>
struct Node {
	Node* next;
	Node* prev;
	T value;
};
#endif // !NodeClass

#ifndef OutLambda
#define OutLambda
// Структура для кастомной лямбды для вывода данных в поток
template<class T>
struct Lambda {
    std::ofstream& localOut;
    void operator()(T value) {localOut << value;}
};
#endif

// #ifndef LambdaInterface
// #define LambdaInterface
// class Lambda {
// public:
//     void operator()();
// };

// class custom : Lambda {
//     void operator ()(note_t val);
// };

// #endif

#ifndef ListClass
#define ListClass
#include <iostream>
#include <algorithm>

template<class T>
class List {
private:
	int len;
	Node<T>* head;
	Node<T>* tail;
public:
	List() {
		this->len = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	~List() {
		Node<T>* curr = this->head, * nextNode = nullptr;
		while (curr) {
			nextNode = curr->next;
			delete curr;
			curr = nextNode;
		}
	}

	int Len() {
		return this->len;
	}

	void append(T newValue) {
		if (!this->len) {
			this->head = new Node<T>;
			this->tail = this->head;
			this->head->prev = nullptr;
			this->head->next = nullptr;
			this->head->value = newValue;
			this->len++;
			return;
		}
		Node<T>* newNode = new Node<T>;
		newNode->value = newValue;
		newNode->next = nullptr;
		newNode->prev = this->tail;
		this->tail->next = newNode;
		this->tail = newNode;
		this->len++;
	}

	T popend() {
		if (!this->len) return {};
		T outValue = this->tail->value;
		if (this->len == 1) {
			delete this->tail;
			this->head = nullptr;
			this->tail = nullptr;
			this->len--;
			return outValue;
		}
		Node<T>* curr = this->tail->prev;
		curr->next = nullptr;
		delete this->tail;
		this->tail = curr;
		this->len--;
		return outValue;
	}

	T getValue(int index, bool& ok) {
		if (index >= this->len || index < 0) {
			ok = false;
			return {};
		}
		if (index == 0) {
			ok = true;
			return this->head->value;
		}
		if (index == this->len - 1) {
			ok = true;
			return this->tail->value;
		}
		int step = 0;
		Node<T>* curr = this->head;
		while ((step++) != index) {
			curr = curr->next;
		}
		ok = true;
		return curr->value;
	}

	void getList(std::ostream& out) {
		Node<T>* curr = this->head;
		for (int i = 0; i < this->len; i++) {
            out << curr->value;
			curr = curr->next;
		}
	}

	bool updateAt(int index, T newValue) {
		if (index >= this->len || index < 0) {
			return false;
		}
		if (index == 0) {
			this->head->value = newValue;
			return true;
		}
		if (index == this->len - 1) {
			this->tail->value = newValue;
			return true;
		}
		int step = 0;
		Node<T>* curr = this->head;
		while ((step++) != index) {
			curr = curr->next;
		}
		curr->value = newValue;
		return true;
	}

	bool insertAt(int index, T value) {
		if (index >= this->len || index < 0) return false;
		if (index == 0 && this->len) {
			Node<T>* newNode = new Node<T>;
			newNode->prev = nullptr;
			newNode->value = value;
			newNode->next = this->head;
			this->head->prev = newNode;
			this->head = newNode;
			this->len++;
			return true;
		}
		if (index == this->len && !this->len) {
			this->append(value);
			return true;
		}
		Node<T>* prev = this->head, *newNode = new Node<T>;
		int step = 0;
		while ((step++) != index - 1) {
			prev = prev->next;
		}
		newNode->value = value;
		newNode->next = prev->next;
		prev->next = newNode;
		newNode->prev = prev;
		this->len++;
		return true;
	}

	bool deleteAt(int index) {
		if (index >= this->len || !this->len|| index < 0) return false;
		if (this->len == 1) {
			delete this->head;
			this->head = nullptr;
			this->tail = nullptr;
			this->len--;
			return true;
		}
		
		if (!index) {
			this->head->next->prev = nullptr;
			Node<T>* temp = this->head;
			this->head = this->head->next;
			delete temp;
			this->len--;
			return true;
		}

		if (index == this->len - 1) {
			Node<T>* temp = this->tail;
			this->tail->prev->next = nullptr;
			this->tail = this->tail->prev;
			delete temp;
			this->len--;
			return true;
		}

		int step = 0;
		Node<T>* prev = this->head, *deletable = nullptr;
		while ((step++) != index - 1) {
			prev = prev->next;
		}
		deletable = prev->next;
		prev->next = deletable->next;
		deletable->next->prev = prev;
		delete deletable;
		this->len--;
		return true;
	}

    void mapCustomLambda(Lambda<T> handler) {
        Node<T>* curr = this->head;
        while (curr) {
            handler(curr->value);
            curr = curr->next;
        }
    }

    // Возвращает -1, если не найдено, или индекс элемента, если он существует в списке
    int find(bool (*f)(T, T), T target) {
        Node<T>* curr = this->head;
        int ind = 0;
        while (curr) {
            if (f(target, curr->value)) return ind;
            curr = curr->next;
            ind++;
        }
        return -1;
    }

    void sortAsc(bool (*f)(T, T)) {
        if (!this->len) return;
        T *arr = new T[this->len];

        bool ok;
        for (int i = 0; i < this->len; i++) {
            arr[i] = this->getValue(i, ok);
        }

        for (int j = 1; j < this->len; j++)
            for (int i = 0; i < this->len - j; i++) {
                if (f(arr[i], arr[i + 1])) {
                    T temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }

        for (int i = 0; i < this->len; i++) {
            this->updateAt(i, arr[i]);
        }
        delete arr;
    }
};

#endif // !ListClass
