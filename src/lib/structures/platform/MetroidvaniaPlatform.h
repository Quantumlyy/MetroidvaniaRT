#ifndef METROIDVANIART_METROIDVANIAPLATFORM_H
#define METROIDVANIART_METROIDVANIAPLATFORM_H

#include "../../../../dependencies/NovelRT/src/NovelCommonArgs.h"
#include "../../../../dependencies/NovelRT/src/NovelRenderObject.h"
#include "../../../../dependencies/NovelRT/src/NovelRenderingService.h"
#include "../../../../dependencies/NovelRT/src/GeoVector.h"
#include "../../../../dependencies/NovelRT/src/RGBAConfig.h"

namespace MetroidvaniaRT {
  /**
   * The base class for creating a game platform in a stage.
   */
  class MetroidvaniaPlatform {
  protected:
    NovelRT::GeoVector<float>& _startingSize;
    NovelRT::NovelCommonArgs& _args;
    NovelRT::RGBAConfig& _colourTint;
  public:
    NovelRT::NovelRenderObject* renderObj;
    virtual NovelRT::NovelRenderObject* formRender(NovelRT::NovelRenderingService*);

    MetroidvaniaPlatform(NovelRT::GeoVector<float>&, NovelRT::NovelCommonArgs&, NovelRT::RGBAConfig&);
  };
}

#endif // METROIDVANIART_METROIDVANIAPLATFORM_H
