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
    NovelRT::NovelCommonArgs& _args;
    NovelRT::RGBAConfig& _colourTint;
    // The current ID of this Platform.
    int _id;
  public:
    // The object that was rendered when formRender was called.
    NovelRT::NovelRenderObject* renderObj;

    // Gets the current ID of this Platform.
    virtual int getId() const;
    // Sets the current ID of this Platform.
    virtual void setId(int value);

    /**
     * The abstract method for rendering this Platform.
     *
     * @param renderer The RenderingService on which the Platform should be rendered.
     * @returns The rendered object.
     */
    virtual NovelRT::NovelRenderObject* formRender(NovelRT::NovelRenderingService*) = 0;

    MetroidvaniaPlatform(NovelRT::NovelCommonArgs&, NovelRT::RGBAConfig&);
  };
}

#endif // METROIDVANIART_METROIDVANIAPLATFORM_H
