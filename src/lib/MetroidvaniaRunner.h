#ifndef METROIDVANIART_METROIDVANIARUNNER_H
#define METROIDVANIART_METROIDVANIARUNNER_H

#include <vector>

#include "./structures/stage/MetroidvaniaStage.h"
#include "../../dependencies/NovelRT/src/NovelRunner.h"
#include "../../dependencies/NovelRT/src/NovelLayeringService.h"

namespace MetroidvaniaRT {
  /**
   * The base class for creating a Metroidvania style game.
   */
  class MetroidvaniaRunner : public NovelRT::NovelRunner {
  public:
    std::vector<MetroidvaniaStage*> stages;

    // TODO: Convert to service
    MetroidvaniaRunner* addStage(MetroidvaniaStage*);

    MetroidvaniaRunner(int, NovelRT::NovelLayeringService*, uint32_t targetFrameRate = 0);
  };
}

#endif // METROIDVANIART_METROIDVANIARUNNER_H
