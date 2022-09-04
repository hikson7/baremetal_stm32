
HOST_PROJECT_PATH=$PWD/project
CONTAINER_PROJECT_PATH=/project-root

HOST_USB_PORT=/dev/tty.usbserial-10
CONTAINER_USB_PORT=/dev/ttyUSB0

TARGET_IMAGE_NAME=armnoneabi-dev
# EXEC_APP=v2/build.sh
EXEC_APP=bash

docker run \
    -it \
    --rm \
    --volume $HOST_PROJECT_PATH:$CONTAINER_PROJECT_PATH \
    --device=$HOST_USB_PORT \
    --privileged \
    $TARGET_IMAGE_NAME \
    $EXEC_APP

# docker run \
#     -it \
#     --rm \
#     --volume $HOST_PROJECT_PATH:$CONTAINER_PROJECT_PATH \
#     $TARGET_IMAGE_NAME \
#     $EXEC_APP