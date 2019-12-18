#include "MetroidvaniaStage.h"

namespace MetroidvaniaRT {
  MetroidvaniaStage::MetroidvaniaStage(int id) : _id(id) { }

  int MetroidvaniaStage::getId() const {
    return _id;
  }
  void MetroidvaniaStage::setId(int value) {
    _id = value;
  }

  MetroidvaniaStage* MetroidvaniaStage::addPlatform(MetroidvaniaPlatform* platform) {
    platforms.push_back(platform);
    return this;
  }
  void MetroidvaniaStage::renderPlatforms(NovelRT::NovelRenderingService* renderer) {
    for (MetroidvaniaPlatform* platform : platforms)
      platform->formRender(renderer);
  }
  void MetroidvaniaStage::renderStage(NovelRT::NovelRenderingService* renderer) {
    renderPlatforms(renderer);
    raiseFinishedRender();
  }
}
