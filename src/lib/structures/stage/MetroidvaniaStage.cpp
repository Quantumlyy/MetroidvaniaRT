#include "MetroidvaniaStage.h"

namespace MetroidvaniaRT {
  MetroidvaniaStage::MetroidvaniaStage(MetroidvaniaIdentificationInformation& identificationInformation) :
    _II(identificationInformation),
    _computedHighestLayer(0),
    _computedLowestLayer(0) { }

  MetroidvaniaIdentificationInformation& MetroidvaniaStage::getII() const {
    return _II;
  }

  int MetroidvaniaStage::getComputedHighestLayer() const {
    return _computedHighestLayer;
  }
  int MetroidvaniaStage::getComputedLowestLayer() const {
    return _computedLowestLayer;
  }

  void MetroidvaniaStage::checkIIConfliction(MetroidvaniaPlatform* insertedPlatform) {
    auto insertedII = insertedPlatform->getII();
    for (const std::unique_ptr<MetroidvaniaPlatform>& platform : platforms) {
      auto currentII = platform.get()->getII();
      
      if (currentII.id == insertedII.id) throw std::logic_error("Platform has a conflicting ID");
      if ((currentII.name == insertedII.name) && (insertedII.name != "")) throw std::logic_error("Platform has a conflicting name");
    }
  }

  MetroidvaniaStage* MetroidvaniaStage::addPlatform(std::unique_ptr<MetroidvaniaPlatform> platform) {
    checkIIConfliction(platform.get());
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
      auto layer = platform.get()->getLayer();
      if (layer  > getComputedHighestLayer()) _computedHighestLayer = layer;
      if (layer < getComputedLowestLayer()) _computedLowestLayer = layer;
    }
  }

  void MetroidvaniaStage::renderStage(NovelRT::NovelRenderingService* renderer) {
    computePlatformLayers();
    renderPlatforms(renderer);
    raiseStageRendered();
  }
}
