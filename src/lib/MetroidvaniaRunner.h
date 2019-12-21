#ifndef METROIDVANIART_METROIDVANIARUNNER_H
#define METROIDVANIART_METROIDVANIARUNNER_H

#include <string>

#include "./MetroidvaniaStageService.h"
#include "../../dependencies/NovelRT/src/NovelRT.h"

namespace MetroidvaniaRT {
  /**
   * The base class for creating a Metroidvania style game.
   */
  class MetroidvaniaRunner : public NovelRT::NovelRunner {
  private:
    std::unique_ptr<MetroidvaniaStageService> _stageService;
  public:
    explicit MetroidvaniaRunner(int displayNumber, const std::string& windowTitle = "MetroidvaniaRTTest", uint32_t targetFrameRate = 0);

    MetroidvaniaStageService* getStageService() const;
  };
}

#endif // METROIDVANIART_METROIDVANIARUNNER_H
