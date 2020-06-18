#ifndef METROIDVANIART_PLATFORM_H
#define METROIDVANIART_PLATFORM_H

#ifndef METROIDVANIART_H
#error Please do not include this directly. Use the centralised header (MetroidvaniaRT.h) instead!
#endif

namespace MetroidvaniaRT::Graphics {
  /**
   * The base class for creating a game platform in a stage.
   */
  template<typename RenderedObj, typename std::enable_if<std::is_base_of<NovelRT::Graphics::RenderObject, RenderedObj>::value>::type * = nullptr>
  class Platform {

  protected:
    NovelRT::Transform& _transform;
    NovelRT::Graphics::RGBAConfig& _colourTint;
    int _layer;
    // The current identification information of this Platform.
    IdentificationInformation& _II;
    bool _created;

  public:
    Platform(IdentificationInformation& identificationInformation,
      NovelRT::Transform& transform,
      int layer,
      NovelRT::Graphics::RGBAConfig& colourTint) :
      PlatformCreated(NovelRT::Utilities::Event<>()),
      PlatformRendered(NovelRT::Utilities::Event<>()),
      _transform(transform),
      _layer(layer),
      _colourTint(colourTint),
      _II(identificationInformation),
      _created(false) { }

    NovelRT::Utilities::Event<> PlatformCreated;
    NovelRT::Utilities::Event<> PlatformRendered;

    // The object that was rendered when create was called.
    std::shared_ptr<RenderedObj> renderObj;

    // Gets the current II of this Platform.
    virtual IdentificationInformation& getII() const noexcept {
      return _II;
    }

    virtual bool getCreated() const noexcept {
      return _created;
    }

    virtual int getLayer() {
      _layer = renderObj->layer();
      return _layer;
    }
    virtual void setLayer(int value) {
      renderObj->layer() = value;
      _layer = renderObj->layer();
    }

    virtual std::shared_ptr<RenderedObj> create(std::weak_ptr<NovelRT::Graphics::RenderingService> renderer) = 0;
    virtual void render() {
      renderObj->executeObjectBehaviour();
      PlatformRendered();
    }
  };
}

#endif // METROIDVANIART_PLATFORM_H
