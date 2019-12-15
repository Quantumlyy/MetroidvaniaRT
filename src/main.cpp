#include "./lib/MetroidvaniaRunner.h"

#include "../dependencies//NovelRT/src/NovelLayeringService.h"

int main(int argc, char* argv[]) {
  auto runner = new MetroidvaniaRT::MetroidvaniaRunner(0, new NovelRT::NovelLayeringService(), 10);
  runner->runNovel();
  return 0;
}
