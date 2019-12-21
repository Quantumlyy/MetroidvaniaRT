#include "MetroidvaniaFillPlatform.h"

namespace MetroidvaniaRT {
  MetroidvaniaFillPlatform::MetroidvaniaFillPlatform(NovelRT::RGBAConfig& colourFill,
    NovelRT::NovelCommonArgs& args) : MetroidvaniaPlatform(args, colourFill) { }

  NovelRT::NovelBasicFillRect* MetroidvaniaFillPlatform::formRender(NovelRT::NovelRenderingService* renderer) {
    renderObj = renderer->getBasicFillRect(_colourTint, _args);
    raisePlatformRendered();
    return renderObj;
  }
}
