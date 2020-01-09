#include "MetroidvaniaStageService.h"

namespace MetroidvaniaRT {

  MetroidvaniaStageService::MetroidvaniaStageService() { }

  MetroidvaniaStageService* MetroidvaniaStageService::addStage(std::unique_ptr<MetroidvaniaStage> stage) {
    stages.insert(std::pair(stage.get()->getII(), std::move(stage)));
    return this;
  }

  MetroidvaniaStage* MetroidvaniaStageService::getStage(int _id) {
    auto opts = MetroidvaniaIdentificationInformation();
    opts.id = _id;
    return stages.at(opts).get();
  }
  MetroidvaniaStage* MetroidvaniaStageService::getStage(const std::string& _name) {
    auto opts = MetroidvaniaIdentificationInformation();
    opts.name = _name;
    return stages.at(opts).get();
  }

  MetroidvaniaStageService* MetroidvaniaStageService::addStagePlatform(int stageId, std::unique_ptr<MetroidvaniaPlatform> platform) {
    auto stage = getStage(stageId);
    stage->addPlatform(std::move(platform));
    return this;
  }
  MetroidvaniaStageService* MetroidvaniaStageService::addStagePlatform(const std::string& stageName, std::unique_ptr<MetroidvaniaPlatform> platform) {
    auto stage = getStage(stageName);
    stage->addPlatform(std::move(platform));
    return this;
  }

  MetroidvaniaStage* MetroidvaniaStageService::renderStage(NovelRT::NovelRenderingService* renderer, int stageId) {
    auto stage = getStage(stageId);
    stage->renderStage(renderer);
    return stage;
  }
  MetroidvaniaStage* MetroidvaniaStageService::renderStage(NovelRT::NovelRenderingService* renderer, const std::string& stageName) {
    auto stage = getStage(stageName);
    stage->renderStage(renderer);
    return stage;
  }
}
