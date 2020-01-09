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

    NOVELRT_PARAMETERLESS_EVENT(StageRendered)

  protected:
    IdentificationInformation& _II;
    int _computedHighestLayer;
    int _computedLowestLayer;

  public:
    std::vector<std::unique_ptr<Platform>> platforms;

    virtual IdentificationInformation& getII() const;

    virtual int getComputedHighestLayer() const;
    virtual int getComputedLowestLayer() const;

    virtual void checkIIConfliction(Platform* insertedPlatform);

    Stage* addPlatform(std::unique_ptr<Platform> platform);
    void renderPlatforms(NovelRT::NovelRenderingService* renderer);
    void computePlatformLayers();
    void renderStage(NovelRT::NovelRenderingService* renderer);

    Stage(IdentificationInformation& identificationInformation);
  };
}

#endif // METROIDVANIART_STAGE_H
