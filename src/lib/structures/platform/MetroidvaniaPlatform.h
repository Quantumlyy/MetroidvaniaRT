#ifndef METROIDVANIART_METROIDVANIAPLATFORM_H
#define METROIDVANIART_METROIDVANIAPLATFORM_H

#include "../MetroidvaniaIdentificationInformation.h"
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
    // The current identification information of this Platform.
    MetroidvaniaIdentificationInformation& _II;
  public:
    // The object that was rendered when formRender was called.
    NovelRT::NovelRenderObject* renderOb;

    // Gets the current II of this Platform.
    virtual MetroidvaniaIdentificationInformation& getII() const;

    virtual int getLayer() const;
    virtual void setLayer(int value);

    /**
     * The abstract method for rendering this Platform.
     *
     * @param renderer The RenderingService on which the Platform should be rendered.
     * @returns The rendered object.
     */
    virtual NovelRT::NovelRenderObject* formRender(NovelRT::NovelRenderingService* renderer) = 0;

    MetroidvaniaPlatform(MetroidvaniaIdentificationInformation& identificationInformation, NovelRT::NovelCommonArgs& args, NovelRT::RGBAConfig& colourTint);
  };
}

#endif // METROIDVANIART_METROIDVANIAPLATFORM_H
