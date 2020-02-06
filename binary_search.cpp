//Binary search on random access containers

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template<typename T>
using _type = typename T::value_type;

template<typename T>
struct less_cmp {
	less_cmp() {};
	inline bool operator()(const T& first, const T& second) {
		return first < second;
	}
};

template<typename _iterator, typename cmp = less_cmp<_type<_iterator>>>
bool binary_search(_iterator first, _iterator last, const _type<_iterator>& val) {	
	size_t sz = last - first;
	if (sz == 1)
		sz = 0;

	auto to_check = first + (sz/2);

	cmp comp;

	if (!comp(val, *to_check) && !comp(*to_check, val))
		return true;

	if (!sz)
		return false;

	if (comp(val, *to_check))
		return binary_search(first, to_check, val);
	else
		return binary_search(to_check, last, val);
}

int main() {
	int n_min = -5000;
	int n_max = 12000;

	std::cout << "Range is [" << n_min << ":" << n_max << ")\n";

	std::vector<int> vec;
	for (int i = n_min; i < n_max ; ++i)
		vec.push_back(i);

	std::cout << "There will be one hundred attemps to verify if one hundred different numbers are in the container.\n" << std::endl;
	srand(time(0));

	for (int i = 0; i < 100; ++i) {
		int j = rand();
		std::cout << std::boolalpha << j << " is in the container: " << binary_search(vec.begin(), vec.end(), j) << "\n";
	}
}
