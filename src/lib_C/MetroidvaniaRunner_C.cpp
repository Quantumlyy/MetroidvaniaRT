#include "MetroidvaniaRunner_C.h"

extern "C" {

  MetroidvaniaRunner_t* createRunner(int displayNumber) {
    return reinterpret_cast<MetroidvaniaRunner_t*>(new MetroidvaniaRT::MetroidvaniaRunner(displayNumber));
  }
  void destroyRunner(MetroidvaniaRunner_t* runner) {
    delete reinterpret_cast<MetroidvaniaRT::MetroidvaniaRunner*>(runner);
  }

  MetroidvaniaStageService_t* getRunnerStageService(MetroidvaniaRunner_t* runner) {
    return reinterpret_cast<MetroidvaniaStageService_t*>(reinterpret_cast<MetroidvaniaRT::MetroidvaniaRunner*>(runner)->getStageService());
  }

  int runNovel(MetroidvaniaRunner_t* runner) {
    return reinterpret_cast<MetroidvaniaRT::MetroidvaniaRunner*>(runner)->runNovel();
  }

}
