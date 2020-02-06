#include <iostream>

bool is_pangram(const std::string& sentence) {

	const int to_compare = 0x3FFFFFF;
	int to_store = 0;
	for (auto x : sentence) {
		to_store |= 1 << tolower(x) - 'a';
	}
	return !(to_compare ^ to_store);
}


int main() {
	std::cout << is_pangram("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	
	return 0;
}
