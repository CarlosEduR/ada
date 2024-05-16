#include <fuzzer/FuzzedDataProvider.h>

#include <memory>
#include <string>

#include "ada.cpp"
#include "ada.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  FuzzedDataProvider fdp(data, size);
  std::string source = fdp.ConsumeRandomLengthString(256);
  std::string base_source = fdp.ConsumeRandomLengthString(256);

  /**
   * ada::validate
   */
  auto out_aggregator = ada::parse<ada::url_aggregator>(source);
  if (out_aggregator) {
    out_aggregator->validate();
  }

  return 0;
}
