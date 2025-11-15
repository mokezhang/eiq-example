# CXX ?= g++
CXX = ~/arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-g++
# CXX = ~/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-linux-gnueabihf/bin/arm-none-linux-gnueabihf-g++

# CXXFLAGS += -c -Wall $(shell pkg-config --cflags opencv)
# LDFLAGS += $(shell pkg-config --libs --static opencv)
CFLAGS += --specs=nosys.specs -fshort-enums -fshort-wchar  -mcpu=cortex-m85 -mfloat-abi=hard -mthumb -MP -MMD -DC_HAS_MFPU_NEON=0 -D__FPU_PRESENT -DCMAKE_SYSTEM_PROCESSOR=arm
CXXFLAGS += --specs=nosys.specs -fshort-enums -fshort-wchar -Wno-narrowing -fno-pie -fno-pic -fpermissive -mabi=aapcs -mcpu=cortex-m85 -mfp16-format=ieee -mthumb -mfloat-abi=hard --std=c++11
LDFLAGS += -mcpu=cortex-m85 -mthumb --specs=nosys.specs -mfloat-abi=hard -Wl,--nmagic,--gc-sections \
-T mps3-sse-310.ld \
-Xlinker --entry Reset_Handler

# INCS += -I /home/moke/code/opencv/modules/core/include/ \
#  		-I /home/moke/code/opencv/build \
# 		-I /home/moke/code/opencv/modules/highgui/include \
# 		-I /home/moke/code/opencv/modules/imgcodecs/include \
# 		-I /home/moke/code/opencv/modules/videoio/include \
# 		-I /home/moke/code/opencv/modules/imgproc/include

INCS += -I /home/moke/code/opencv/modules/core/include/ \
 		-I /home/moke/code/opencv/build.static

# LIBS += -L /home/moke/code/opencv/build/lib \
#         -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs

# LIBS += -L /home/moke/code/opencv/build.staticlinux/lib \
#         -lopencv_core \
# 		-L /home/moke/code/opencv/build.staticlinux/3rdparty/lib \
# 		-lzlib
#  -lstdc++

LIBS += -L. -lopencv_world -lzlib

all: dms

dms: main.o
	$(CXX) $< -o $@ $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCS)

clean: 
	rm -f main.o dms
