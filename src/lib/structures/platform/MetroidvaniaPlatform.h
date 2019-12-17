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
    // The object that was rendered when formRender was called.
    NovelRT::NovelRenderObject* renderObj;
    /**
     * The abstract method for rendering this Platform.
     * By default it renders a NovelRT::NovelBasicFillRect .
     *
     * @param renderer The RenderingService on which the Platform should be rendered.
     * @returns The rendered object.
     */
    virtual NovelRT::NovelRenderObject* formRender(NovelRT::NovelRenderingService*);

    MetroidvaniaPlatform(NovelRT::GeoVector<float>&, NovelRT::NovelCommonArgs&, NovelRT::RGBAConfig&);
  };
}

#endif // METROIDVANIART_METROIDVANIAPLATFORM_H
