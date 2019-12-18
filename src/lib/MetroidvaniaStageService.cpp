#include "MetroidvaniaStageService.h"

#include "./structures/stage/MetroidvaniaStage.h"
#include "../../dependencies/NovelRT/src/NovelRenderingService.h"

namespace MetroidvaniaRT {

  MetroidvaniaStageService::MetroidvaniaStageService(std::unique_ptr<NovelRT::NovelRenderingService> renderer) : _renderer(renderer) { }

  MetroidvaniaStageService* MetroidvaniaStageService::addStage(MetroidvaniaStage* stage) {
    stages.push_back(stage);
    return this;
  }
  MetroidvaniaStage* MetroidvaniaStageService::renderStage(const int& stage) {
    MetroidvaniaStage* stag = stages[stage];
    // TODO Finish
  }

}
