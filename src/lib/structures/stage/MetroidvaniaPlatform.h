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
    NovelRT::GeoVector<float>& _startingSize;
    std::string _filePath;
    MetroidvaniaCommonArgs& _args;
    NovelRT::RGBAConfig& _colourTint;
  public:
    NovelRT::NovelImageRect* rect;
    NovelRT::NovelImageRect* formRender(NovelRT::NovelRenderingService*);

    MetroidvaniaPlatform(NovelRT::GeoVector<float>&, std::string, MetroidvaniaCommonArgs&, NovelRT::RGBAConfig&);
  };
}

#endif // METROIDVANIART_METROIDVANIAPLATFORM_H
