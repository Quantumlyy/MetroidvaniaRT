#include "MetroidvaniaStage.h"

#include <vector>

#include "MetroidvaniaPlatform.h"
#include "../../../../dependencies/NovelRT/src/NovelRenderingService.h"

namespace MetroidvaniaRT {
  MetroidvaniaStage::MetroidvaniaStage() { }

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
    for each (MetroidvaniaPlatform* platform in platforms)
    {
      platform->formRender(renderer);
    }
  }
}
