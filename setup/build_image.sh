IMAGE_NAME=armnoneabi-dev
CONTAINER_PROJECT_PATH=/project-root

docker build \
    --tag $IMAGE_NAME \
    --build-arg MY_WORKDIR=$CONTAINER_PROJECT_PATH \
    --file $PWD/setup/Dockerfile .
