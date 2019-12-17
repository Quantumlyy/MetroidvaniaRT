#include "MetroidvaniaFillPlatform.h"

#include "MetroidvaniaPlatform.h"
#include "../../../../dependencies/NovelRT/src/NovelCommonArgs.h"
#include "../../../../dependencies/NovelRT/src/NovelBasicFillRect.h"
#include "../../../../dependencies/NovelRT/src/NovelRenderingService.h"
#include "../../../../dependencies/NovelRT/src/GeoVector.h"
#include "../../../../dependencies/NovelRT/src/RGBAConfig.h"

namespace MetroidvaniaRT {
  MetroidvaniaFillPlatform::MetroidvaniaFillPlatform(NovelRT::GeoVector<float>& startingSize,
    NovelRT::RGBAConfig& colourFill,
    NovelRT::NovelCommonArgs& args) : MetroidvaniaPlatform(startingSize, args, colourFill) { }

  NovelRT::NovelBasicFillRect* MetroidvaniaFillPlatform::formRender(NovelRT::NovelRenderingService* renderer) {
    renderObj = renderer->getBasicFillRect(_startingSize, _colourTint, _args);
    return renderObj;
  }
}
