#ifndef _RANDOM_HH_
#define _RANDOM_HH_

class Random {
	public:
		static void srand();
		static void srand( unsigned int seed);
		// return a number in the range [a, b] ( including a and b)
		static size_t random( const size_t a, const size_t b);

	private:
		Random();

};

#endif
