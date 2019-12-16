#include "MetroidvaniaImagePlatform.h"

#include <string>

#include "MetroidvaniaPlatform.h"
#include "../../../../dependencies/NovelRT/src/NovelCommonArgs.h"
#include "../../../../dependencies/NovelRT/src/NovelImageRect.h"
#include "../../../../dependencies/NovelRT/src/NovelRenderingService.h"
#include "../../../../dependencies/NovelRT/src/GeoVector.h"
#include "../../../../dependencies/NovelRT/src/RGBAConfig.h"

namespace MetroidvaniaRT {
  MetroidvaniaImagePlatform::MetroidvaniaImagePlatform(NovelRT::GeoVector<float>& startingSize,
    std::string filePath,
    NovelRT::NovelCommonArgs& args,
    NovelRT::RGBAConfig& colourTint) : MetroidvaniaPlatform(startingSize, args, colourTint), _filePath(filePath) { }

  NovelRT::NovelImageRect* MetroidvaniaPlatform::formRender(NovelRT::NovelRenderingService* renderer) {
    rect = renderer->getImageRect(_startingSize, _filePath, _args, _colourTint);
    return rect;
  }
}
