#include "MetroidvaniaPlatform.h"

#include "../../../../dependencies/NovelRT/src/NovelCommonArgs.h"
#include "../../../../dependencies/NovelRT/src/NovelRenderObject.h"
#include "../../../../dependencies/NovelRT/src/NovelRenderingService.h"
#include "../../../../dependencies/NovelRT/src/GeoVector.h"
#include "../../../../dependencies/NovelRT/src/RGBAConfig.h"

namespace MetroidvaniaRT {
  MetroidvaniaPlatform::MetroidvaniaPlatform(NovelRT::GeoVector<float>& startingSize,
    NovelRT::NovelCommonArgs& args,
    NovelRT::RGBAConfig& colourTint):
      _startingSize(startingSize),
      _args(args),
      _colourTint(colourTint) { }

  NovelRT::NovelRenderObject* MetroidvaniaPlatform::formRender(NovelRT::NovelRenderingService* renderer) {
    renderObj = renderer->getBasicFillRect(_startingSize, _colourTint, _args);
    return renderObj;
  }
}
