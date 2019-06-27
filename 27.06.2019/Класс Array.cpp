#include <iostream>
#include <type_traits>
#include <array>

template <typename T, typename AT = std::allocator<T>> class VarArray {
	using BYTE = char;
private: 
	size_t size;
	T* arr;
	AT alloc;

public:
	VarArray() = default;
	
	VarArray(size_t num): alloc(), size(num), arr(alloc.allocate(num)) {
	  for(size_t i = 0; i< num; i++) {
		  new (reinterpret_cast<BYTE*>(arr + i)) T();
	  }
	}
	
	VarArray(VarArray&& old) : size(std::move(old.size)), alloc(std::move(old.alloc)), arr(std::move(old.arr)) {}
	
	VarArray(const VarArray& old) : size(old.size), alloc(old.alloc) {
		arr = alloc.allocate(old.size);
		for (size_t i = 0; i < size; i++) {
			new (reinterpret_cast<BYTE*>(arr + i)) T(old.arr[i]);
		}
	}

	VarArray(std::initializer_list<T> values): alloc(), size(values.size()), arr(alloc.allocate(size)) {
		size_t i = 0;
		for (auto&& elem : values) {
			new (reinterpret_cast<BYTE*>(arr + i)) T(std::move(elem));
			i++;
		}
	}

	~VarArray() {
		for (size_t i = 0; i < size; i++) {
			(arr+i)->~T();
		}
		alloc.deallocate(arr, size);
	}
	
	
	T& operator[](size_t idx) {
		return arr[idx];
	}

	size_t GetSize() {
		return size;
	}

	size_t SetSize(size_t newsize, size_t grow = 1) {
		if (size < newsize) {
			auto newarr = alloc.allocate(newsize);
			for (size_t i = 0; i < size; i++) {
				new (reinterpret_cast<BYTE*>(newarr + i)) T(std::move(arr[i]));
			}
			for (size_t i = size; i < newsize; i++) {
				new (reinterpret_cast<BYTE*>(newarr + i)) T();
			}
			alloc.deallocate(arr, size);
			arr = newarr;
			size = newsize;
		} else if (size > newsize) {
			auto newarr = alloc.allocate(newsize);
			for (size_t i = 0; i < newsize; i++) {
				new (reinterpret_cast<BYTE*>(newarr + i)) T(std::move(arr[i]));
			}
			for (size_t i = newsize; i < size; i++) {
				(newarr + i)->~T();
			}
			alloc.deallocate(arr, size);
			arr = newarr;
			size = newsize;
		}

		return size;
	}

};

struct QQQ {
   int qqq;
   QQQ() = default;
};


int main(){
	//VarArray<int> va1 = { 10, 12, 52, 47 };

	//VarArray<int>&& va2 = std::move(va1);

	//std::cout << va1[1] << std::endl;

	//std::cout << va2[2] << std::endl;

	VarArray<QQQ> va1 = { QQQ{ 1 }, QQQ{ 2 }, QQQ{ 3 } };

	VarArray<QQQ>&& va2 = std::move(va1);

   return 0; 
}
