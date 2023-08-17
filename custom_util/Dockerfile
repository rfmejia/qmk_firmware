FROM ghcr.io/qmk/qmk_cli

RUN apt-get update && apt-get install --no-install-recommends -y cmake libusb-1.0
RUN git clone https://github.com/WestberryTech/wb32-dfu-updater
WORKDIR wb32-dfu-updater
RUN bash ./bootstrap.sh install
