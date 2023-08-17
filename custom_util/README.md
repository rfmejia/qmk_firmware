# Custom docker image

This is a docker image that extends `ghcr.io/qmk/qmk_cli` to include
`wb32-dfu-updater` in order to build and flash firmware on WestberryTech
controllers (for boards like the Inland MK47).

## Building and flashing

From the `qmk_firmware` root, run

```bash
# To build the docker image
docker build custom_util -t custom_qmk_cli

# To build the keyboard/keymap firmware
custom_util/docker_build.sh inland/mk47:default

# To flash the keyboard/keymap firmware
custom_util/docker_build.sh inland/mk47:default:flash
```

## Troubleshooting

- "Cannot open DFU device xxxx:yyyy found on devnum zz (LIBUSB_ERROR_ACCESS)"

Create the file `/etc/udev/rules.d/70-ttyusb.rules` and replug the USB in bootloader mode:

```
SUBSYSTEM=="usb", ATTRS{idVendor}=="28e9", ATTRS{idProduct}=="0189", MODE="0666"
SUBSYSTEM=="usb_device", ATTRS{idVendor}=="28e9", ATTRS{idProduct}=="0189", MODE="0666"
```
