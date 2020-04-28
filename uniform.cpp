#include <random>
#include <functional>
#include <map>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
	const unsigned int kStart = 1;
	const unsigned int kEnd = 99;
	const unsigned int kIteration = 1'000'000;

	// 균등 메르센 트위스터
	random_device seeder;
	const auto seed = seeder.entropy() ? seeder() : time(nullptr);
	mt19937 eng(static_cast<mt19937::result_type>(seed));
	uniform_int_distribution<int> dist(kStart, kEnd);
	auto gen = bind(dist, eng);

	map<int, int> m;
	for (unsigned int i = 0; i < kIteration; ++i) {
		int rnd = gen();

		++(m[rnd]);
	}

	// csv파일에 저장

	ofstream of("result.csv");
	for (unsigned int i = kStart; i <= kEnd; ++i) {
		of << i << ", " << m[i] << endl;
	}

	return 0;





}