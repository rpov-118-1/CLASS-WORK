#include <iostream>
#include "ctime"

class Array {
private:
	int* x;
	int size;
	bool xz = false;
public:
	
	Array() = default;
	
	Array(int xx) {
		xz = true;
			x = new int[xx];
			size = xx;
	}

	Array(std::initializer_list<int> ints) {				//!!!!!!!!!!!!!!!инициализируем список интами, указщанными в меййне
		xz = true;
		x = new int[ints.size()];
		size = ints.size();
		size_t i = 0;
		for (const int elem : ints) {
			x[i++] = elem;
		}
	}
		
	~Array() {
		if (xz) {
		delete x;
		}
		else std::cout << "Not initialization object \n";
	}
	
	Array(const Array& old) {
		xz = true;
		x = new int[old.size];
		size = old.size;
		for (int i = 0; i < size; i++) {
			x[i] = old.x[i];
		}		
	}

	Array(Array&& old) {
		xz = true;
		x = old.x;
		size = old.size;		
	}

	void create_array(int zz) {
		if (xz) {
			x = new int[zz];
			size = zz;
		}
		else std::cout << "Not initialization object \n";
	}

	void fill_array() {
		if (xz) {
			for (int i = 0; i < size; i++) {
				x[i] = rand() % 41 - 20;
			}
		}
		else std::cout << "Not initialization object \n";
	}

	void print() {
		if (xz) {
			for (int i = 0; i < size; i++) {
				std::cout << x[i] << " ";
			}
			std::cout << std::endl;
		}
		else std::cout << "Not initialization object \n";
	}
	   
	void new_array(int new_size) {
		if (xz) {
			size = new_size;
			int* y = new int[size];
			for (int i = 0; i < size; i++) {
				y[i] = x[i];
			}
			delete x;
			x = new int[new_size];
			for (int i = 0; i < size; i++) {
				x[i] = y[i];
			}
			delete y;
		}
		else std::cout << "Not initialization object \n";
	}

	void sort() {
		if (xz) {
			for (int i = 0; i < size; i++) {
				for (int j = i + 1; j < size; j++) {
					if (x[i] > x[j]) {
						x[i] = x[i] + x[j];
						x[j] = -(x[j] - x[i]);
						x[i] = x[i] - x[j];
					}
				}
			}
		}
		else std::cout << "Not initialization object \n";
	}

	void min() {
		if (xz) {
			int min = x[0];
			for (int i = 0; i < size; i++) {
				if (x[i] < min) {
					min = x[i];
				}
			}
			std::cout << "Min " << min << std::endl;
		}
	}

	void max() {
		if (xz) {
			int max = x[0];
			for (int i = 0; i < size; i++) {
				if (x[i] > max) {
					max = x[i];
				}
			}
			std::cout << "Max " << max << std::endl;
		}
		else std::cout << "Not initialization object \n";
	}


};



int main(){
	srand(time(NULL));
	//Array first = {};
	//first.fill_array();
	//first.print();
	//first.sort();
	//first.print();
	//first.max();
	//first.min();
	//first.new_array(15);
	//first.print();
	//Array second = std::move(first);
	//second.print();
	/*Array asd = { };
	asd.print();
	asd.min();*/

	Array third = { 12, 42, 53, 74, 85, 46, 17 };
	third.print();

    return 0; 
}
