 #include "MetroidvaniaRunner.h"

#include "./structures/stage/MetroidvaniaStage.h"
#include "../../dependencies/NovelRT/src/NovelRunner.h"
#include "../../dependencies/NovelRT/src/NovelLayeringService.h"

namespace MetroidvaniaRT {

  MetroidvaniaRunner::MetroidvaniaRunner(int displayNumber, NovelRT::NovelLayeringService* layeringService, uint32_t targetFrameRate)
    : NovelRT::NovelRunner(displayNumber, layeringService, targetFrameRate) { }

  MetroidvaniaRunner* MetroidvaniaRunner::addStage(MetroidvaniaStage* stage) {
    stages.push_back(stage);
    return this;
  }
}
