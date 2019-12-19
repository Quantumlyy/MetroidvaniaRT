#ifndef METROIDVANIART_METROIDVANIARUNNER_H
#define METROIDVANIART_METROIDVANIARUNNER_H

#include <vector>
#include <string>

#include "./structures/stage/MetroidvaniaStage.h"
#include "./MetroidvaniaStageService.h"
#include "../../dependencies/NovelRT/src/NovelRunner.h"

namespace MetroidvaniaRT {
  /**
   * The base class for creating a Metroidvania style game.
   */
  class MetroidvaniaRunner : public NovelRT::NovelRunner {
  private:
    MetroidvaniaStageService _stageService;
  public:
    std::vector<MetroidvaniaStage*> stages;

    // TODO: Convert to service
    MetroidvaniaRunner* addStage(MetroidvaniaStage* stage);

    MetroidvaniaRunner(int displayNumber, const std::string& windowTitle = "MetroidvaniaRTTest", uint32_t targetFrameRate = 0);
  };
}

#endif // METROIDVANIART_METROIDVANIARUNNER_H
