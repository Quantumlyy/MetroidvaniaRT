#ifndef METROIDVANIART_METROIDVANIARUNNER_H
#define METROIDVANIART_METROIDVANIARUNNER_H

#include <map>
#include <string>

#include "../../dependencies/NovelRT/src/NovelRunner.h"
#include "../../dependencies/NovelRT/src/NovelLayeringService.h"

namespace MetroidvaniaRT {
  /**
   * The base class for creating a Metroidvania style game.
   */
  class MetroidvaniaRunner : public NovelRT::NovelRunner {
  public:
    MetroidvaniaRunner(int, NovelRT::NovelLayeringService*, uint32_t targetFrameRate = 0);
  };
}

#endif // METROIDVANIART_METROIDVANIARUNNER_H
