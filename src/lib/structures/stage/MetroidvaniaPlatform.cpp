#include "MetroidvaniaPlatform.h"

#include <string>

#include "../MetroidvaniaCommonArgs.h"
#include "../../../../dependencies/NovelRT/src/NovelImageRect.h"
#include "../../../../dependencies/NovelRT/src/GeoVector.h"
#include "../../../../dependencies/NovelRT/src/RGBAConfig.h"

namespace MetroidvaniaRT {
  MetroidvaniaPlatform::MetroidvaniaPlatform(const NovelRT::GeoVector<float>& startingSize,
    std::string_view filePath,
    const MetroidvaniaCommonArgs& args,
    const NovelRT::RGBAConfig& colourTint)
  {
    this->startingSize = startingSize;
    this.filePath = filePath;
    this->args = args;
    this->colourTint = colourTint;
  }
}
