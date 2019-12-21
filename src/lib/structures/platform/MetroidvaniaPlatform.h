#ifndef METROIDVANIART_METROIDVANIAPLATFORM_H
#define METROIDVANIART_METROIDVANIAPLATFORM_H

#include "../../../../dependencies/NovelRT/src/NovelRT.h"
#include "../../../../dependencies/NovelRT/src/NovelUtilities.h"

namespace MetroidvaniaRT {
  /**
   * The base class for creating a game platform in a stage.
   */
  class MetroidvaniaPlatform {
    NOVELRT_PARAMETERLESS_EVENT(PlatformRendered)
  protected:
    NovelRT::NovelCommonArgs& _args;
    NovelRT::RGBAConfig& _colourTint;
    // The current ID of this Platform.
    int _id;
  public:
    // The object that was rendered when formRender was called.
    NovelRT::NovelRenderObject* renderOb;

    // Gets the current ID of this Platform.
    virtual int getId() const;
    // Sets the current ID of this Platform.
    virtual void setId(int value);

    virtual int getLayer() const;
    virtual void setLayer(int value);

    virtual int getLayerOrder() const;
    virtual void setLayerOrder(int value);

    /**
     * The abstract method for rendering this Platform.
     *
     * @param renderer The RenderingService on which the Platform should be rendered.
     * @returns The rendered object.
     */
    virtual NovelRT::NovelRenderObject* formRender(NovelRT::NovelRenderingService* renderer) = 0;

    MetroidvaniaPlatform(NovelRT::NovelCommonArgs& args, NovelRT::RGBAConfig& colourTint);
  };
}

#endif // METROIDVANIART_METROIDVANIAPLATFORM_H
