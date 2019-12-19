 #include "MetroidvaniaRunner.h"

namespace MetroidvaniaRT {

  MetroidvaniaRunner::MetroidvaniaRunner(int displayNumber, const std::string& windowTitle, uint32_t targetFrameRate)
    : NovelRT::NovelRunner(displayNumber, windowTitle, targetFrameRate), _stageService(getRenderer()) { }

  MetroidvaniaRunner* MetroidvaniaRunner::addStage(MetroidvaniaStage* stage) {
    stages.push_back(stage);
    return this;
  }
}
