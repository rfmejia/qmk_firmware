## Building and flashing

To *build the keymap*, run

```sh
util/docker_build.sh ferris/sweep:rfmejia:dfu-split-left
```

To *build and flash each side*, run

```sh
sudo util/docker_build.sh ferris/sweep:rfmejia:dfu-split-left
sudo util/docker_build.sh ferris/sweep:rfmejia:dfu-split-right
```
