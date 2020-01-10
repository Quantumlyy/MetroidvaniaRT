#ifndef METROIDVANIART_METROIDVANIARUNNER_H
#define METROIDVANIART_METROIDVANIARUNNER_H

#ifndef METROIDVANIART_H
#error Please do not include this directly. Use the centralised header (MetroidvaniaRT.h) instead!
#endif

namespace MetroidvaniaRT {
  /**
   * The base class for creating a Metroidvania style game.
   */
  class MetroidvaniaRunner : public NovelRT::NovelRunner {

  private:
    std::unique_ptr<Graphics::StageService> _stageService;

  public:
    explicit MetroidvaniaRunner(int displayNumber, const std::string& windowTitle = "MetroidvaniaRTTest", uint32_t targetFrameRate = 0);

    Graphics::StageService* getStageService() const;
  };
}

#endif // METROIDVANIART_METROIDVANIARUNNER_H
