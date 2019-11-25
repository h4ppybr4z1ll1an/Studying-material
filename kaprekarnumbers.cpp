//Routine that finds the kaprekarNumbers withing given range
//I have made this while completing a chalenge in HackerRank


std::vector<int> kaprekarNumbers(int p, int q) {
	std::vector<int> to_return;
	
	for (; p <= q; p++) {	
		if (p == 1) {
			to_return.push_back(p);
			continue;
		}
		long long n = static_cast<long long>(p);
	
		const long long int squared = n*n;
	
		int original_digits = 0;
		for (int div = 1; n / div; ++original_digits, div *= 10);
		
		int squared_digits = 0;
		long long int sqr = squared;
		for (int div = 1; sqr; ++squared_digits, div *= 10, sqr/=div);

		if (squared_digits > original_digits * 2 || squared_digits < original_digits - 1)
			continue;

		long long int l;
		long long int r;

		for (int i = 0, div = 1; i <= original_digits; div *= 10, i++) {
			if (i == original_digits) {
				l = squared / div * div;
				r = squared - l;
				l /= div;
			}
		}
		if (r + l == p)
			to_return.push_back(p);
	}
	return to_return;
}
