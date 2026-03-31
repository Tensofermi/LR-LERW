TARGET := a.out

SRC_DIR := 1d/src
# SRC_DIR := 2d/src
# SRC_DIR := 3d/src
# SRC_DIR := 4d/src
# SRC_DIR := 5d/src

BIN_DIR := bin
BUILD_DIR := build

rwildcard = $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

SRC := $(call rwildcard,$(SRC_DIR)/,*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEP := $(OBJ:.o=.d)

INC_DIR := $(sort $(dir $(call rwildcard,$(SRC_DIR)/,*.hpp) $(call rwildcard,$(SRC_DIR)/,*.h)))
INC_FLAG := $(addprefix -I,$(INC_DIR))

CXX := $(shell g++-15 --version >/dev/null 2>&1 && echo g++-15 || echo g++)

ARMADILLO_LIB := -larmadillo
LAPACK_LIB := -llapack
BLAS_LIB := -lblas
GMP_LIB := -lgmp
GMPXX_LIB := -lgmpxx
GSL_LIB := -lgsl
BOOST_LIB := -lboost_mpi -lboost_serialization -lboost_filesystem -lboost_system
FFT_LIB :=

ALL_LIBS := $(FFT_LIB)

CXX_WARNINGS := -Wall -pedantic-errors
CXX_DEBUG :=
CXX_OPTIM := -O3
CXX_DEP := -MMD

CXXFLAGS := -std=c++11 -DM_PI=3.14159265358979323846 $(CXX_DEBUG) $(CXX_WARNINGS) $(CXX_OPTIM) $(CXX_DEP) $(INC_FLAG)

$(BIN_DIR)/$(TARGET): $(OBJ)
	@if not exist "$(@D)" mkdir "$(@D)"
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(ALL_LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist "$(@D)" mkdir "$(@D)"
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	@if exist "$(BUILD_DIR)" rmdir /S /Q "$(BUILD_DIR)"
	@if exist "$(BIN_DIR)" rmdir /S /Q "$(BIN_DIR)"

-include $(DEP)
