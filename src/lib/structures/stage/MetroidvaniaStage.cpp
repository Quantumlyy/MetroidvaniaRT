#include "MetroidvaniaStage.h"

namespace MetroidvaniaRT {
  MetroidvaniaStage::MetroidvaniaStage(MetroidvaniaIdentificationInformation& identificationInformation) :
    _II(identificationInformation),
    _computedHighestLayer(0),
    _computedLowestLayer(0) {
    computePlatformLayers();
  }

  MetroidvaniaIdentificationInformation& MetroidvaniaStage::getII() const {
    return _II;
  }

  int MetroidvaniaStage::getComputedHighestLayer() const {
    return _computedHighestLayer;
  }
  int MetroidvaniaStage::getComputedLowestLayer() const {
    return _computedLowestLayer;
  }

  void MetroidvaniaStage::checkIIConfliction(std::unique_ptr<MetroidvaniaPlatform> insertedPlatform) {
    auto insertedII = insertedPlatform.get()->getII();
    for (const std::unique_ptr<MetroidvaniaPlatform>& platform : platforms) {
      auto currentII = platform.get()->getII();

      if (currentII.id == insertedII.id) throw "Platform has a conflicting ID";
      if (currentII.name == insertedII.name) throw "Platform has a conflicting name";
    }
  }

  MetroidvaniaStage* MetroidvaniaStage::addPlatform(std::unique_ptr<MetroidvaniaPlatform> platform) {
    checkIIConfliction(std::move(platform));
    platforms.push_back(std::move(platform));
    computePlatformLayers();
    return this;
  }

  void MetroidvaniaStage::renderPlatforms(NovelRT::NovelRenderingService* renderer) {
    for (const std::unique_ptr<MetroidvaniaPlatform>& platform : platforms)
      platform->formRender(renderer);
  }

  void MetroidvaniaStage::computePlatformLayers() {
    for (const std::unique_ptr<MetroidvaniaPlatform>& platform : platforms) {
      if (platform->getLayer() > _computedHighestLayer) _computedHighestLayer = platform->getLayer();
      if (platform->getLayer() < _computedLowestLayer) _computedLowestLayer = platform->getLayer();
    }
  }

  void MetroidvaniaStage::renderStage(NovelRT::NovelRenderingService* renderer) {
    computePlatformLayers();
    renderPlatforms(renderer);
    raiseStageRendered();
  }
}
