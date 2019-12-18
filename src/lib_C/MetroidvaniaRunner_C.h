#ifndef METROIDVANIART_METROIDVANIARUNNER_C_H
#define METROIDVANIART_METROIDVANIARUNNER_C_H

#include <string>

#ifdef __cplusplus
extern "C" {
#endif
  struct MetroidvaniaRunner_C;
  typedef struct MetroidvaniaRunner_C MetroidvaniaRunner_t;

  MetroidvaniaRunner_t* createRunner(int displayNumber, const std::string& windowTitle = "MetroidvaniaRT", int targetFramerate = 0);
  void destroyRunner(MetroidvaniaRunner_t*);

  int runNovel(MetroidvaniaRunner_t*);

#ifdef __cplusplus
}
#endif

#endif //METROIDVANIART_METROIDVANIARUNNER_C_H
