//While studying with help of the book Programming Principles and pratices using C++, on the chapter 17 there are some exercises with linked lists.
//This is what I've done so far in regard of linked lists related to this book.



template <typename T> 
class Node {
public:
	Node() {};
	Node(const T x) :value(x) {};
	~Node() { delete next; }
	
	T value;
	Node* next = nullptr;
	Node* previous = nullptr;
};

template <typename T>
class Linked_list {
public:
	Linked_list() {};
	~Linked_list() { delete head; }
	Linked_list(std::initializer_list<T> init) {
		if (init.size()) {
			Node<T>* current = nullptr;

			for (int i = 0; i < init.size(); ++i, ++list_size) {
				if (i == 0) {
					current = new Node<T>;
					head = current;
				}

				current->value = *(init.begin() + i);
				current->next = i == init.size() - 1 ? nullptr : new Node<T>;

				if (current->next) {
					current->next->previous = current;
					current = current->next;
				}
			}
		}
	}

	T at(unsigned n) const {
		return r_position(n)->value;
	}
	void insert(T to_insert, int loc) {
		if (!head) {
			if (loc != 0)
				throw std::out_of_range("Invalid insert position for empty list");
			head = new Node<T>(to_insert);
			++list_size;
			return;
		}

		if (loc == this->size()) {
			Node<T>* temp = const_cast<Node<T>*>(r_position(loc - 1));
			temp->next = new Node<T>(to_insert);
			temp->next->previous = temp;
			++list_size;
			return;
		}
		
		Node<T>* pos = const_cast<Node<T>*>(r_position(loc));
		Node<T>* new_node = new Node<T>(to_insert);

		new_node->next = pos;
		
		if (pos->previous) {
			new_node->previous = pos->previous;
			new_node->previous->next = new_node;
		}

		pos->previous = new_node;

		head = head == pos ? new_node : head;
		
		++list_size;
	}
	void remove(int loc) {
		Node<T>* temp = const_cast<Node<T>*>(r_position(loc));
		if (temp == head) {
			head = temp->next;
			temp->next = nullptr;
			delete temp;
			--list_size;
			return;
		}
		
		if (temp->previous)
			temp->previous->next = temp->next;

		if (temp->next)
			temp->next->previous = temp->previous;

		temp->next = nullptr;
		
		delete temp;
		--list_size;
	}
	int size() const { return list_size; }	
	void insert_ordered(T to_insert) {
		Node<T>* temp = head;

		if (!head) {
			insert(to_insert, 0);
		}


		Node<T>* to_add = nullptr;
		while (temp) {
			
			if (temp->value > to_insert && (temp->previous == nullptr || temp->previous->value <= to_insert)) {
				++list_size;
				to_add = new Node<T>(to_insert);
				if (temp->previous) {
					to_add->previous = temp->previous;
					to_add->previous->next = to_add;
					to_add->next = temp;
					to_add->next->previous = to_add;
					break;
				}
				else {
					to_add->next = temp;
					to_add->next->previous = to_add;
					break;
				}
			}
			else if (!temp->next && temp->value <= to_insert) {
				++list_size;
				to_add = new Node<T>(to_insert);
				temp->next = to_add;
				temp->next->previous = temp;
				break;
			}
			temp = temp->next;
		}


		if (temp == head && temp->previous)
			head = temp->previous;
	}
	void sort() {
		if (!head)
			throw std::exception("Attemp of sorting empty list");
		
		
		bool sort_happened = 1;


		while (sort_happened) {
			Node<T>* temp = head;
			sort_happened = false;

			while (temp) {
				if (temp->next) {
					if (temp->next->value < temp->value) {
						T x = temp->value;
						temp->value = temp->next->value;
						temp->next->value = x;
						sort_happened = true;
					}
				}
				temp = temp->next;
			}
		}
	}


protected:
	const Node<T>* r_position(unsigned int n) const {
		if (n >= list_size)
			throw std::out_of_range("");

		const Node<T>* temp = head;
		while (n--) {
				temp = temp->next;
		}
		return temp;
	}	
	Node<T>* head = nullptr;
	int list_size = 0;
};
