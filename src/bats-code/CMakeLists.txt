set(BATS_CODE_SOURCES
    helper/bats-helper.cc
    model/bats-header.cc
)

set(BATS_CODE_HEADERS
    helper/bats-helper.h
    model/bats-header.h
)

add_library(ns3-bats-code MODULE ${BATS_CODE_SOURCES} ${BATS_CODE_HEADERS})

target_link_libraries(ns3-bats-code
    PRIVATE
        ns3-core
        ns3-network
        ns3-internet
        ns3-point-to-point
)