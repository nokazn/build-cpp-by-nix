// https://blog.galowicz.de/2019/04/17/tutorial_nix_cpp_setup/
#include <boost/lexical_cast.hpp>
#include <Poco/Environment.h>
#include <iostream>

#if defined (__clang__)
#define CC "clang++"
#elif defined (__GNUC__)
#define CC "g++"
#else
#define CC "<unknown compiler>"
#endif

int add(int a, int b) {
  return a + b;
}

int main(void) {
  std::cout << "Hello World!\n"
    << "Complier: " << CC << " " << __VERSION__ << '\n'
    << "Boost: " << (BOOST_VERSION / 100000) << '.'
      << (BOOST_VERSION / 100 % 1000) << '.'
      << (BOOST_VERSION % 100) << '\n'
    << "Poco: " << (Poco::Environment::libraryVersion() >> 24) << '.'
      << (Poco::Environment::libraryVersion() >> 16 & 0xff) << '.'
      << (Poco::Environment::libraryVersion() >> 8 & 0xff) << '\n';
  std::cout << BOOST_VERSION << '\n';
  printf("%d + %d = %d\n", 1, 2, add(1, 2));
  return 0;
}
