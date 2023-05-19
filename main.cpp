#include <iostream>
#include <type_traits>


template<int... Numbers>
struct is_sorted
: std::true_type
{
};

template<int Start, int Head, int... Other>
struct is_sorted<Start, Head, Other...>
:std::integral_constant<bool, 
						(Start <= Head) &&
						is_sorted<Head, Other...>::value>

{
};

int main(int argc, char* argv[])
{
	std::cout << std::boolalpha 
			  << is_sorted<1, 4, 5, 9, 12>::value << std::endl;

	std::cout << std::boolalpha
			  << is_sorted<1, 1, 3, 4, 5>::value << std::endl;

	std::cout << std::boolalpha 
			  << is_sorted<1, 2, 4, 3, 5>::value << std::endl;

	std::cout << std::boolalpha
			  << is_sorted<>::value << std::endl;
}