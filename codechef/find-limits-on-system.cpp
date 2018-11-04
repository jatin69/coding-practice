#include <iostream>
#include <limits>
int main(int, char **) {
  std::cout
    << static_cast< int >(std::numeric_limits< char >::max()) << "\n"
    << static_cast< int >(std::numeric_limits< unsigned char >::max()) << "\n"
    << std::numeric_limits< short >::max() << "\n"
    << std::numeric_limits< unsigned short >::max() << "\n"
    << std::numeric_limits< int >::max() << "\n"
    << std::numeric_limits< unsigned int >::max() << "\n"
    << std::numeric_limits< long >::max() << "\n"
    << std::numeric_limits< unsigned long >::max() << "\n"
    << std::numeric_limits< long long >::max() << "\n"
    << std::numeric_limits< unsigned long long >::max() << "\n";
}
