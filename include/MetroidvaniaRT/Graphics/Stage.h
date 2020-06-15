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

    std::vector<std::unique_ptr<Platform>> platforms;

    virtual IdentificationInformation& getII() const;

    virtual int getComputedHighestLayer() const;
    virtual int getComputedLowestLayer() const;

    virtual void checkIIConfliction(Platform* insertedPlatform);
    void computePlatformLayers();

    Stage* addPlatform(std::unique_ptr<Platform> platform);

    void createPlatforms(NovelRT::Graphics::RenderingService* renderer, bool force = false);
    void renderPlatforms();

    void create(NovelRT::Graphics::RenderingService* renderer, bool force = false);
    void render();

    Stage(IdentificationInformation& identificationInformation);
  };
}

#endif // METROIDVANIART_STAGE_H
