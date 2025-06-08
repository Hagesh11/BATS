set(sources
    helper/bats-helper.cc
    model/bats-header.cc
    test/bats-code.cc
)

set(headers
    helper/bats-helper.h
    model/bats-header.h
    test/bats-code.h
)

add_library(ns3-bats-code MODULE ${sources} ${headers})
target_link_libraries(ns3-bats-code ns3-core ns3-network)