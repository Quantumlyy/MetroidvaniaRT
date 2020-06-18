#include <MetroidvaniaRT.h>

namespace MetroidvaniaRT::Graphics {
  Stage::Stage(IdentificationInformation& identificationInformation) :
    StageCreated(NovelRT::Utilities::Event<>()),
    StageRendered(NovelRT::Utilities::Event<>()),
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

  void Stage::computePlatformLayers() {
    for (const std::unique_ptr<Platform>& platform : platforms) {
      auto layer = platform.get()->getLayer();
      if (layer > getComputedHighestLayer()) _computedHighestLayer = layer;
      if (layer < getComputedLowestLayer()) _computedLowestLayer = layer;
    }
  }

  void Stage::createPlatforms(std::weak_ptr<NovelRT::Graphics::RenderingService> renderer, bool force) {
    for (const std::unique_ptr<Platform>& platform : platforms)
      if (force || !platform.get()->getCreated()) platform.get()->create(renderer);
  }
  void Stage::renderPlatforms() {
    for (const std::unique_ptr<Platform<NovelRT::Graphics::RenderObject>>& platform : platforms)
      platform->render();
  }

  void Stage::create(std::weak_ptr<NovelRT::Graphics::RenderingService> renderer, bool force) {
    createPlatforms(renderer, force);
    StageCreated();
  }
  void Stage::render() {
    renderPlatforms();
    StageRendered();
  }
}
