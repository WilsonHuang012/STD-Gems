#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <conio.h>
#include <cctype>
#include <algorithm>

template<class Container>
void write_to_cout(const Container& container, const char* delimiter = " ")
{
	std::copy(container.begin(), container.end(),
		std::ostream_iterator<Container::value_type>(std::cout, delimiter));
}

void Copy()
{
	std::string a = "Happy Fun times With Capital letters";
	std::string b = "otHEewiSe KNOwn as upper CASE biotches";
	write_to_cout(a);
	std::cout << std::endl;
	write_to_cout(b);
	std::cout << std::endl << std::endl;

	std::string uppers;
	std::copy_if(a.begin(), a.end(), std::back_inserter(uppers), std::isupper);
	std::copy_if(b.begin(), b.end(), std::back_inserter(uppers), std::isupper);
	write_to_cout(uppers);
}

int main()
{
	Copy();
	while (!_kbhit());
}