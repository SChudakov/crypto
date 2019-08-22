add_library(algorithm)

target_sources(algorithm
        PRIVATE
        GCD.cpp
        ExtendedGCD.cpp
        PollardsRhoFactorization.cpp
        BabyStepGiantStepDiscreteLogarithm.cpp
        EulerFunction.cpp
        MobuisFunction.cpp
        SolovayStrassen.cpp
        JacobianSymbol.cpp
        LegendreSymbol.cpp
        CipollasAlgorithm.cpp
        UniformRandomGenerator.cpp
        FloydAlgorithm.cpp
        ChineseRemainderProblem.cpp
        EllipticCurve.cpp
        ElGamalCryptosystem.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/GCD.h
        ${CMAKE_CURRENT_LIST_DIR}/ExtendedGCD.h
        ${CMAKE_CURRENT_LIST_DIR}/PollardsRhoFactorization.h
        ${CMAKE_CURRENT_LIST_DIR}/BabyStepGiantStepDiscreteLogarithm.h
        ${CMAKE_CURRENT_LIST_DIR}/EulerFunction.h
        ${CMAKE_CURRENT_LIST_DIR}/MobuisFunction.h
        ${CMAKE_CURRENT_LIST_DIR}/SolovayStrassen.h
        ${CMAKE_CURRENT_LIST_DIR}/JacobianSymbol.h
        ${CMAKE_CURRENT_LIST_DIR}/LegendreSymbol.h
        ${CMAKE_CURRENT_LIST_DIR}/CipollasAlgorithm.h
        ${CMAKE_CURRENT_LIST_DIR}/UniformRandomGenerator.h
        ${CMAKE_CURRENT_LIST_DIR}/FloydAlgorithm.h
        ${CMAKE_CURRENT_LIST_DIR}/ChineseRemainderProblem.h
        ${CMAKE_CURRENT_LIST_DIR}/EllipticCurve.h
        ${CMAKE_CURRENT_LIST_DIR}/ElGamalCryptosystem.h
        )
target_include_directories(algorithm
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )



target_link_libraries(algorithm biginteger)