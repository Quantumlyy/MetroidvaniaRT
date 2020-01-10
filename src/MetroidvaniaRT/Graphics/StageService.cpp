#include <MetroidvaniaRT.h>

namespace MetroidvaniaRT::Graphics {

  StageService::StageService(MetroidvaniaRunner* const runner) :
    _runner(runner) { }

  StageService* StageService::addStage(std::unique_ptr<Stage> stage) {
    stages.insert(std::pair(stage.get()->getII(), std::move(stage)));
    return this;
  }

  Stage* StageService::getStage(int _id) {
    auto opts = IdentificationInformation();
    opts.id = _id;
    return stages.at(opts).get();
  }
  Stage* StageService::getStage(const std::string& _name) {
    auto opts = IdentificationInformation();
    opts.name = _name;
    return stages.at(opts).get();
  }

  StageService* StageService::addStagePlatform(int stageId, std::unique_ptr<Platform> platform) {
    auto stage = getStage(stageId);
    stage->addPlatform(std::move(platform));
    return this;
  }
  StageService* StageService::addStagePlatform(const std::string& stageName, std::unique_ptr<Platform> platform) {
    auto stage = getStage(stageName);
    stage->addPlatform(std::move(platform));
    return this;
  }

  Stage* StageService::renderStage(int stageId) {
    auto stage = getStage(stageId);
    stage->renderStage(_runner->getRenderer());
    return stage;
  }
  Stage* StageService::renderStage(const std::string& stageName) {
    auto stage = getStage(stageName);
    stage->renderStage(_runner->getRenderer());
    return stage;
  }
}
