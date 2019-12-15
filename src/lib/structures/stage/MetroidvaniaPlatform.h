#ifndef METROIDVANIART_METROIDVANIAPLATFORM_H
#define METROIDVANIART_METROIDVANIAPLATFORM_H

#include <string>

#include "../MetroidvaniaBase.h"
#include "../MetroidvaniaCommonArgs.h"
#include "../../../../dependencies/NovelRT/src/NovelImageRect.h"
#include "../../../../dependencies/NovelRT/src/GeoVector.h"
#include "../../../../dependencies/NovelRT/src/RGBAConfig.h"

namespace MetroidvaniaRT {
  /**
   * The base class for creating a game platform in a stage.
   */
  class MetroidvaniaPlatform : public MetroidvaniaBase {
  private:
    const NovelRT::GeoVector<float>& startingSize;
    std::string_view filePath;
    const MetroidvaniaCommonArgs& args;
    const NovelRT::RGBAConfig& colourTint;
  public:
    NovelRT::NovelImageRect rect;

    MetroidvaniaPlatform(const NovelRT::GeoVector<float>& startingSize,
      std::string_view filePath,
      const MetroidvaniaCommonArgs& args,
      const NovelRT::RGBAConfig& colourTint);
  };
}

#endif // METROIDVANIART_METROIDVANIAPLATFORM_H
