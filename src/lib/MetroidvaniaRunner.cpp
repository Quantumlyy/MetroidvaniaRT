 #include "MetroidvaniaRunner.h"

namespace MetroidvaniaRT {

  MetroidvaniaRunner::MetroidvaniaRunner(int displayNumber, const std::string& windowTitle, uint32_t targetFrameRate)
    : NovelRT::NovelRunner(displayNumber, windowTitle, targetFrameRate), _stageService(new MetroidvaniaStageService(getRenderer())) { }

  MetroidvaniaStageService* MetroidvaniaRunner::getStageService() const {
    return _stageService.get();
  }
}
