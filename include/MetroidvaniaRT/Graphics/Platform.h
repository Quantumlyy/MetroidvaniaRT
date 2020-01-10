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

    NOVELRT_PARAMETERLESS_EVENT(PlatformCreated)
    NOVELRT_PARAMETERLESS_EVENT(PlatformRendered)

  protected:
    NovelRT::Transform& _transform;
    NovelRT::Graphics::RGBAConfig& _colourTint;
    int _layer;
    // The current identification information of this Platform.
    IdentificationInformation& _II;

  public:
    // The object that was rendered when create was called.
    NovelRT::Graphics::RenderObject* renderObj;

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
    virtual NovelRT::Graphics::RenderObject* create(NovelRT::Graphics::RenderingService* renderer) = 0;
    virtual void render();

    Platform(IdentificationInformation& identificationInformation, NovelRT::Transform& transform, int layer, NovelRT::Graphics::RGBAConfig& colourTint);
  };
}

#endif // METROIDVANIART_PLATFORM_H
