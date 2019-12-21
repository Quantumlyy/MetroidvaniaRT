#include "MetroidvaniaStage.h"

namespace MetroidvaniaRT {
  MetroidvaniaStage::MetroidvaniaStage(int id) :
    _id(id),
    _computedHighestLayer(0),
    _computedLowestLayer(0),
    _computedHighestLayerOrder(0),
    _computedLowestLayerOrder(0) { }

  int MetroidvaniaStage::getId() const {
    return _id;
  }
  void MetroidvaniaStage::setId(int value) {
    _id = value;
  }

  int MetroidvaniaStage::getComputedHighestLayer() const {
    return _computedHighestLayer;
  }
  int MetroidvaniaStage::getComputedLowestLayer() const {
    return _computedLowestLayer;
  }
  int MetroidvaniaStage::getComputedHighestLayerOrder() const {
    return _computedHighestLayerOrder;
  }
  int MetroidvaniaStage::getComputedLowestLayerOrder() const {
    return _computedLowestLayerOrder;
  }

  MetroidvaniaStage* MetroidvaniaStage::addPlatform(MetroidvaniaPlatform* platform) {
    platforms.push_back(platform);
    return this;
  }

  void MetroidvaniaStage::renderPlatforms(NovelRT::NovelRenderingService* renderer) {
    for (MetroidvaniaPlatform* platform : platforms)
      platform->formRender(renderer);
  }
  void MetroidvaniaStage::computePlatforms() {
    for (const MetroidvaniaPlatform* platform : platforms) {
      if (platform->getLayer() > _computedHighestLayer) _computedHighestLayer = platform->getLayer();
      if (platform->getLayer() < _computedLowestLayer) _computedLowestLayer = platform->getLayer();
      if (platform->getLayerOrder() > _computedHighestLayerOrder) _computedHighestLayerOrder = platform->getLayerOrder();
      if (platform->getLayerOrder() < _computedLowestLayerOrder) _computedLowestLayerOrder = platform->getLayerOrder();
    }
  }

  void MetroidvaniaStage::renderStage(NovelRT::NovelRenderingService* renderer) {
    renderPlatforms(renderer);
    computePlatforms();
    raiseStageRendered();
  }

  MetroidvaniaStage::~MetroidvaniaStage() {
    for (const MetroidvaniaPlatform* platform : platforms)
      delete platform;
  }
}
