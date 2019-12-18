#include "../lib/MetroidvaniaRunner.h"
#include "MetroidvaniaRunner_C.h"

extern "C" {
  MetroidvaniaRunner_t createRunner(int displayNumber, const std::string& windowTitle, int targetFramerate) {
    return reinterpret_cast<MetroidvaniaRunner_t*>(new MetroidvaniaRT::MetroidvaniaRunner(displayNumber, windowTitle, targetFramerate));
  }

  void destroyRunner(MetroidvaniaRunner_t* runner) {
    delete reinterpret_cast<MetroidvaniaRT::MetroidvaniaRunner*>(runner);
  }

  int runNovel(MetroidvaniaRunner_t* runner) {
    return reinterpret_cast<MetroidvaniaRT::MetroidvaniaRunner*>(runner)->runNovel();
  }
}
