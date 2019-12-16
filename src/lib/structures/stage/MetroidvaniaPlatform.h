#ifndef METROIDVANIART_METROIDVANIAPLATFORM_H
#define METROIDVANIART_METROIDVANIAPLATFORM_H

#include <string>

#include "../MetroidvaniaCommonArgs.h"
#include "../../../../dependencies/NovelRT/src/NovelImageRect.h"
#include "../../../../dependencies/NovelRT/src/NovelRenderingService.h"
#include "../../../../dependencies/NovelRT/src/GeoVector.h"
#include "../../../../dependencies/NovelRT/src/RGBAConfig.h"

namespace MetroidvaniaRT {
  /**
   * The base class for creating a game platform in a stage.
   */
  class MetroidvaniaPlatform {
  private:
    const NovelRT::GeoVector<float>& startingSize;
    std::string filePath;
    const MetroidvaniaCommonArgs& args;
    const NovelRT::RGBAConfig& colourTint;
  public:
    NovelRT::NovelImageRect rect;
    NovelRT::NovelImageRect formRender(const NovelRT::NovelRenderingService&);

    MetroidvaniaPlatform(const NovelRT::GeoVector<float>&, std::string, const MetroidvaniaCommonArgs&, const NovelRT::RGBAConfig&);
  };
}

#endif // METROIDVANIART_METROIDVANIAPLATFORM_H
