#include <MetroidvaniaRT.h>

namespace MetroidvaniaRT::Graphics {
  Stage::Stage(IdentificationInformation& identificationInformation) :
    _II(identificationInformation),
    _computedHighestLayer(0),
    _computedLowestLayer(0) { }

  IdentificationInformation& Stage::getII() const {
    return _II;
  }

  int Stage::getComputedHighestLayer() const {
    return _computedHighestLayer;
  }
  int Stage::getComputedLowestLayer() const {
    return _computedLowestLayer;
  }

  void Stage::checkIIConfliction(Platform* insertedPlatform) {
    auto insertedII = insertedPlatform->getII();
    for (const std::unique_ptr<Platform>& platform : platforms) {
      auto currentII = platform.get()->getII();
      
      if (currentII.id == insertedII.id) throw std::logic_error("Platform has a conflicting ID");
      if ((currentII.name == insertedII.name) && (insertedII.name != "")) throw std::logic_error("Platform has a conflicting name");
    }
  }
  void Stage::computePlatformLayers() {
    for (const std::unique_ptr<Platform>& platform : platforms) {
      auto layer = platform.get()->getLayer();
      if (layer > getComputedHighestLayer()) _computedHighestLayer = layer;
      if (layer < getComputedLowestLayer()) _computedLowestLayer = layer;
    }
  }

  Stage* Stage::addPlatform(std::unique_ptr<Platform> platform) {
    checkIIConfliction(platform.get());
    platforms.push_back(std::move(platform));
    computePlatformLayers();
    std::sort(platforms.begin(), platforms.end(), [](Platform x, Platform y) { return (x.getLayer() < y.getLayer()); });
    return this;
  }

  void Stage::createPlatforms(NovelRT::Graphics::RenderingService* renderer, bool force) {
    for (const std::unique_ptr<Platform>& platform : platforms)
      if (force || !platform->getCreated()) platform->create(renderer);
  }
  void Stage::renderPlatforms() {
    for (const std::unique_ptr<Platform>& platform : platforms)
      platform->render();
  }

  void Stage::create(NovelRT::Graphics::RenderingService* renderer, bool force) {
    createPlatforms(renderer, force);
    raiseStageCreated();
  }
  void Stage::render() {
    renderPlatforms();
    raiseStageRendered();
  }
}
