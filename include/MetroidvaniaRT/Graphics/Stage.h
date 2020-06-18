#ifndef METROIDVANIART_STAGE_H
#define METROIDVANIART_STAGE_H

#ifndef METROIDVANIART_H
#error Please do not include this directly. Use the centralised header (MetroidvaniaRT.h) instead!
#endif

namespace MetroidvaniaRT::Graphics {
  /**
   * The base class for a Stage.
   */
  class Stage { 

  protected:
    IdentificationInformation& _II;
    int _computedHighestLayer;
    int _computedLowestLayer;

  public:
    NovelRT::Utilities::Event<> StageCreated;
    NovelRT::Utilities::Event<> StageRendered;

    std::vector<std::unique_ptr<Platform<NovelRT::Graphics::RenderObject>>> platforms;

    virtual IdentificationInformation& getII() const;

    virtual int getComputedHighestLayer() const;
    virtual int getComputedLowestLayer() const;

    template<typename RenderedObj, typename std::enable_if<std::is_base_of<NovelRT::Graphics::RenderObject, RenderedObj>::value>::type * = nullptr>
    void checkIIConfliction(Platform<RenderedObj>* insertedPlatform) {
      auto insertedII = insertedPlatform->getII();
      for (const std::unique_ptr<Platform>& platform : platforms) {
        auto currentII = platform.get()->getII();

        if (currentII.id == insertedII.id) throw std::logic_error("Platform has a conflicting ID");
        if ((currentII.name == insertedII.name) && (insertedII.name != "")) throw std::logic_error("Platform has a conflicting name");
      }
    }
    void computePlatformLayers();

    template<typename RenderedObj, typename std::enable_if<std::is_base_of<NovelRT::Graphics::RenderObject, RenderedObj>::value>::type * = nullptr>
    Stage* addPlatform(std::unique_ptr<Platform<RenderedObj>> platform) {
      checkIIConfliction(platform.get());
      platforms.push_back(std::move(platform));
      computePlatformLayers();
      //std::sort(platforms.begin(), platforms.end(), [](std::unique_ptr<Platform> x, std::unique_ptr<Platform> y) { return (x.get()->getLayer() < y.get()->getLayer()); });
      return this;
    }

    void createPlatforms(std::weak_ptr<NovelRT::Graphics::RenderingService> renderer, bool force = false);
    void renderPlatforms();

    void create(std::weak_ptr<NovelRT::Graphics::RenderingService> renderer, bool force = false);
    void render();

    Stage(IdentificationInformation& identificationInformation);
  };
}

#endif // METROIDVANIART_STAGE_H
