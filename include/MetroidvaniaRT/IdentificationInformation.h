#ifndef METROIDVANIART_IDENTIFICATIONINFORMATION_H
#define METROIDVANIART_IDENTIFICATIONINFORMATION_H

#ifndef METROIDVANIART_H
#error Please do not include this directly. Use the centralised header (MetroidvaniaRT.h) instead!
#endif

namespace MetroidvaniaRT {
  struct IdentificationInformation {

  public:
    std::string name = "";
    int32_t id = 0;

    IdentificationInformation() {};
  };
}

#endif // METROIDVANIART_IDENTIFICATIONINFORMATION_H
