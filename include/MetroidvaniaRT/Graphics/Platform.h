#ifndef METROIDVANIART_PLATFORM_H
#define METROIDVANIART_PLATFORM_H

#ifndef METROIDVANIART_H
#error Please do not include this directly. Use the centralised header (MetroidvaniaRT.h) instead!
#endif

namespace MetroidvaniaRT::Graphics {
  /**
   * The base class for creating a game platform in a stage.
   */
  class Platform {

    NOVELRT_PARAMETERLESS_EVENT(PlatformRendered)

  protected:
    NovelRT::NovelCommonArgs& _args;
    NovelRT::RGBAConfig& _colourTint;
    // The current identification information of this Platform.
    IdentificationInformation& _II;

  public:
    // The object that was rendered when formRender was called.
    NovelRT::NovelRenderObject* renderOb;

    // Gets the current II of this Platform.
    virtual IdentificationInformation& getII() const;

    virtual int getLayer() const;
    virtual void setLayer(int value);

    /**
     * The abstract method for rendering this Platform.
     *
     * @param renderer The RenderingService on which the Platform should be rendered.
     * @returns The rendered object.
     */
    virtual NovelRT::NovelRenderObject* formRender(NovelRT::NovelRenderingService* renderer) = 0;

    Platform(IdentificationInformation& identificationInformation, NovelRT::NovelCommonArgs& args, NovelRT::RGBAConfig& colourTint);
  };
}

#endif // METROIDVANIART_PLATFORM_H
