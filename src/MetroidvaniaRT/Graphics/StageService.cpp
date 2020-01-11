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

  Stage* StageService::createStage(int stageId, bool force) {
    auto stage = getStage(stageId);
    stage->createPlatforms(_runner->getRenderer(), force);
    return stage;
  }
  Stage* StageService::createStage(const std::string& stageName, bool force) {
    auto stage = getStage(stageName);
    stage->createPlatforms(_runner->getRenderer(), force);
    return stage;
  }

  Stage* StageService::renderStage(int stageId) {
    auto stage = getStage(stageId);
    stage->render();
    return stage;
  }
  Stage* StageService::renderStage(const std::string& stageName) {
    auto stage = getStage(stageName);
    stage->render();
    return stage;
  }

  void StageService::initiateRenderLoopStage(int stageId) {
    auto stage = getStage(stageId);
    _runner->subscribeToSceneConstructionRequested([stage] {
      stage->render();
      });
  }
  void StageService::initiateRenderLoopStage(const std::string& stageName) {
    auto stage = getStage(stageName);
    _runner->subscribeToSceneConstructionRequested([stage] {
      stage->render();
    });
  }
}
