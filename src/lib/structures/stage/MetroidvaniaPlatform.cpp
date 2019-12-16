#include "MetroidvaniaPlatform.h"

#include <string>

#include "../MetroidvaniaCommonArgs.h"
#include "../../../../dependencies/NovelRT/src/NovelImageRect.h"
#include "../../../../dependencies/NovelRT/src/NovelRenderingService.h"
#include "../../../../dependencies/NovelRT/src/GeoVector.h"
#include "../../../../dependencies/NovelRT/src/RGBAConfig.h"

namespace MetroidvaniaRT {
  MetroidvaniaPlatform::MetroidvaniaPlatform(NovelRT::GeoVector<float>& startingSize,
    std::string filePath,
    MetroidvaniaCommonArgs& args,
    NovelRT::RGBAConfig& colourTint):
      _startingSize(startingSize),
      _filePath(filePath),
      _args(args),
      _colourTint(colourTint) { }

  NovelRT::NovelImageRect* MetroidvaniaPlatform::formRender(NovelRT::NovelRenderingService* renderer) {
    rect = renderer->getImageRect(_startingSize, _filePath, _args, _colourTint);
    return rect;
  }
}
