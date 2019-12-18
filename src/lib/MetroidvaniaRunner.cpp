 #include "MetroidvaniaRunner.h"

namespace MetroidvaniaRT {

  MetroidvaniaRunner::MetroidvaniaRunner(int displayNumber, uint32_t targetFrameRate)
    : NovelRT::NovelRunner(displayNumber, targetFrameRate) { }

  MetroidvaniaRunner* MetroidvaniaRunner::addStage(MetroidvaniaStage* stage) {
    stages.push_back(stage);
    return this;
  }
}
