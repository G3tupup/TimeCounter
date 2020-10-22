#include <unistd.h>

#include "time_counter.hpp"

void func1() { usleep(80000); }
void func2() { usleep(40000); }

int main() {
  // single
  time_counter::tick();
  func1();
  time_counter::tack();

  // single
  time_counter::tick("func1");
  func1();
  time_counter::tack("func1");

  // multiple
  for (int i = 0; i < 10; i++) {
    time_counter::tick("func2");
    func2();
    time_counter::tock("func2");
  }
  time_counter::output("func2");

  // multiple
  time_counter::clear("func2");
  for (int i = 0; i < 10; i++) {
    time_counter::tick("total");
    func1();
    time_counter::tick("func2");
    func2();
    time_counter::tock("func2");
    time_counter::tock("total");
  }
  time_counter::output("func2");
  time_counter::output("total");
  return 0;
}
