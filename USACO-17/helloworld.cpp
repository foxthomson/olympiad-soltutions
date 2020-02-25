// #include <iostream>
// #include <cstdint>
//
// int main()
// {
// 	long long a;
// 	std::cout << "a size: " << sizeof(a) << std::endl;
// 	std::int16_t b(10000);
// 	std::cout << "b size: " << sizeof(b) << std::endl;
// 	bool x;
// 	std::cout << "Enter a number: ";
// 	std::cin >> x;
// 	std::cout << "You entered " << x << std::endl;
// 	return 0;
// }
// #include <iostream>
// // #include <cstdint>
//
// int main()
// {
//     int i(1); // direct initialization
//     std::cout << "\a\a\a\a\a\a\a\v" << i << std::endl << sizeof(i);
//     return 0;
// }
// int main()
// {
//     unsigned char option_viewed = 0x01;
//     unsigned char option_edited = 0x02;
//     unsigned char option_favorited = 0x04;
//     unsigned char option_shared = 0x08;
//     unsigned char option_deleted = 0x80;
//
//     unsigned char myArticleFlags = 0;
//
//     myArticleFlags |= option_viewed
//
//     bool deleted = myArticleFlags option_deleted
//
//     myArticleFlags &= ~option_favorited
//
//     return 0;
// }

#include <iostream>
#include <string>

int main()
{
    std::string a;
    std::cout << "> ";
    std::getline(std::cin, a);

    std::string b;
    std::cout << "> ";
    std::cin >> b;

    std::cout << a << b;
}
