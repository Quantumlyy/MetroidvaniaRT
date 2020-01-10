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
    NovelRT::Transform& _args;
    NovelRT::Graphics::RGBAConfig& _colourTint;
    // The current identification information of this Platform.
    IdentificationInformation& _II;

  public:
    // The object that was rendered when formRender was called.
    NovelRT::Graphics::RenderObject* renderOb;

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
    virtual NovelRT::Graphics::RenderObject* formRender(NovelRT::Graphics::RenderingService* renderer) = 0;

    Platform(IdentificationInformation& identificationInformation, NovelRT::Transform& args, NovelRT::Graphics::RGBAConfig& colourTint);
  };
}

#endif // METROIDVANIART_PLATFORM_H
