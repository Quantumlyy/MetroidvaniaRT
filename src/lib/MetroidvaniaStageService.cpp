#include "MetroidvaniaStageService.h"

namespace MetroidvaniaRT {

  MetroidvaniaStageService::MetroidvaniaStageService(NovelRT::NovelRenderingService* renderer) : _renderer(renderer) { }

  MetroidvaniaStageService* MetroidvaniaStageService::addStagePlatform(int stageEntry, MetroidvaniaPlatform* platform) {
    MetroidvaniaStage* stage = stages[stageEntry];
    stage->addPlatform(platform);
    return this;
  }
  MetroidvaniaStageService* MetroidvaniaStageService::addStage(MetroidvaniaStage* stage) {
    stages.push_back(stage);
    return this;
  }

  MetroidvaniaStage* MetroidvaniaStageService::renderStage(int stageEntry) {
    MetroidvaniaStage* stage = stages[stageEntry];
    stage->renderStage(_renderer);
    return stage;
  }

}
