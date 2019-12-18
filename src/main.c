#include "lib_C/MetroidvaniaRunner_C.h"

int main() {
  auto runner = createRunner(0, "Heh", 100);
  runNovel(runner);

  return EXIT_SUCCESS;
}
