#ifndef BATS_CODE_H
#define BATS_CODE_H

#include <vector>
#include <memory>
#include <string>
#include <iostream>

namespace ns3 {

class BatCode {
public:
    static std::vector<std::vector<uint8_t>> Encode(const std::vector<std::vector<uint8_t>>& packets, uint32_t batchSize, uint32_t fieldSize);
    static bool Decode(const std::vector<std::vector<uint8_t>>& encodedPackets, const std::vector<std::vector<uint8_t>>& originalPackets);

private:
    static std::vector<std::vector<uint8_t>> GenerateRandomMatrix(uint32_t rows, uint32_t cols, uint32_t fieldSize);
};

} // namespace ns3

#endif // BATS_CODE_H
