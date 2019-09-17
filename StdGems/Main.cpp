#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <conio.h>

template<class Container>
void write_to_cout(const Container& container, const char* delimiter = " ")
{
	std::copy(container.begin(), container.end(),
		std::ostream_iterator<Container::value_type>(std::cout, delimiter));
}

void Copy()
{
	std::vector<std::string> a =
	{ "zero", "one", "two", "three", "four",
	  "five", "six", "seven", "eight", "nine", "ten"
	};
	std::vector<std::string> b =
	{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

	write_to_cout(a);
	std::cout << std::endl;
	write_to_cout(b);
	std::cout << std::endl << std::endl;

	std::copy(b.begin(), b.begin() + 4, b.begin() + 6);
	write_to_cout(b);
}

int main()
{
	Copy();
	while (!_kbhit());
}