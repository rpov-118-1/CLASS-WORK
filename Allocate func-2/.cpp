#include "iostream"
#include <functional>

typedef int buf_t[1024];
typedef buf_t* bufarr_t[1024];
typedef std::function<void(const bufarr_t&)> worker_t;

void allocate_and_work(bufarr_t* bufarr, int m, int n, int q, int i, worker_t worker) {
	buf_t buf = { 0 };
	(*bufarr)[i] = &buf;
	if (m <= 0 && n <= 0 && q <= 0) {
		(*bufarr)[i] = NULL;
		worker(*bufarr);
		return;
	}
	else if (m <= 0 && n <= 0) {
		return allocate_and_work(bufarr, m, n, q - 1024, i + 1, worker);
	}
	else if (m <= 0) {
		return allocate_and_work(bufarr, 0, n - 1024, q, i + 1, worker);
	}
	else {
		return allocate_and_work(bufarr, m - 1024, n, q, i + 1, worker);
	}
}

void allocate_and_work(int m, int n, int q, worker_t worker) {
	bufarr_t bufarr = { 0 };
	allocate_and_work(&bufarr, m, n, q, 0, worker);
}

int main() {
	int m = 0, n = 0, q = 0;
	std::cin >> m;
	std::cin >> n;
	q = m + n;

	allocate_and_work(m, n, q, [=](const bufarr_t& q) {
		std::cout << " one buf" << (*q[1])[1022] << std::endl;
		for (int i = 0; i < m; i++)
			(*q[0])[i] = 1;
		for (int i = 0; i < n; i++)
			(*q[1])[i] = 2;
		for (int i = 0; i < m; i++)
			(*q[2])[i] = (*q[0])[i];
		for (int i = 0; i < n; i++)
			(*q[2])[m+i] = (*q[1])[i];
		for (int i = 0; i < n+m; i++)
			std::cout << "\n" << (*q[2])[i] << "\n";
	});

	system("pause");
	return 0;
}
