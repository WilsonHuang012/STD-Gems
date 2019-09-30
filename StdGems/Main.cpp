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

void Copy(std::vector<std::string> a, std::vector<std::string> b)
{
	std::cout << "Copy if:" << std::endl;
	std::copy_if(std::make_move_iterator(a.begin()),
		std::make_move_iterator(a.end()), b.begin(),
		[](const std::string& str) { return str.size() > 3; });
	write_to_cout(a, " | ");
	std::cout << std::endl;
	write_to_cout(b);
}

template<class Container, class Pred>
void Remove_If(Container a, Pred pred)
{
	std::cout << "Remove_If:" << std::endl;
	const auto new_end = std::remove_if(a.begin(), a.end(), pred);
	a.erase(new_end, a.end());
	write_to_cout(a, " | ");
}

void Unique()
{
	std::cout << "Unique " <<
		"(Removes all but the first element from every consecutive group " << 
		"of equivalent elements in the range ):" << std::endl;
	std::vector<std::string> b =
	{ "0", "2", "2", "2", "4", "9", "6", "7", "9", "9", "10" };
	const auto new_end = std::unique(b.begin(), b.end());
	b.erase(new_end, b.end());
	write_to_cout(b);
}

int main()
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

	Copy(a, b);
	std::cout << std::endl << std::endl;
	
	auto pred = [](const std::string& s)
	{
		return std::count(s.begin(), s.end(), 'e') == 0;
	};
	
	Remove_If(a, pred);
	std::cout << std::endl << std::endl;
	Unique();

	while (!_kbhit());
}