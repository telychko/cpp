#ifndef TEMPLATE_FOR_EXPANSION_H
#define TEMPLATE_FOR_EXPANSION_H

#include <print>

template <class... Ts>
void print_all(Ts... ts) {
  template for (auto t : {ts...}) {
    std::println("{}", t);
  }
}

#endif // TEMPLATE_FOR_EXPANSION_H
