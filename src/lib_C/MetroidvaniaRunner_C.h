#ifndef METROIDVANIART_METROIDVANIARUNNER_C_H
#define METROIDVANIART_METROIDVANIARUNNER_C_H

#include "MetroidvaniaStageService_C.h"
#include "../../include/MetroidvaniaRT.h"

#ifdef __cplusplus
extern "C" {
#endif
  struct MetroidvaniaRunner_C;
  typedef struct MetroidvaniaRunner_C MetroidvaniaRunner_t;

  MetroidvaniaRunner_t* createRunner(int);
  void destroyRunner(MetroidvaniaRunner_t*);

  MetroidvaniaStageService_t* getRunnerStageService(MetroidvaniaRunner_t*);

  int runNovel(MetroidvaniaRunner_t*);

#ifdef __cplusplus
}
#endif

#endif //METROIDVANIART_METROIDVANIARUNNER_C_H
